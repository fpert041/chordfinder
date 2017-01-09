//
//  CHORDFINDER
//  Max MSP External for harmonical analysis of an audio signal
//  Based on an implementation of the work by Adam Stark and using the C++ template "MaxCpp"
//
//  Copyright © 2017 Francesco Perticarari. All rights reserved.
//

#include "chordfinder~.hpp"

//-----------------------------------------------------------------------------------
// The external body
//-----------------------------------------------------------------------------------


Chordfinder::Chordfinder(t_symbol * sym, long ac, t_atom * av)
        : c(frameSize, sampleRate), finder() //pass parameters into chromagram object when creating THIS object, then create chord detector object
    {
        c.setChromaCalculationInterval(frameSize); //Set the interval at which the chromagram is calculated in audio frames
        
        RMSCutoff = 0.000001; // initial rms cutoff value

        chordName = "";
        frame.resize(frameSize); //make processing window equal to its appropriate frame_size
        for(int i=0; i<frame.size(); ++i) { frame[i]=0; } //and set its values to zero
        
        m_outlets = (void**)sysmem_newptr(sizeof(void*) * outletsNum); //create outlet "pointers-type" variables >> see example of max object template in MaxCpp
        for(unsigned int i=0; i<outletsNum; i++){
            m_outlets[outletsNum - 1 - i] = outlet_new(this, NULL); //add max outlets to THIS object
        }
        
		setupIO(2, 2); //setup MSP inlets and oultes
		post("chordfinder: object created");
        post("chordfinder: current version - 0.2");
	}
	
	Chordfinder::~Chordfinder() {
		post("chordfinder: object freed");
	}	

//-----------------------------------------------------------------------
//-----------------------------------------------------------------------


// * methods:

//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
// default signal processing method is called 'perform'

void Chordfinder::perform(double **ins, long numins, double **outs, long numouts, long sampleframes) {
///// example code to invert inputs
//        for (long channel = 0; channel < numouts; channel++) {
//            double * in = ins[channel];
//            double * out = outs[channel];
//            for (long i=0; i < sampleframes; i++) {
//                out[i] = -in[i];
//            }
//        }
    
    //variables used to calculate velume of input signal
    double rms = 0;
    double rmsTot = 0;
    int bob;
       
        double * in0 = ins[0];
        double * out0 = outs[0]; //setup double precision pointers for the input and output buffered-samples
        double * in1 = ins[1];
        double * out1 = outs[1];
    
            
        for (long i=0; i < sampleframes; ++i) {
            out0[i] = in0[i]; //passthrough signal ch 1
            out1[i] = in1[i]; //passthrough signal ch 2
                    
                if (samplesTakenIn < frameSize - 1) { //if the samples currently on the analysis buffer ar less than the FFT widnow size...
                        frame[samplesTakenIn] = (in0[i]+in1[i])/2.0; //process the average of both channels
                        samplesTakenIn++; //increment counter of samples taken in
                        
                } else {//...esle...
                    
                    //calculate RMS audio power for our samples
                    for (bob = 0; bob < frameSize; bob++) {
                        rmsTot += pow(frame[bob],2);
                    }
                    rms = rmsTot / frameSize;
                    
                    //if the signal is powerful enough:
                    if (rms > RMSCutoff){
                        c.processAudioFrame(frame); //then process the buffer to extract a chromogram
                        outlet_int(m_outlets[3], 1); //and flag this
                    } else {
                        outlet_int(m_outlets[3], 0); // flag that signal is too quiet
                    }
                    
                    if (c.isReady()) { //if the chroma-feature spectrum is ready
                            
                        // ** WARNING: HERE I USE A C-STYLE ARRAY, but the object supports vectors
                        // MAKE SURE POINTERS DON'T MESS UP THE CODE --play safe if needed
                        std::vector<double> chroma = c.getChromagram(); //define vector to store chroma-feature
                        finder.detectChord(&chroma[0]); //call the chord detection function using the current chromagram (use the array/pointer type for efficiency)
                        
                        currentchord = 10000 * finder.rootNote + finder.chordID; //create and ID for the chord (inc. root)
                        chordName = finder.chordName; //read and store chord detected name
                        
                        const char *this_chordname = chordName.c_str(); //cast name to c-string "* char"
                            
                        if (currentchord != lastchord){ //check if a new chord has been detected
                            outlet_anything(m_outlets[0], gensym(this_chordname), 0, NULL); //output chord name on outlet "0" of type "anything"
                            outlet_int(m_outlets[1], currentchord); //output chord ID on outlet "1" of type "int"
                            
                            midiList(finder.rootNote, finder.chordID); //work out a list of MIDI notes for this chord
                        } //end_if
                        
                        lastchord = currentchord;
 
                    }//end_if
                    
                    samplesTakenIn = 0; //reset counter of currently buffered samples
                    
                } //end_if
                    
        }//end_loop
        
    }//end_perform

//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
//MAX INTERFACE METHODS

void Chordfinder::bang(long inlet) {
		post("bang in inlet %i!", inlet);
        
	}
void Chordfinder::test(long inlet, t_symbol * s, long ac, t_atom * av) {
		post("%s in inlet %i (%i args)", s->s_name, inlet, ac);
	}

//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
//HELPER FUNCTIONS

//create and output a list of midi note numbers that identify the current chord
void Chordfinder::midiList(int baseNote, int chordType) {
    //variables to store root and interval notes (contained in the binary chordID)
    int root;
    int notes;
    
    t_atom outList[12]; //variable to store output list
    int noteCount = 0;
    
    root = 60 + baseNote; //set root at middle C + input chord root
    notes = chordType; //get information from a 12-bits string expressed as an INT
    for (int index = 0; index < 12; index++){ //loop through all chord interval components...
        notes *= 2; //...by doing a bit-shift
        if (notes > 4095) { //check if the interval we are checking is present in the current chord
            atom_setlong(&outList[noteCount], t_atom_long (root + index)); //if so place it on the outgoing list (after calculating where it is located in respect to chord MIDI root)
            notes = notes - 4096; //...now discard used info and move on
            noteCount++; //keep track of how many notes we have created
        }
    }
    
    outlet_anything(m_outlets[2], gensym("midi_notes"), noteCount, &outList[0]); //output list out of the generic max outlet "2"
}

	
//	// optional method: gets called when the dsp chain is modified
//	// if not given, the MspCpp will use Example::perform by default
//	void dsp(t_object * dsp64, short *count, double samplerate, long maxvectorsize, long flags) { 
//		// specify a perform method manually:
//		REGISTER_PERFORM(Example, perform);
//	}



