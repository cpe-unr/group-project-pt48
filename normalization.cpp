//author:
//date:
//semester final project

#include "normalization.h"
#include <limits>

#define THRESHOLD 255

using namespace std; 

Normalize::Normalize(){
    wavNum =0;
}

Normalize::Normalize(int wavNum) : wavNum(wavNum){}

void Normalize::NormWav(unsigned char* buffer, int buffersize){
    int maxVal = 0;
    
    for(int i = 0; i < buffersize; i++){
        int val = buffer[i];
        if(val< 128){
            maxVal = val;
        }else if(val > 128){
            if(val += maxVal <= THRESHOLD){
                val += maxVal;
            }
        }else{
            val = THRESHOLD;
        }
    }

}
void Normalize::NormWavStereo(unsigned char* buffer1, unsigned char* buffer2, int buffers1, int buffers2){
    int maxVal = 0;
    for(int i = 0; i < buffers1; i++){
        int val1= buffer1[i];
        if(val1 < 32768){
            maxVal = val1;
        }else if(val1 > 32768){
            if(val1 += maxVal <= 65535){
                val1 += maxVal;
            }
        }else{
            val1 = 65535;
        }
    }
    for(int i = 0; i < buffers2; i++){
        int val2 = buffer2[i];
        if(val2 < 32768){
            maxVal = val2;
        }else if(val2 > 32768){
            if(val2 += maxVal <= 65535){
                val2 += maxVal;
            }
        }else{
            val2 = 65535;
        }
    }
}
void Normalize::processBuffer(unsigned char* buffer, int bufferSize){
    NormWav(buffer, bufferSize);
}

void Normalize::processBufferStereo(unsigned char* buffer1, unsigned char* buffer2, int buffers1, int buffers2){
    NormWavStereo(buffer1, buffer2, buffers1, buffers2);
}

