//author:
//date:
//semester final project

#ifndef PROCESSOR_H
#define PROCESSOR_H 

#include "iprocessor.h"

class Processor : public IProcessor{

    public:
    void processBuffer(int* buffer, int bufferSize) override;

};


#endif