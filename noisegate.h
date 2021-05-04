//author:
//date:
//semester final project


#ifndef NOISEGATE_H
#define NOISEGATE_H

#include "Wav.h"
#include "WaveHeader.h"
#include "processor.h"

#include<iostream>

/**
 * @brief NoiseGate class - inherits from IProcessor
 * 
 */
class NoiseGate : public IProcessor{

    int threshold;

    public:
    /**
     * @brief Construct a new Noise Gate object
     * 
     */
    NoiseGate();

    /**
     * @brief Construct a new Noise Gate object - parameterized with int
     * 
     */
    NoiseGate(int);

    /**
     * @brief Noisegate function for one channel wav file
     * 
     * @param unsigned char * 
     */
    void Noisegate(unsigned char*, int);

    /**
     * @brief NoiseGate function for stereo wav file
     * 
     * @param unsigned char *, unsigned char* 
     * @param int, int
     */
    void NoisegateStereo(unsigned char* , unsigned char*, int, int);

    /**
     * @brief processBuffer for one channel wav file
     * 
     * @param buffer 
     * @param bufferSize 
     */
    void processBuffer(unsigned char* buffer, int bufferSize) override;

    /**
     * @brief processBuffer for stereo wav file
     * 
     * @param buffer1 
     * @param buffer2 
     * @param buffers1 
     * @param buffers2 
     */
    void processBufferStereo(unsigned char* buffer1, unsigned char* buffer2, int buffers1, int buffers2) override;
};


#endif