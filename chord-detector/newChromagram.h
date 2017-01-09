//This chroma-based spectrum-analysing C++ class is inspired by the Chromagram/ChordDetector by Adam Stark.
//(https://github.com/adamstark/Chord-Detector-and-Chromagram)
//Copyright (C) 2016-2017  Francesco Perticarari
//
//Original Algorithm and implementation by Adam Stark (Copyright (C) 2008-2014  Queen Mary University of London)

#ifndef __NEWCHROMAGRAM_H
#define __NEWCHROMAGRAM_H

#define _USE_MATH_DEFINES

#include <math.h>
#include <vector>

#include "kiss_fft.h"


//=======================================================================
/** A class for calculating a Chromagram from input audio
 * in a real-time context */
class newChromagram
{
    
public:
    /** Constructor
     * @param frameSize the input audio frame size 
     * @param fs the sampling frequency
     */
    newChromagram(int frameSize,int fs);

    /** Destructor */
    ~newChromagram();
    
    /** Process a single audio frame. This will determine whether enough samples
     * have been accumulated and if so, will calculate the chromagram
     * @param inputAudioFrame an array containing the input audio frame. This should be
     * the length indicated by the input audio frame size passed to the constructor
     * @see setInputAudioFrameSize
     */
    void processAudioFrame(double *inputAudioFrame);
    
    /** Process a single audio frame. This will determine whether enough samples
     * have been accumulated and if so, will calculate the chromagram
     * @param inputAudioFrame a vector containing the input audio frame. This should be
     * the length indicated by the input audio frame size passed to the constructor
     * @see setInputAudioFrameSize
     */
    void processAudioFrame(std::vector<double> inputAudioFrame);
    
    /** Sets the input audio frame size
     * @param frameSize the input audio frame size
     */
    void setInputAudioFrameSize(int frameSize);
    
    /** Set the sampling frequency of the input audio
     * @param fs the sampling frequency in Hz
     */
    void setSamplingFrequency(int fs);
    
    /** Set the interval at which the chromagram is calculated. As the algorithm requires
     * a significant amount of audio to be accumulated, it may be desirable to have the algorithm
     * not calculate the chromagram at every new audio frame. This function allows you to set the 
     * interval at which the chromagram will be calculated, specified in the number of samples at
     * the audio sampling frequency 
     * @param numSamples the number of samples that the algorithm will receive before calculating a new chromagram
     */
    void setChromaCalculationInterval(int numSamples);
    
    /** @returns the chromagram vector */
    std::vector<double> getChromagram();
    
    /** @returns true if a new chromagram vector has been calculated at the current iteration. This should
     * be called after processAudioFrame
     */
    bool isReady();
    
private:
    
    void setupFFT();
    
    void calculateChromagram();
    
    void calculateMagnitudeSpectrum();

	void downSampleFrame(std::vector<double> inputAudioFrame);

    void makeHammingWindow();

	double round(double val)
	{
		return floor(val + 0.5);
	}
    
    std::vector<double> window;
    std::vector<double> buffer;
    std::vector<double> magnitudeSpectrum;
    std::vector<double> downsampledInputAudioFrame;
    std::vector<double> chromagram;
    
    double referenceFrequency;
    double noteFrequencies[12];
    
    int bufferSize;
    int samplingFrequency;
    int inputAudioFrameSize;
    int downSampledAudioFrameSize;
    
    int numHarmonics;
	int numOctaves;
	int numBinsToSearch;
    
    int numSamplesSinceLastCalculation;
    int chromaCalculationInterval;
    bool chromaReady;

    kiss_fft_cfg cfg;
    kiss_fft_cpx *fftIn;
    kiss_fft_cpx *fftOut;
};

#endif /* defined(__CHROMAGRAM_H) */
