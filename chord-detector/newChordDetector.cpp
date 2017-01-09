//
//  _ChordDetector.cpp
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

#include "newChordDetector.hpp"
#include <math.h>

//-----------------------------------------------------------------------------------
newChordDetector::newChordDetector()
{
    bias = 1.06; //define bias weight
    noiseFloor = 0.14; //based on the Euclidean distance between analysed chromagram and strored "ideal" chord profiles
            //if there is too much energy everywhere not good enough matches, don't bother guessing the chord
            //To Be Improved ;)
    
    //define chord names in a c-style array of addresses
    noteNames[0] = "C";
    noteNames[1] = "C#";
    noteNames[2] = "D";
    noteNames[3] = "D#";
    noteNames[4] = "E";
    noteNames[5] = "F";
    noteNames[6] = "F#";
    noteNames[7] = "G";
    noteNames[8] = "G#";
    noteNames[9] = "A";
    noteNames[10] = "A#";
    noteNames[11] = "B";
    
    makeChordProfiles(); //create and fill lookup matrix to store chord profiles
    
}
//-----------------------------------------------------------------------------------
// MAIN METHODS
//-----------------------------------------------------------------------------------
void newChordDetector::detectChord(std::vector<double> chroma) //in case a vector is copied in
{
    detectChord(&chroma[0]); //call array/pointer-based method
}

//-----------------------------------------------------------------------------------
void newChordDetector::detectChord(double *chroma) ////in case a c-style pointer/array is sent in
{
    for (int i = 0;i < 12;i++) //iterate through the first twelve addresses
    {
        chromagram[i] = chroma[i]; //set the chromagram values equal to them
    }
    
    classifyChromagram(); //call chromogram classification function
}


