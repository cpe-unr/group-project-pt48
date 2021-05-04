//author:
//date:
//semester final project

#include "echo.h"

Echo::Echo(){
    delay = 0;
}

Echo::Echo(int delay) : delay(delay){}

void Echo::processBuffer(unsigned char* buffer, int bufferSize){
    echo(buffer, bufferSize);
}

void Echo::processBufferStereo(unsigned char* buffer1, unsigned char* buffer2, int buffers1, int buffers2){
    echoStereo(buffer1, buffer2, buffers1, buffers2);
}

void Echo::echo(unsigned char* buffer, int bufferSize){
    for(int i =0; i < bufferSize; i++){
        buffer[i] = (buffer[i]/(uint8_t)2) - (buffer[i-delay]/(uint8_t)3); 
    }
}

void Echo::echoStereo(unsigned char* buffer1, unsigned char* buffer2, int buffers1, int buffers2){
    for(int i =0; i < buffers1; i++){
        buffer1[i] = (buffer1[i]/(uint8_t)2) - (buffer1[i-delay]/(uint8_t)3); 
    }
    for(int i =0; i < buffers2; i++){
        buffer2[i] = (buffer2[i]/(uint8_t)2) - (buffer2[i-delay]/(uint8_t)3); 
    }
}