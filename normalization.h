//author:
//date:
//semester final project

#ifndef NORMALIZATION_H
#define NORMALIZATION_H

#include "Wav.h"
#include "WaveHeader.h"
#include "processor.h"
#include <iostream>
#include <string>
#include <cmath>
#include <vector>


/**
 * @brief Normalize Wav class - inherits from IProcessor
 * 
 */
class Normalize : public IProcessor{

    int wavNum, newNum;

    public:
    /**
     * @brief Construct a new Normalize object
     * 
     */
    Normalize();

    /**
     * @brief Construct a new Normalize object parameterized with int
     * 
     */
    Normalize(int);

    /**
     * @brief Normalize a wav with one channel
     * 
     * @param unsigned char *, int
     */
    void NormWav(unsigned char*, int);

    /**
     * @brief Normalize a wav with two channels
     * 
     * @param unsigned char *, unsigned char* 
     * @param int, int
     */
    void NormWavStereo(unsigned char*, unsigned char*, int, int);

    /**
     * @brief process buffer with one wav channel
     * 
     * @param buffer 
     * @param bufferSize 
     */
    void processBuffer(unsigned char* buffer, int bufferSize) override;

    /**
     * @brief process buffer with two wav channels
     * 
     * @param buffer1 
     * @param buffer2 
     * @param buffers1 
     * @param buffers2 
     */
    void processBufferStereo(unsigned char* buffer1, unsigned char* buffer2, int buffers1, int buffers2) override;
};


#endif