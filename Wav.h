//authors: 
//date: 
//semester final project

#ifndef WAVEMANAGER_H
#define WAVEMANAGER_H

#include "WaveHeader.h"
#include <string>
#include <fstream>
#include <iostream>

class Wav{

    private:
    int* buffer = NULL;
    wav_header waveHeader;

    public:
    void readFile(const std::string &fileNile);
    void writeFile(const std::string &outFileName);
    virtual ~Wav();
    int *getBuffer();
    int getBufferSize() const;

};

#endif