//author:
//date:
//semester final project

#ifndef CSVWRITER_H
#define CSVWRITER_H

#include<iostream>
#include<fstream>
#include<string>

#include "Wav.h"

/**
 * @brief CSV Writer class - writes the data to a csv file
 * 
 */
class CSVWriter{
    Wav wav;
    std::string fileName;
    public:
    /**
     * @brief writeCSV function writes the data using the input file name
     * 
     * @param fileName 
     */
    void writeCSV(const std::string &fileName);

};


#endif