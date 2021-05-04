//author:
//date:
//semester final project

#ifndef PROCESSOR_H
#define PROCESSOR_H 

#include "iprocessor.h"

class Processor : public IProcessor{

    public:
    void processBuffer(unsigned char* buffer, int bufferSize) override;
    void processBufferStereo(unsigned char*, unsigned char*, int, int) override;

};


#endif