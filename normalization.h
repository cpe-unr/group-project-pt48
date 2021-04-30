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

    public:
    void NormWav(int*, int);
    void processBuffer(int* buffer, int bufferSize) override;

};


#endif