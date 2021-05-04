//author:
//date:
//semester final project

#include "CSVwriter.h"

using namespace std;

void CSVWriter::writeCSV(const std::string &fileName){
    std::ofstream outFile(fileName, std::ios::out | std::ios::binary);
    outFile.open(fileName);
    wav.writeFile(fileName);
    outFile.close();
    
}