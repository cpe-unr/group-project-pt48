//author:
//date:
//semester final project

#ifndef PROCESSOR_H
#define PROCESSOR_H 

#include "iprocessor.h"

/**
 * @brief Processor class - inherits from IProcessor 
 * 
 */
class Processor : public IProcessor{

    public:
    /**
     * @brief processBuffer for one channel wav file
     * 
     * @param buffer 
     * @param bufferSize 
     */
    void processBuffer(unsigned char* buffer, int bufferSize) override;

    /**
     * @brief processBuffer for two channel wav file
     * 
     * @param char 
     * @param char 
     */
    void processBufferStereo(unsigned char*, unsigned char*, int, int) override;

};


#endif