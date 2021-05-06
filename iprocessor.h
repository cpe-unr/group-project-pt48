//author:
//date:
//semester final project

#ifndef IPROCESSOR_H
#define IPROCESSOR_H

#include <cstdint>
#include <cmath>

/**
 * @brief IProcessor interface to process buffers
 * 
 */
class IProcessor{
    
    public:
    /**
     * @brief processBuffer function for one channel wav file
     * 
     * @param buffer 
     * @param bufferSize 
     */
    virtual void processBuffer(unsigned char* buffer, int bufferSize) = 0;

    /**
     * @brief processBuffer function for two channel wav files
     * 
     * @param unsigned char * 
     * @param unsigned char *
     * @param int 
     * @param int 
     */
    virtual void processBufferStereo(unsigned char*, unsigned char*, int, int) = 0;
};

#endif