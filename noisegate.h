//author:
//date:
//semester final project


#ifndef NOISEGATE_H
#define NOISEGATE_H

#include "Wav.h"
#include "WaveHeader.h"
#include "processor.h"

#include<iostream>

class NoiseGate : public IProcessor{

    int threshold;

    public:
    NoiseGate();
    NoiseGate(int);
    void Noisegate(unsigned char*, int);
    void NoisegateStereo(unsigned char* , unsigned char*, int, int);
    void processBuffer(unsigned char* buffer, int bufferSize) override;
    void processBufferStereo(unsigned char* buffer1, unsigned char* buffer2, int buffers1, int buffers2) override;
};


#endif