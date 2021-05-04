//author: 
//date: 05/04/2021
//semester final project

#include "csvfilewriter.h"
#include <string> 

int main()
{
    fs.open(csvFileWriter,csvFile);
    
    try
    {
        csvFileWriter csvFile ("DataTable.csv"); 
        
        csvFile << "FILE" << "TECHNICAL INFORMATION" << "FILE METADATA"<< std::endl; 
       
        //how to pass in wav data?
        
        int i = 1;

        csvFile << i++ << "FILE NAME" << "TECHNICAL INFORMATION" << "FILE METADATA" << std::endl; 
    }

    catch (const std::exception)

    {
        std::cout << "No metadata present" << std::endl;
    }
    


    return 0;
}


