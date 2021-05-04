//author:
//date:
//semester final project

#ifndef WAVEHEADER_H
#define WAVEHEADER_H

typedef struct wav_header{

    char riff_header[4]; 
    int wave_size; 
    char wave_header[4]; 

    char fmt_header[4];
    int fmt_chunk_size;
    short audio_format;
    short num_channels;
    int sample_rate;
    int byte_rate;
    short sample_alignment;
    short bit_depth;

    char data_header[4];
    int data_bytes;

    char list_header[4];
    int list_chunk;
    //char info_header[4];
    // char sub_data[4];
    // int sub_data_sz;

}wav_header;

struct meta_data{
    // char list_header[4];
    // int list_chunk;
    char info_header[4];
    char sub_data[4];
    int sub_data_size; 


};

#endif