//-----------------------------------------------------------------------------------
void newChordDetector::classifyChromagram()
{
    //function-wide counters/indeces
    int i;
    int j;
    
    int fifth;
    int chordindex;
    
    // remove some of the 5th note energy from chromagram
    for (i = 0;i < 12;i++)
    {
        fifth = (i+7) % 12;
        chromagram[fifth] = chromagram[fifth] - (0.1*chromagram[i]);
        
        if (chromagram[fifth] < 0)
        {
            chromagram[fifth] = 0;
        }
        
    }
    
    //--LOOP--
    //start from 0 (incl.) and go up to 12*9=108 (excl.)...
    //...calculate how much a chroma-feature spectrum matches the chord profile of each chord type (x12 possible root notes) -- the bias is hard-coded but it could be a nice way to introduce machine learning into the algorithm
    // here major/minor chords are more "likely" to be heard
    // --the last param is the number of notes expected in the chord
    
    // major chords
    for (j=0;j < 12;j++)
    {
        chord[j] = calculateChordScore(chromagram,chordProfiles[j],bias,3);
        chordEu[j] = calculateChordAffinity(chromagram,chordProfiles[j],bias,3);
    }
    
    // minor chords
    for (j=12;j < 24;j++)
    {
        chord[j] = calculateChordScore(chromagram,chordProfiles[j],bias,3);
        chordEu[j] = calculateChordAffinity(chromagram,chordProfiles[j],bias,3);
    }
    
    // diminished 5th chords
    for (j=24;j < 36;j++)
    {
        chord[j] = calculateChordScore(chromagram,chordProfiles[j],bias,3);
        chordEu[j] = calculateChordAffinity(chromagram,chordProfiles[j],bias,3);
    }
    
    // augmented 5th chords
    for (j=36;j < 48;j++)
    {
        chord[j] = calculateChordScore(chromagram,chordProfiles[j],bias,3);
        chordEu[j] = calculateChordAffinity(chromagram,chordProfiles[j],bias,3);
    }
    
    // sus2 chords
    for (j=48;j < 60;j++)
    {
        chord[j] = calculateChordScore(chromagram,chordProfiles[j],1,3);
        chordEu[j] = calculateChordAffinity(chromagram,chordProfiles[j],1,3);
    }
    
    // sus4 chords
    for (j=60;j < 72;j++)
    {
        chord[j] = calculateChordScore(chromagram,chordProfiles[j],1,3);
        chordEu[j] = calculateChordAffinity(chromagram,chordProfiles[j],1,3);
    }
    
    // major 7th chords
    for (j=72;j < 84;j++)
    {
        chord[j] = calculateChordScore(chromagram,chordProfiles[j],1,4);
        chordEu[j] = calculateChordAffinity(chromagram,chordProfiles[j],1,4);
    }
    
    // minor 7th chords
    for (j=84;j < 96;j++)
    {
        chord[j] = calculateChordScore(chromagram,chordProfiles[j],bias,4);
        chordEu[j] = calculateChordAffinity(chromagram,chordProfiles[j],bias,4);
    }
    
    // dominant 7th chords
    for (j=96;j < 108;j++)
    {
        chord[j] = calculateChordScore(chromagram,chordProfiles[j],bias,4);
        chordEu[j] = calculateChordAffinity(chromagram,chordProfiles[j],bias,4);
    }
    //--ENDLOOP--
    
    // calculate an index based on the distance between the current chromagram being analysed and the stored chord profiles
    // the index (chord profile with the minimum distance) will be our chord guess
    chordindex = minimumIndex(chord,108);
    
    enHarmonicContent = chordEu[chordindex]; //set a variable = "how close we are to an ideal chord"
                                                  //to test against noise threshold
    
    if(enHarmonicContent < noiseFloor) { //only classify chords which are close enough to chord profiles
        
        
        //find out what type of chord we have by looking at the section it falls in:
        
        // major
        if (chordindex < 12)
        {
            rootNote = chordindex-0; // the root note of our guessed chord will be the index itself
            // (if necessary translated so that it is between 0 and 11)
            quality = Major; //assign an "enum" value to the quality based on where the index is
            intervals = 0; //note if there are any other intervals, depending on what chord it is
            //(e.g. "2" for a sus2 chord, "7" for a Maj7 or a Dom7 chord, etc.)
            
            
            chordID = 2192; //12-bit unique identifier e.g: Major = 1 0 0 0 1 0 0 1 0 0 0 0 = 2192
            //other e.g: Minor = 1 0 0 1 0 0 0 1 0 0 0 0 = 2320 (see below)
            chordName = noteNames[rootNote] + ""; //chord name storage variable
        }
        
        // minor
        if ((chordindex >= 12) && (chordindex < 24))
        {
            rootNote = chordindex-12;
            quality = Minor;
            intervals = 0;
            
            chordID = 2320;
            chordName = noteNames[rootNote] + "min";
        }
        
        // diminished 5th
        if ((chordindex >= 24) && (chordindex < 36))
        {
            rootNote = chordindex-24;
            quality = Dimished5th;
            intervals = 0;
            
            chordID = 2336;
            chordName = noteNames[rootNote] + "Dim5";
        }
        
        // augmented 5th
        if ((chordindex >= 36) && (chordindex < 48))
        {
            rootNote = chordindex-36;
            quality = Augmented5th;
            intervals = 0;
            
            chordID = 2184;
            chordName = noteNames[rootNote] + "Aug5";
        }
        
        // sus2
        if ((chordindex >= 48) && (chordindex < 60))
        {
            rootNote = chordindex-48;
            quality = Suspended;
            intervals = 2;
            
            chordID = 2576;
            chordName = noteNames[rootNote] + "sus2";
        }
        
        // sus4
        if ((chordindex >= 60) && (chordindex < 72))
        {
            rootNote = chordindex-60;
            quality = Suspended;
            intervals = 4;
            
            chordID = 2128;
            chordName = noteNames[rootNote] + "sus4";
        }
        
        // major 7th
        if ((chordindex >= 72) && (chordindex < 84))
        {
            rootNote = chordindex-72;
            quality = Major;
            intervals = 7;
            
            chordID = 2193;
            chordName = noteNames[rootNote] + "Maj7";
        }
        
        // minor 7th
        if ((chordindex >= 84) && (chordindex < 96))
        {
            rootNote = chordindex-84;
            quality = Minor;
            intervals = 7;
            
            chordID = 2322;
            chordName = noteNames[rootNote] + "min7";
        }
        
        // dominant 7th
        if ((chordindex >= 96) && (chordindex < 108))
        {
            rootNote = chordindex-96;
            quality = Dominant;
            intervals = 7;
            
            chordID = 2194;
            chordName = noteNames[rootNote] + "7th";
        }
    }
}

