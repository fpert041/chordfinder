//
//  CHORDFINDER
//  Max MSP External for harmonical analysis of an audio signal
//  Based on an implementation of the work by Adam Stark and using the C++ template "MaxCpp"
//
//  Copyright © 2017 Francesco Perticarari. All rights reserved.
//

#include "maxcpp.h"
#include "../chord-detector/Chromagram.h"
#include "../chord-detector/ChordDetector.h"

#include <string>
#include <sstream>
#include <iostream>
#include <vector>



// inherit from the MSP base class and build the external using C++ code
class Chordfinder : public MspCpp<Chordfinder> {
public:
    
    //define frame size and frame rate for chroma-feature analysisis of FFT data
    int frameSize = 512;
    int sampleRate = 44100;
    
    //create chromagram and chord detector objects
    Chromagram c;
    ChordDetector finder;
    std::vector<double> frame; //FFT-chromogram processing window
    int samplesTakenIn = 0;
    std::string chord_name = ""; //string variable to store a chord name
    
    int outletsNum = 4; //number of "control" outlets
    void **	m_outlets = 0; //variable for max (non-audio) outlets -- note: 0 here == nullptr

	Chordfinder(t_symbol * sym, long ac, t_atom * av)
        : c(frameSize, sampleRate), finder() //pass parameters into chromagram object when creating THIS object, then create chord detector object
    {
        c.setChromaCalculationInterval(frameSize); //Set the interval at which the chromagram is calculated in audio frames
        
        frame.resize(frameSize); //make processing window equal to its appropriate frame_size
        for(int i=0; i<frame.size(); ++i) { frame[i]=0; } //and set its values to zero
        
        m_outlets = (void**)sysmem_newptr(sizeof(void*) * outletsNum); //create outlet "pointers-type" variables >> see example of max object template in MaxCpp
        for(unsigned int i=0; i<outletsNum; i++){
            m_outlets[outletsNum - 1 - i] = outlet_new(this, NULL); //add max outlets to THIS object
        }
        
		setupIO(2, 2); //setup MSP inlets and oultes
		post("chordfinder: object created");
        post("Debugging: current version - 0.05");
	}
	
	~Chordfinder() {
		post("chordfinder: object freed");
	}	
	
	// methods:
    // default signal processing method is called 'perform'
    void perform(double **ins, long numins, double **outs, long numouts, long sampleframes) {
        // example code to invert inputs
//        for (long channel = 0; channel < numouts; channel++) {
//            double * in = ins[channel];
//            double * out = outs[channel];
//            for (long i=0; i < sampleframes; i++) {
//                out[i] = -in[i];
//            }
//        }
       
        double * in0 = ins[0];
        double * out0 = outs[0]; //setup double precision pointers for the input and output buffered-samples
        double * in1 = ins[1];
        double * out1 = outs[1];
            
        for (long i=0; i < sampleframes; i++) {
            out0[i] = in0[i]; //passthrough signal ch 1
            out1[i] = in1[i]; //passthrough signal ch 2
                    
                if (samplesTakenIn < frameSize - 1) { //if the samples currently on the analysis buffer ar less than the FFT widnow size...
                        frame[samplesTakenIn] = (in0[i]+in1[i])/2.0; //process the average of both channels
                        samplesTakenIn++; //increment counter of samples taken in
                        
                } else {//...esle...
                        c.processAudioFrame(frame); //then process the buffer to extract a chromogram
                        
                        if (c.isReady()) { //if the chroma-feature spectrum is ready
                            std::vector<double> chroma = c.getChromagram(); //define vector to store chroma-feature
                            finder.detectChord(chroma); //call the chord detection function using the current chromagram
                            
                            /** The root note of the detected chord */
                            int rootN = finder.rootNote;
                            std::ostringstream convert0;   // stream used for the conversion
                            convert0 << rootN;      // insert the textual representation of the int in the characters in the stream
                            std::string s = convert0.str(); // set a string to the contents of the stream
                            
                            /** The quality of the detected chord (Major, Minor, etc) */
                            std::ostringstream convert2;
                            convert2 << finder.quality;
                            s+= " " + convert2.str();
                            
                            /** Any other intervals that describe the chord, e.g. 7th */
                            std::ostringstream convert3;
                            convert3 << finder.intervals;
                            s+= " " + convert2.str();
                            
                            //****---debug---*****//
                            //std::ostringstream convert;
                            //convert << s;
                            //std::string debug = convert.str();
                            //post(("root quality other_invetervals : " + debug).c_str()); //debugging check - OK
                            //****---debug---*****//
                            
                            if (chord_name.compare(s) != 0 ){ //check if a new chord has been detected
                                chord_name = s;
                                const char *this_chordname = chord_name.c_str(); //prepare the chord name to be sent out
                                outlet_anything(m_outlets[0], gensym(this_chordname), 0, NULL); //output chord name
                            
                            } //end_if
                        } //end_if
                        
                        samplesTakenIn = 0; //reset counter of currently buffered samples
                } //end_if
                    
        }//end_loop
        
    }//end_perform
    
	void bang(long inlet) { 
		post("bang in inlet %i!", inlet);
        
	}
	void test(long inlet, t_symbol * s, long ac, t_atom * av) { 
		post("%s in inlet %i (%i args)", s->s_name, inlet, ac);
	}
    
    //HELPER FUNCTIONS

	
//	// optional method: gets called when the dsp chain is modified
//	// if not given, the MspCpp will use Example::perform by default
//	void dsp(t_object * dsp64, short *count, double samplerate, long maxvectorsize, long flags) { 
//		// specify a perform method manually:
//		REGISTER_PERFORM(Example, perform);
//	}
};

C74_EXPORT int main(void) {
	// create a class with the given name:
	Chordfinder::makeMaxClass("chordfinder~");
	REGISTER_METHOD(Chordfinder, bang);
	REGISTER_METHOD_GIMME(Chordfinder, test);
}
