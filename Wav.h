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

class MetaData{
    int size;
    char taginfo[4];
    std::string datastring; 
    
    public:
    MetaData() = default;
    MetaData(std::ifstream &fileName);
    std::string getTag() const;
    void setTag(char) const;
    int getSize() const;
    void setSize(int);
    std::string getDataS() const;
    void setDataS(std::string);

};

class Wav{

    private:
    int buffersize, bitdepth, numChannels;
    unsigned char* buffer = NULL; 
    std::vector<wav_header> metaDataV;
    wav_header waveHeader;

    public:
    void readFile(const std::string &fileName);
    void writeFile(const std::string &outFileName);
    ~Wav();
    unsigned char *getBuffer();
    int getBufferSize() const;
    int getNumChannels();

};

class MetaManager{

    meta_data metaInfo;
    std::vector<MetaData> metadata; 

    public:
    MetaManager() = default;
    MetaManager(std::ifstream &fileName);
    void printMeta();
    int getSize() const;


};

#endif