//-----------------------------------------------------------------------------------
// HELPER FUNCTIONS
//-----------------------------------------------------------------------------------

// This function takes in a chromagram and a chord profile (WARNING - they have to be both a c-style array of 12 bins)
// It then compares them and outputs a score based on how far off from each other they are
double newChordDetector::calculateChordScore(double *chroma,double *chordProfile,double biasToUse, double featIntervalsNum)
{
    double sum = 0; // running sum variable
    double delta; // hypotetical distance between the current chromogram and the stored chord profiles
    
    for (int i=0;i < 12;i++) //iterate through the 12 versions of each chord type (12 = root notes)
    {
        // square the content of each chromatic "energy" bin from the input chromogram
        // zero this result if it is a chroma-feature of the chord profile against which it is tested
        // add it to the running sum
        sum += ((1-chordProfile[i])*(chroma[i]*chroma[i]));
    }
    
    delta = sqrt(sum); // calculate the distance between chromogram and chord profile based on the Alex Stark method:
                       // this will tend to be "0" if there is little or no energy in the chromatic "bins" of the chromogram which are NOT charachteristic of the chord profile,
                       // and maxim if there is a lot of energy in these bins
    
    delta *= 1/((12 - featIntervalsNum)*biasToUse); // scale the distance which is made by "12 - chroma_ft_intervals" components
                                // (also add custom bias whereby the higher the bias the more it REDUCES the distance)
    return delta;
}

//-----------------------------------------------------------------------------------

// This function takes in a chromagram and a chord profile (WARNING - they have to be both a c-style array of 12 bins)
// It then compares them and outputs a score based on how similar they are
double newChordDetector::calculateChordAffinity(double *chroma,double *chordProfile,double biasToUse, double featIntervalsNum)
{
    double sum = 0; // running sum variable
    double delta; // Euclidean distance between the current chromogram and the stored chord profiles
            // WARNING: the chromagram may not normalised
    
    double maxChroma = 0;

    for (int i=0;i < 12;i++) //iterate through the 12 versions of each chord type (12 = root notes)
    {
        if (chroma[i] > maxChroma) { maxChroma = chroma[i]; } //find out what's the highest energy peak in the chromagram
    }
    
    for (int i=0;i < 12;i++) //iterate through the 12 versions of each chord type (12 = root notes)
    {
        // square the difference between each chromatic "energy" bin from the input chromogram (normalised)
        // and each chromatic "feature" bin from the chord profiles
        // add it to the running sum
        sum += pow((chordProfile[i] - chroma[i]/maxChroma),2);
    }
    
    delta = sqrt(sum); // calculate EUCLIDEAN distance between chromogram and chord profile:
    // this will tend to be MINIM if there is little match btween the chromatic "bins" of the chromogram which are charachteristic of the chord profile,
    // and MAXIM if their chroma-feature spectra match
    
    delta *= 1/((12)*biasToUse); //scale the distance because the sum is the result of 12 components
                                        //(also add custom bias whereby the higher the bias the more it REDUCES the distance)
    return delta;
}


//-----------------------------------------------------------------------------------

