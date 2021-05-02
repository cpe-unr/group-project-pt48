//authors: 
//date: 
//semester final project

#ifndef WAVEMANAGER_H
#define WAVEMANAGER_H

#include "WaveHeader.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

class MetaData : public meta_data{
    meta_data metaData;
    wav_header waveHeader;
    
    unsigned char* buffer3;

    public:
    int* buffero;
    //meta_data metadata;
    std::string datastring; 
    void readMeta(const std::string &fileName );
    bool metaExist(const meta_data &fileName, char, char, char, char);

};

class Wav : public MetaData{

    private:
    int* buffer = NULL;
    unsigned char* buffer2; 
    wav_header waveHeader;
    meta_data metaData;

    public:
    unsigned char* buffer3;
    void readFile(const std::string &fileName);
    void writeFile(const std::string &outFileName);
    virtual ~Wav();
    int *getBuffer();
    int getBufferSize() const;

};




#endif