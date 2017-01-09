//
//  chordfinder~.h
//  chordfinder~
//
//  Created by Francesco Perticarari on 09/01/2017.
//
//

#ifndef chordfinder__hpp
#define chordfinder__hpp

#include "maxcpp.h"
#include "newChromagram.h" // chroma-based spectrum analysis class
#include "ChordDetector.h" //chord detection class

#include <string>
#include <sstream>
#include <iostream>
#include <vector>

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
    ChordDetector finder;
    std::vector<double> frame; //FFT-chromogram processing window
    int samplesTakenIn = 0;
    std::string chord_name; //string variable to store a chord name
    
    int outletsNum = 4; //number of "control" outlets
    void **	m_outlets = 0; //variable for max (non-audio) outlets -- note: 0 here == nullptr
    
    
    //----------------MSP buffer-level auido thread method-------------
    void perform(double **ins, long numins, double **outs, long numouts, long sampleframes);
    
    //---------------------max interface methods-----------------------
    void bang(long inlet);
    
    //-----------------------helper functions--------------------------
    void test(long inlet, t_symbol * s, long ac, t_atom * av);
    
};

#endif /* chordfinder__hpp */
