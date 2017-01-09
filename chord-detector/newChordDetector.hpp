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

//=======================================================================
/** A class for estimating chord labels from chromagram input */
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
    
    /** The root note of the detected chord */
    int rootNote;
    
    /** The quality of the detected chord (Major, Minor, etc) */
    int quality;
    
    /** Any other intervals that describe the chord, e.g. 7th */
    int intervals;
    
private:
    void makeChordProfiles();
    
    void classifyChromagram();
    
    double calculateChordScore(double *chroma,double *chordProfile,double biasToUse, double N);
    
    int minimumIndex(double *array,int length);
    
    double chromagram[12];
    double chordProfiles[108][12];
    
    double chord[108];
    
    double bias;
};

#endif /* _ChordDetector_hpp */
