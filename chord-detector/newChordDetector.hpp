//
//  _ChordDetector.hpp
//  chordfinder~
//
//  Created by Francesco Perticarari on 08/01/2017.
//
//
//  This chord-detector C++ class is inspired by the Chromagram/ChordDetector by Adam Stark.
//  (https://github.com/adamstark/Chord-Detector-and-Chromagram)
//  Copyright (C) 2016-2017  Francesco Perticarari
//
//  Original Algorithm and implementation by Adam Stark (Copyright (C) 2008-2014  Queen Mary University of London)


#ifndef newChordDetector_hpp
#define newChordDetector_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

//-----------------------------------------------------------------------------------
// A class for estimating chord labels from chromagram input
//-----------------------------------------------------------------------------------

class newChordDetector
{
public:
    
    /** An enum describing the chord qualities used in the algorithm */
    enum ChordQuality
    {
        Minor,
        Major,
        Suspended,
        Dominant,
        Dimished5th,
        Augmented5th,
    };
    
    /** Constructor */
    newChordDetector();
    
    /** Detects the chord from a chromagram. This is the vector interface
     * @param chroma a vector of length 12 containing the chromagram
     */
    void detectChord(std::vector<double> chroma);
    
    /** Detects the chord from a chromagram. This is the array interface
     * @param chroma an array of length 12 containing the chromagram
     */
    void detectChord(double *chroma);
    
    /** The string name of a chord */
    std::string chordName;
    
    /** 12-bit chord identifier*/
    int chordID;
    
    /** distance of currently guessed chord from it "ideal" chromatic profile */
    double enHarmonicContent;
    
    /** The root note of the detected chord */
    int rootNote;
    
    /** The quality of the detected chord (Major, Minor, etc) */
    int quality;
    
    /** Any other intervals that describe the chord, e.g. 7th */
    int intervals;
    
private:
    
    double noiseFloor; //noise floor level
    
    std::string noteNames[12]; //array for note names
    
    void makeChordProfiles();
    
    void classifyChromagram();
    
    double calculateChordScore(double *chroma,double *chordProfile,double biasToUse, double N);
    double calculateChordAffinity(double *chroma,double *chordProfile,double biasToUse, double N);
    
    int minimumIndex(double *array,int length);
    
    double chromagram[12]; //a c-style array to store the chroma-based spectral content to be analysed (chromagram)
    double chordProfiles[108][12]; //a c-style 2D array (matrix) to store chord profiles for each root note
    
    double chord[108]; //a c-style array to store chord scores (based on distance to stored chord profiles)
    double chordEu[108]; //a c-style array to store chord scores (based on Euclidean distance)
    
    double bias;
};

#endif /* _ChordDetector_hpp */