//work out the index of the chord contained in the chromagram (which can then be looked up in the chord-profiles matrix)
int newChordDetector::minimumIndex(double *array,int arrayLength) // params: c-style array of chord scores & its length
{
    double minValue = 100000; //arbitrary big number (so that it is always larger than any chord score/distance)
    int minIndex = 0; //varible to store output
    
    for (int i = 0;i < arrayLength; i++) //iterate through the array that holds the values of "distances" (scores)
                                     //between the currently analysed chroma-feature spectrum
                                     //and the chord profiles stored
    {
        if (array[i] < minValue) //if any of the distances is less than minValue...
        {
            minValue = array[i]; //...set minValue = that_distance
            minIndex = i; //...set our output variable equal to the current index of the array
        }
    }
    
    return minIndex; //at the end return the index of the stored chord profile which most matches the current chromagram
}


//-----------------------------------------------------------------------------------

// This function defines chord profiles to compare against the chromogram (= chroma-based spectrum) being analysed
void newChordDetector::makeChordProfiles()
{
    //function-wide counters
    int i;
    int intervalInSemitones;
    int index = 0; //chord index
    
    //intervals
    int root;
    int third;
    int fifth;
    int seventh;
    //int ninth; // *** for possible future upgrades
    //int eleventh;  // *** for possible future upgrades
    
    double v1 = 1;
    double v2 = 1;
    double v3 = 1;
    
    // set profiles matrix to all zeros
    for (index = 0;index < 108;index++)
    {
        for (intervalInSemitones = 0; intervalInSemitones < 12; intervalInSemitones++)
        {
            chordProfiles[index][intervalInSemitones] = 0;
        }
    }
    
    // reset index to zero to begin creating profiles
    index = 0;
    
    /** Create unique chord profiles by "switching on" ( = setting to 1) the intervals featured in each chord
     * In the end, chordProfiles will be a matrix whose content looks like this:
     * [0] -> [1][0][0][0][1][0][1][0][0][0][0][0] (major chord)
     * [1] -> [1][0][0][1][0][0][1][0][0][0][0][0] (minor chord)
     * [...]
     *
     * PSEUDOCODE:
     * for each location in the chord-profiles matrix, do:
     *  loop 12 times to create a profile for each root note, and each time do:
     *      calculate root_index = appropriate_number_between_0_and_11
     *      calculate third_index = (root_index + 4) modulo 12 [ -> fold back into the 12-note scale]
     *      calculate fifth_index = (root_index + 7) modulo 12 [ -> fold back into the 12-note scale]
     *      GO_TO: ROOT-LOCATION of the current CHORD-PROFILE and SET it to 1 [ -> flag that every chord has a root]
     *      GO_TO: ANY-RELEVANT-INTERVAL-LOCATION of the current CHORD-PROFILE (i.e. minor 3rd, major 3rd, ect...)
     *          and SET it to 1 [ -> This is what identifies each chord!!! ]
     *      increment chord_index counter to go through each chord-profile in the matrix
     *  endloop
     * endloop
     */
    //--LOOP--
    // major chords
    for (i = 0;i < 12;i++)
    {
        root = i % 12;
        third = (i+4) % 12;
        fifth = (i+7) % 12;
        
        chordProfiles[index][root] = v1;
        chordProfiles[index][third] = v2;
        chordProfiles[index][fifth] = v3;
        
        index++;
    }
    
    // minor chords
    for (i = 0;i < 12;i++)
    {
        root = i % 12;
        third = (i+3) % 12;
        fifth = (i+7) % 12;
        
        chordProfiles[index][root] = v1;
        chordProfiles[index][third] = v2;
        chordProfiles[index][fifth] = v3;
        
        index++;
    }
    
    // diminished chords
    for (i = 0;i < 12;i++)
    {
        root = i % 12;
        third = (i+3) % 12;
        fifth = (i+6) % 12;
        
        chordProfiles[index][root] = v1;
        chordProfiles[index][third] = v2;
        chordProfiles[index][fifth] = v3;
        
        index++;
    }
    
    // augmented chords
    for (i = 0;i < 12;i++)
    {
        root = i % 12;
        third = (i+4) % 12;
        fifth = (i+8) % 12;
        
        chordProfiles[index][root] = v1;
        chordProfiles[index][third] = v2;
        chordProfiles[index][fifth] = v3;
        
        index++;
    }
    
    // sus2 chords
    for (i = 0;i < 12;i++)
    {
        root = i % 12;
        third = (i+2) % 12;
        fifth = (i+7) % 12;
        
        chordProfiles[index][root] = v1;
        chordProfiles[index][third] = v2;
        chordProfiles[index][fifth] = v3;
        
        index++;
    }
    
    // sus4 chords
    for (i = 0;i < 12;i++)
    {
        root = i % 12;
        third = (i+5) % 12;
        fifth = (i+7) % 12;
        
        chordProfiles[index][root] = v1;
        chordProfiles[index][third] = v2;
        chordProfiles[index][fifth] = v3;
        
        index++;
    }		
    
    // major 7th chords
    for (i = 0;i < 12;i++)
    {
        root = i % 12;
        third = (i+4) % 12;
        fifth = (i+7) % 12;
        seventh = (i+11) % 12;
        
        chordProfiles[index][root] = v1;
        chordProfiles[index][third] = v2;
        chordProfiles[index][fifth] = v3;
        chordProfiles[index][seventh] = v3;
        
        index++;
    }	
    
    // minor 7th chords
    for (i = 0;i < 12;i++)
    {
        root = i % 12;
        third = (i+3) % 12;
        fifth = (i+7) % 12;
        seventh = (i+10) % 12;
        
        chordProfiles[index][root] = v1;
        chordProfiles[index][third] = v2;
        chordProfiles[index][fifth] = v3;
        chordProfiles[index][seventh] = v3;
        
        index++;
    }
    
    // dominant 7th chords
    for (i = 0;i < 12;i++)
    {
        root = i % 12;
        third = (i+4) % 12;
        fifth = (i+7) % 12;
        seventh = (i+10) % 12;
        
        chordProfiles[index][root] = v1;
        chordProfiles[index][third] = v2;
        chordProfiles[index][fifth] = v3;
        chordProfiles[index][seventh] = v3;
        
        index++;
    }
    //--ENDLOOP--
}

