//author:
//date:
//semester final project

#include "Wav.h"

void Wav::readFile(const std::string &fileName) {
    std::vector<unsigned char*> metadata;

    meta_data metas;

    //std::vector<MetaData> submeta;
    std::ifstream file(fileName,std::ios::binary | std::ios::in);
    if(file.is_open()){
        file.read((char*)&waveHeader, sizeof(wav_header));
        buffer = new int[waveHeader.data_bytes];
        file.read(reinterpret_cast<char *>(buffer), waveHeader.data_bytes);

        //unsigned char* buffer = new unsigned char[waveHeader.list_chunk];
        
        // buffer2 = new unsigned char[waveHeader.list_chunk];
        // std::cout << sizeof(waveHeader.list_chunk) << std::endl;
        // file.read((char *)(buffer2), sizeof(waveHeader.list_chunk));
        // metadata.push_back(buffer2);
        
        //std::cout << sizeof(buffer2) << std::endl;
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

        // file.read((char*)&metas, sizeof(metas));
        // buffer2 = new unsigned char[waveHeader.list_chunk];
        // file.read((char*)buffer2, waveHeader.list_chunk);
        // metadata.push_back(buffer2);

        
        // buffer3 = new unsigned char[metas.sub_data_size];
        // file.read((char*)buffer3, sizeof(metas.sub_data_size));
        // metadata.push_back(buffer3);
        

 
        // file.read((char*)&metas, sizeof(metas));
        // buffero = new int[metas.sub_data_size];
        // file.read((char*)buffero, metas.sub_data_size);
        
        // while(file.read((char*)buffer2, waveHeader.list_chunk)){
        //     buffer3 = new unsigned char[metas.sub_data_size];
        //     file.read((char*)buffer3, metas.sub_data_size);
        //     metadata.push_back(buffer3);
        // }

        // while(file.read((char*)&metas, sizeof(metas) == 1)){
        //     buffer2 = new unsigned char[waveHeader.list_chunk];
        //     file.read((char*)buffer2, waveHeader.list_chunk);
        //     metadata.push_back(buffer2);
        // }

        // for(int i=0; i < sizeof(buffero); i++){
        //     file.read((char*)&metas, sizeof(metas));
        //     buffer3 = new unsigned char[metas.sub_data_size];
        //     file.read((char*)buffer3, metas.sub_data_size);
        //     metadata.push_back(buffer3);
        // }

        // while(file.read((char*)&metas, sizeof(metas) == 1)){
        //     buffer2 = new unsigned char[waveHeader.list_chunk];
        //     file.read((char*)buffer2, sizeof(waveHeader.list_chunk));
        //     metadata.push_back(buffer2);
        // }


        while(file.read((char*)&metas, sizeof(metas) == 1)){
            // buffero = new int[metas.sub_data_size];
            // file.read((char*)buffero, metas.sub_data_size);
            buffer2 = new unsigned char[waveHeader.list_chunk];
            file.read((char*)buffer2, sizeof(waveHeader.list_chunk));
            metadata.push_back(buffer2);
            
        // //     buffer3 = new unsigned char[metas.sub_data_size];
        // //     file.read((char*)buffer3, sizeof(metas.sub_data_size));
        // //     metadata.push_back(buffer3);
        }

        // while(waveHeader.list_chunk != '\0'){
        //     file.read((char*)&metas, sizeof(metas));
        //     buffer2 = new unsigned char[waveHeader.list_chunk];
        //     file.read((char*)buffer2, waveHeader.list_chunk);
        //     metadata.push_back(buffer2);
        // }
        
        // for(int i =0; i < submeta.size(); i++){
        //     std::cout << submeta.at(i) << " " << std::endl;
        // }
    
    }
    file.close();
    std::cout << sizeof(metadata) << " " << sizeof(waveHeader.list_chunk) <<  " " << sizeof(buffer2) << std::endl;
    std::cout << "submeta size: " << sizeof(sub_data_size) << " " << sub_data_size << std::endl;
    //std::cout << buffer2 << std::endl;
    std::cout << "chunk size: " << waveHeader.list_chunk <<std::endl;
    std::cout << "size of metas: " << sizeof(metas) << std::endl;
    // for(int i = 0; i <4; i++){
    //     std::cout << waveHeader.list_header[i] << std::endl;
    // }
    for(int i =0; i < metadata.size(); i++){
        std::cout << metadata[i] << std::endl;
    }
    //std::cout << metadata << std::endl;
}


int *Wav::getBuffer(){
    return buffer;
}

// unsigned char *MetaData::getMeta(){
//     return buffer3;
// }

// void MetaData::readMeta(const std::string &fileName){
//     // std::vector<unsigned char*> submeta;
//     // std::ifstream file(fileName,std::ios::binary | std::ios::in);
//     // if(file.is_open()){
//     //     file.read((char*)&metaData, sizeof(meta_data));
//     //     buffero = new int[metaData.sub_data_size];
//     //     file.read(reinterpret_cast<char *>(buffero), metaData.sub_data_size);
//     //     file.read((char*)&metaData, sizeof(meta_data));
//     //     buffer3 = new unsigned char[metaData.sub_data_size];
//     //     //file.read(reinterpret_cast<char *>(buffer3), metaData.sub_data_size);

//     //     file.read((char*)buffer3, metaData.sub_data_size);
//     //     submeta.push_back(buffer3);

//     //     // buffer3 = new unsigned char[waveHeader.sub_data_size];
//     //     // //file.read((char*)&metaData, metaData.sub_data_size);
//     //     // file.read((char*)buffer3, waveHeader.sub_data_size);
//     //     // submeta.push_back(buffer3);

//     //     file.close();
//     // for(int i =0; i < submeta.size(); i++){
//     //     std::cout << submeta.at(i) << " " << std::endl;
//     // }
//     // }


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
