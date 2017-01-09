//
//  CHORDFINDER
//  Max MSP External for harmonical analysis of an audio signal
//  Based on an implementation of the work by Adam Stark and using the C++ template "MaxCpp"
//
//  Copyright © 2017 Francesco Perticarari. All rights reserved.
//

#ifndef chordfinder__hpp
#define chordfinder__hpp

#include "maxcpp.h"
#include "newChromagram.hpp" // chroma-based spectrum analysis class
#include "newChordDetector.hpp" //chord detection class

#include <string>
#include <sstream>
#include <iostream>
#include <vector>

//-----------------------------------------------------------------------------------
// The external wrapper class
//-----------------------------------------------------------------------------------

// inherit from the MSP base class and build the external using C++ code
class Chordfinder : public MspCpp<Chordfinder> {
public:
    
    Chordfinder(t_symbol * sym, long ac, t_atom * av); //constructor
    ~Chordfinder(); //destructor
    
    //define frame size and frame rate for chroma-feature analysisis of FFT data
    int frameSize = 512;
    int sampleRate = 44100;
    
    //create chromagram and chord detector objects
    newChromagram c;
    newChordDetector finder;
    std::vector<double> frame; //FFT-chromogram processing window
    int samplesTakenIn = 0; //currently buffered sumples
    
    int currentchord = 0; // store chordID
    int lastchord = 0;
    std::string chordName; // string variable to store a chord name
    double RMSCutoff; // signal control: don't analyse quiet noise
    
    int outletsNum = 4; //number of "control" outlets
    void **	m_outlets = 0; //variable for max (non-audio) outlets -- note: 0 here == nullptr
    
    
    //----------------MSP buffer-level auido thread method-------------
    void perform(double **ins, long numins, double **outs, long numouts, long sampleframes);
    
    //---------------------max interface methods-----------------------
    void bang(long inlet); // called when banged
    
    void setRMS(long inlet, t_symbol * s, long ac, t_atom * av); //use setRMS and an argument to set the RMS cutoff
    
    void rate(long inlet, t_symbol * s, long ac, t_atom * av); //set framerate (how many chromagrams to wait before analysing) -- it is by default 1 ( = 512 samples), and increasing it means less CPU and a more sparse analysis
    
    void assist(void *b, long m, long a, char *s); //gets called when user hovers over inlets/outlets
    
    //void test(long inlet, t_symbol * s, long ac, t_atom * av);
    //-----------------------helper functions--------------------------
    
private:
    
    void midiList(int baseNote, int chordType);
    
};

#endif /* chordfinder__hpp */