/** POSSIBLE UPGRADES:
 
 
//TO CHORD PROFILES CLASSIFICATION:
 
// add9 chords
for (i = 0; i < 12; i++)
{
 root = i % 12;
 third = (i + 4) % 12;
 fifth = (i + 7) % 12;
 ninth = (i + 2) % 12;
 
 chordProfiles[index][root] = v1;
 chordProfiles[index][third] = v2;
 chordProfiles[index][fifth] = v3;
 chordProfiles[index][ninth] = v3;
 
 index++;
}
 
// 11th chords
for (i = 0; i < 12; i++)
{
 root = i % 12;
 ninth = (i + 2) % 12;
 third = (i + 4) % 12;
 fifth = (i + 5) % 12;
 seventh = (i + 7) % 12;
 eleventh = (i + 10) % 12;
 
 chordProfiles[index][root] = v1;
 chordProfiles[index][third] = v2;
 chordProfiles[index][fifth] = v3;
 chordProfiles[index][seventh] = v3;
 chordProfiles[index][ninth] = v3;
 chordProfiles[index][eleventh] = v3;
 
 
 index++;
}
 
// 9th chords
for (i = 0; i < 12; i++)
{
 root = i % 12;
 third = (i + 4) % 12;
 fifth = (i + 7) % 12;
 seventh = (i + 10) % 12;
 ninth = (i + 2) % 12;
 
 chordProfiles[index][root] = v1;
 chordProfiles[index][third] = v2;
 chordProfiles[index][fifth] = v3;
 chordProfiles[index][seventh] = v3;
 chordProfiles[index][ninth] = v3;
 
 
 index++;
}
 
// 6th chords
for (i = 0; i < 12; i++)
{
 root = i % 12;
 third = (i + 4) % 12;
 fifth = (i + 7) % 12;
 seventh = (i + 9) % 12;
 
 chordProfiles[index][root] = v1;
 chordProfiles[index][third] = v2;
 chordProfiles[index][fifth] = v3;
 chordProfiles[index][seventh] = v3;
 
 index++;
}
 
*/
