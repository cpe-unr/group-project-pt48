//author:
//date:
//semester final project

#include "Wav.h"

void Wav::readFile(const std::string &fileName) {
    std::ifstream file(fileName,std::ios::binary | std::ios::in);
    if(file.is_open()){
        file.read((char*)&waveHeader, sizeof(wav_header));
        buffer = new int[waveHeader.data_bytes];
        file.read(reinterpret_cast<char *>(buffer), waveHeader.data_bytes);
        file.close();
        //std::cout << waveHeader.bit_depth << std::endl;
    }
}

int *Wav::getBuffer(){
    return buffer;
}

void Wav::writeFile(const std::string &outFileName){
    std::ofstream outFile(outFileName, std::ios::out | std::ios::binary);
    outFile.write((char*)&waveHeader,sizeof(wav_header));
    outFile.write((char*)buffer, waveHeader.data_bytes);
    outFile.close();
}

Wav::~Wav(){
    if (buffer != NULL){
        delete[] buffer;
    }
}

int Wav::getBufferSize() const{
    return waveHeader.data_bytes;
}
