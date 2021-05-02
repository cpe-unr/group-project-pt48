//author:
//date:
//semester final project

#include "Wav.h"

void Wav::readFile(const std::string &fileName) {
    std::vector<unsigned char*> metadata;
    std::vector<MetaData> submeta;
    std::ifstream file(fileName,std::ios::binary | std::ios::in);
    if(file.is_open()){
        file.read((char*)&waveHeader, sizeof(wav_header));
        buffer = new int[waveHeader.data_bytes];
        file.read(reinterpret_cast<char *>(buffer), waveHeader.data_bytes);
        

        //unsigned char* buffer = new unsigned char[waveHeader.list_chunk];
        buffer2 = new unsigned char[waveHeader.list_chunk];
        file.read(reinterpret_cast<char *>(buffer2), waveHeader.list_chunk);
        metadata.push_back(buffer2);
        //buffer3 = new metaData[metaData.sub_data_size];

        //buffer3 = new unsigned char[metaData.sub_data_size];
        // file.read((char*)&metaData, sizeof(meta_data));
        // buffero = new int[metaData.sub_data_size];
        // buffer3 = new unsigned char[metaData.sub_data_size];
        // file.read((char*)buffer3, metaData.sub_data_size);
        // submeta.push_back(buffer3);
        // //file.read((char*)&metaData, metaData.sub_data_size);
        // file.read((char*)buffer3, waveHeader.sub_data_size);
        // submeta.push_back(buffer3);

        
        // for(int i =0; i < submeta.size(); i++){
        //     std::cout << submeta.at(i) << " " << std::endl;
        // }
    }
    file.close();
    std::cout << sizeof(metadata) << sizeof(waveHeader.list_chunk) << sizeof(buffer2) << std::endl;
    //std::cout << buffer2 << std::endl;
    std::cout << "chunk size: " << waveHeader.list_chunk <<std::endl;
    // for(int i = 0; i <4; i++){
    //     std::cout << waveHeader.list_header[i] << std::endl;
    // }
    for(int i =0; i < metadata.size(); i++){
        std::cout << metadata[i] << std::endl;
    }
}

int *Wav::getBuffer(){
    return buffer;
}

unsigned char *MetaData::getMeta(){
    return buffer3;
}

void MetaData::readMeta(const std::string &fileName){
    std::vector<unsigned char*> submeta;
    std::ifstream file(fileName,std::ios::binary | std::ios::in);
    if(file.is_open()){
        file.read((char*)&waveHeader, sizeof(wav_header));
        buffero = new int[waveHeader.data_bytes];
        file.read(reinterpret_cast<char *>(buffero), waveHeader.data_bytes);
        file.read((char*)&metaData, sizeof(meta_data));
        buffer3 = new unsigned char[metaData.sub_data_size];
        //file.read(reinterpret_cast<char *>(buffer3), metaData.sub_data_size);

        file.read((char*)buffer3, metaData.sub_data_size);
        submeta.push_back(buffer3);

        // buffer3 = new unsigned char[waveHeader.sub_data_size];
        // //file.read((char*)&metaData, metaData.sub_data_size);
        // file.read((char*)buffer3, waveHeader.sub_data_size);
        // submeta.push_back(buffer3);

        file.close();
    for(int i =0; i < submeta.size(); i++){
        std::cout << submeta.at(i) << " " << std::endl;
    }
    }
}


// bool MetaData::metaExist(const meta_data &fileName, char meta1, char meta2, char meta3, char meta4){
//     if(fileName.sub_data[0] == meta1 && fileName.sub_data[1] == meta2 && fileName.sub_data[2] == meta3 && fileName.sub_data[3] == meta4){
//         return true;
//     }else{
//         return false;
//     }
// }

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
