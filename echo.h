//author:
//date:
//semester final project


#ifndef ECHO_H
#define ECHO_H

#include "Wav.h"
#include "WaveHeader.h"
#include "processor.h"

#include<iostream>

class Echo : public IProcessor{
    
    int delay;

    public: 
        Echo();
        Echo(int);
        void echo(unsigned char*, int);
        void echoStereo(unsigned char*, unsigned char*, int, int);
        void processBuffer(unsigned char* buffer, int bufferSize) override;
        void processBufferStereo(unsigned char*, unsigned char*, int, int) override;
};


#endif