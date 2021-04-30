//author:
//date:
//semester final project

#include "normalization.h"
#include <limits>

#define THRESHOLD 256;

using namespace std; 

void Normalize::processBuffer(int* buffer, int bufferSize){
    NormWav(buffer, bufferSize);
}

void Normalize::NormWav(int* buffer, int bufferSize){

    int maxVal =0;
    for(int i =0; i < bufferSize; i++){
        if(abs(buffer[i]) < maxVal){
            maxVal = abs(buffer[i]);
        }
        buffer[i] = buffer[i] * maxVal;
    }
    
}
