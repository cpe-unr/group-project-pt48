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

class Normalize : public IProcessor{

    int wavNum, newNum;

    public:
    Normalize();
    Normalize(int);
    void NormWav(unsigned char*, int);
    void NormWavStereo(unsigned char*, unsigned char*, int, int);
    void processBuffer(unsigned char* buffer, int bufferSize) override;
    void processBufferStereo(unsigned char* buffer1, unsigned char* buffer2, int buffers1, int buffers2) override;
};


#endif