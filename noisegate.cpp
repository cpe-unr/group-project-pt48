//author:
//date:
//semester final project

#include "noisegate.h"


using namespace std;

NoiseGate::NoiseGate(){
    threshold = 100;
}

NoiseGate::NoiseGate(int threshold) : threshold(threshold){}

void NoiseGate::processBuffer(unsigned char* buffer, int bufferSize){
    Noisegate(buffer, bufferSize);
}

void NoiseGate::NoisegateStereo(unsigned char* buffer1 , unsigned char* buffer2, int buffers1, int buffers2){
    NoisegateStereo(buffer1, buffer2, buffers1, buffers2);
}

void NoiseGate::Noisegate(unsigned char* buffer, int bufferSize){
    for(int i = 0; i < bufferSize; i++){
        if(buffer[i] > (uint8_t)128 - threshold && buffer[i] < (uint8_t)128 + threshold){
            buffer[i] = (uint8_t)128;
        }
    }
}

void NoiseGate::processBufferStereo(unsigned char* buffer1, unsigned char* buffer2, int buffers1, int buffers2){
    for(int i = 0; i < buffers1; i++){
        if(buffer1[i] > (uint8_t)128 - threshold && buffer1[i] < (uint8_t)128 + threshold){
            buffer1[i] = (uint8_t)128;
        }
    }
    for(int i = 0; i < buffers2; i++){
        if(buffer2[i] > (uint8_t)128 - threshold && buffer2[i] < (uint8_t)128 + threshold){
            buffer2[i] = (uint8_t)128;
        }
    }
}
