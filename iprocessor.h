//author:
//date:
//semester final project

#ifndef IPROCESSOR_H
#define IPROCESSOR_H

#include <cstdint>
#include <cmath>

class IProcessor{
    public:
    virtual void processBuffer(int* buffer, int bufferSize) = 0;
};

#endif