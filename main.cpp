/** @file */
#include <iostream>

#include "Wav.h"
#include "processor.h"
#include "normalization.h"
#include "echo.h"
#include "noisegate.h"
#include "CSVwriter.h"

#include<iostream>
#include<string>


/**
 * \brief   The function bar.
 *
 * \details This function does something which is doing nothing. So this text
 *          is totally senseless and you really do not need to read this,
 *          because this text is basically saying nothing.
 *
 * \note    This text shall only show you, how such a \"note\" section
 *          is looking. There is nothing which really needs your notice,
 *          so you do not really need to read this section.
 *
 * \param[in]     a    Description of parameter a.
 * \param[out]    b    Description of the parameter b.
 * \param[in,out] c    Description of the parameter c.
 *
 * \return        The error return code of the function.
 *
 * \retval        ERR_SUCCESS    The function is successfully executed
 * \retval        ERR_FAILURE    An error occurred
 */
void fn(){

}

using namespace std;
const int NUM_ARGS = 2;

/**
 * @brief Main Function 
 * 
 * @param argc - executable input parameter
 * @param argv - filename input parameter
 * @return int - returns 0
 */
int main(int argc, char const* argv[]) {
    Wav wav;
    CSVWriter csv;
    //Echo echo;
    if(argc < NUM_ARGS){
        cout << "Correct usage:" << endl;
        cout << argv[0] << " filename" << endl;
        return 0;
    }
    string file = argv[1];
    ifstream inputFile; 
    inputFile.open(file); 
    if(!inputFile.good()){
        cout << "The file " << file << " could not be opened." << endl;
    } 

    int num;
    cout << "What would you like to do? please enter a number" << endl;
    cout << "1 echo" << endl;
    cout << "2 noisegate" << endl;
    cout << "3 normalize" << endl;
    cin >> num; 

    if(num == 1){
        wav.readFile(file);
        if(wav.getNumChannels() == 1){
            IProcessor *processor = new Echo(5000);
            processor->processBuffer(wav.getBuffer(), wav.getBufferSize());
            cout << "Please name your new file as: filename.csv" << endl;
            string filename; 
            cin >> filename; 
            if(filename != file){
                csv.writeCSV(filename);
            }else{
                cout << "That file name is already taken. Please choose a new one" << endl;
            }
        }else if(wav.getNumChannels()==2){
            IProcessor *processor = new Echo(5000);
            processor->processBufferStereo(wav.getBuffer(), wav.getBuffer(), wav.getNumChannels(), wav.getNumChannels());
            cout << "Please name your new file as: filename.csv" << endl;
            string filename; 
            cin >> filename;
            if(filename != file){
                csv.writeCSV(filename);
            }else{
                cout << "That file name is already taken. Please choose a new one" << endl;
            }
        }else{
            return 0;
        }
    } else if(num == 2){
        wav.readFile(file);
        if(wav.getNumChannels() == 1){
            IProcessor *processor = new Normalize(500);
            processor->processBuffer(wav.getBuffer(), wav.getBufferSize());
            cout << "Please name your new file as: filename.csv" << endl;
            string filename; 
            cin >> filename;
            if(filename != file){
                csv.writeCSV(filename);
            }else{
                cout << "That file name is already taken. Please choose a new one" << endl;
            }
        }else if(wav.getNumChannels() == 2){
            IProcessor *processor = new Normalize(500);
            processor->processBufferStereo(wav.getBuffer(), wav.getBuffer(), wav.getBufferSize(), wav.getBufferSize());
            cout << "Please name your new file as: filename.csv" << endl;
            string filename;
            cin >> filename;
            if(filename != file){
                csv.writeCSV(filename);
            }else{
                cout << "That file name is already taken. Please choose a new one" << endl;
            }
        }else{
            return 0;
        }
    }else if(num == 3){
        wav.readFile(file);
        if(wav.getNumChannels() == 1){
            IProcessor *processor = new NoiseGate(10);
            processor->processBuffer(wav.getBuffer(), wav.getBufferSize());
            cout << "Please name your new file as: filename.csv" << endl;
            string filename;
            cin >> filename;
            if(filename != file){
                csv.writeCSV(filename);
            }else{
                cout << "that file name is already taken. Please choose a new one" << endl;
            }
        }else if(wav.getNumChannels() == 2){
            IProcessor *processor = new NoiseGate(10);
            processor->processBufferStereo(wav.getBuffer(), wav.getBuffer(), wav.getBufferSize(), wav.getBufferSize());
            cout << "Please name your new file as: filename.csv" << endl;
            string filename;
            cin >> filename;
            if(filename != file){
                csv.writeCSV(filename);
            }else{
                cout << "That file name is already taken. Please choose a new one" << endl;
            }
        }else{
            return 0;
        }
    }else{
        cout << "Please enter a valid number" << endl;
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
