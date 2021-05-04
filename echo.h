//author:
//date:
//semester final project


#ifndef ECHO_H
#define ECHO_H

#include "Wav.h"
#include "WaveHeader.h"
#include "processor.h"

#include<iostream>

/**
 * @brief Echo class - inherits from IProcessor
 * 
 */
class Echo : public IProcessor{
    
    int delay;

    public: 
    /**
     * @brief Construct a new Echo object
     * 
     */
    Echo();

    /**
     * @brief Construct a new Echo object - parameterized with int
     * 
     */
    Echo(int);

    /**
     * @brief echo function for one channel wav file
     * 
     * @param unsigned char *, int 
     */
    void echo(unsigned char*, int);

    /**
     * @brief echo function for stereo wav file
     * 
     * @param unsigned char *, unsigned char*
     * @param int, int 
     */
    void echoStereo(unsigned char*, unsigned char*, int, int);

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
     * @param char 
     * @param char 
     */
    void processBufferStereo(unsigned char*, unsigned char*, int, int) override;
};


#endif