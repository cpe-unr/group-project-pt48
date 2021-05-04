//author:
//date:
//semester final project

#include "Wav.h"

using namespace std;

MetaData::MetaData(std::ifstream &file){
    file.read(taginfo, sizeof(taginfo));
    file.read((char*)&size, sizeof(size));
    datastring.resize(size);
    file.read(&datastring[0], size);
}

std::string MetaData::getTag() const{
    std::string temps;
    for(char i : taginfo){
        temps.push_back(i);
    }
    temps.push_back('\0');
    return temps;
}
void MetaData::setTag(char taginfo) const{
    taginfo = taginfo;
}
int MetaData::getSize() const{
    return size;
}
void MetaData::setSize(int size){
    size = size;
}
std::string MetaData::getDataS() const{
    return datastring;
}
void MetaData::setDataS(std::string datastring){
    datastring = datastring;
}

void Wav::readFile(const std::string &fileName){
    std::ifstream file(fileName,std::ios::binary | std::ios::in);
    if(file.is_open()){
        file.read((char*)&waveHeader, sizeof(wav_header));
        buffer = new unsigned char[waveHeader.data_bytes];
        file.read(reinterpret_cast<char *>(buffer), waveHeader.data_bytes);

        buffer = new unsigned char[waveHeader.fmt_chunk_size];
        for(int i =0; i < waveHeader.fmt_chunk_size; i++){
            file.read((char*)&buffer[i], waveHeader.fmt_chunk_size);
        }
    }
    file.close();
}

void Wav::writeFile(const std::string &outFileName){
    std::ofstream outFile(outFileName, std::ios::out | std::ios::binary);
    outFile.write((char*)&waveHeader,sizeof(wav_header));

    outFile.write("FMT ", 4);
    int size = sizeof(waveHeader.fmt_chunk_size);
    outFile.write((char*)&size, sizeof(size));
    outFile.write((char*)&waveHeader.fmt_chunk_size, sizeof(waveHeader.fmt_chunk_size));

    outFile.write("LIST", 4);
    size = 4;
    outFile.write((char*)&waveHeader, sizeof(waveHeader.data_bytes));

    outFile.write("INFO", 4);
    MetaManager meta;
    meta.printMeta();

    outFile.write("DATA", 4);
    outFile.write((char*)&buffersize, sizeof(buffersize));
    outFile.write((char*)&buffer, sizeof(buffersize));

    outFile.close();
}

unsigned char *Wav::getBuffer(){
    return buffer;
}

int Wav::getBufferSize() const{
    return waveHeader.data_bytes;
}

int Wav::getNumChannels(){
    return waveHeader.num_channels;
}

Wav::~Wav(){
    if (buffer != NULL){
        delete[] buffer;
    }
}

MetaManager::MetaManager(const std::string &fileName){
    std::ifstream file(fileName,std::ios::binary | std::ios::in);
    file.read((char*)&metaInfo, sizeof(meta_data));
    unsigned char* buffertemp = new unsigned char[metaInfo.list_chunk];
    while(file.read((char*)&metaInfo, sizeof(meta_data) == 1)){
        metadata.push_back(buffertemp);
    }
}

void MetaManager::printMeta(){
    for(int i =0; i < metaInfo.list_chunk; i++){
        std::cout << metadata[i] << std::endl;
    }
}

int MetaManager::getSize() const{
    return metadata.size();
}
