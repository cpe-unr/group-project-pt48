//author:
//date:
//semester final project

#ifndef CSVWRITER_H
#define CSVWRITER_H

#include<iostream>
#include<fstream>
#include<string>

#include "Wav.h"

class CSVWriter{
    Wav wav;
    std::string fileName;
    public:
    void writeCSV(const std::string &fileName);

};


#endif