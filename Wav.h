//authors: 
//date: 
//semester final project

#ifndef WAVEMANAGER_H
#define WAVEMANAGER_H

#include "WaveHeader.h"

#include <string>
#include <fstream>
#include <iostream>
#include <vector>

<<<<<<< HEAD
class MetaData{
    int size;
    char taginfo[4];
    std::string datastring; 
=======
/**
 * Class to interpret Metadata
*/


class MetaData : public meta_data{
    meta_data metaData;
    //wav_header waveHeader;
    
>>>>>>> a5073a72968c2d579995224a10d095642f4afa08
    
    public:
    /**
     * @brief Construct a new Meta Data object
     * 
     */
    MetaData() = default;

    /**
     * @brief Parameterized onstructer for a new Meta Data object
     * 
     * @param fileName 
     */
    MetaData(std::ifstream &fileName);

    /**
     * @brief Get the Tag object
     * 
     * @return std::string 
     */
    std::string getTag() const;

    /**
     * @brief Set the Tag object
     * 
     */
    void setTag(char) const;

    /**
     * @brief Get the Size object
     * 
     * @return int 
     */
    int getSize() const;

    /**
     * @brief Set the Size object
     * 
     */
    void setSize(int);

    /**
     * @brief Get the Data S object
     * 
     * @return std::string 
     */
    std::string getDataS() const;

    /**
     * @brief Set the Data S object
     * 
     */
    void setDataS(std::string);

};

/**
 * @brief Wav Class
 * 
 */
class Wav{

    private:
    int buffersize, bitdepth, numChannels;
    unsigned char* buffer = NULL; 
    std::vector<wav_header> metaDataV;
    wav_header waveHeader;

    public:
    /**
     * @brief reads the information from an inputed file
     * 
     * @param fileName 
     */
    void readFile(const std::string &fileName);

    /**
     * @brief writes information a different file
     * 
     * @param outFileName 
     */
    void writeFile(const std::string &outFileName);

    /**
     * @brief Destroy the Wav object
     * 
     */
    ~Wav();

    /**
     * @brief Get the Buffer object
     * 
     * @return unsigned char* 
     */
    unsigned char *getBuffer();

    /**
     * @brief Get the Buffer Size object
     * 
     * @return int 
     */
    int getBufferSize() const;

    /**
     * @brief Get the Num Channels object
     * 
     * @return int 
     */
    int getNumChannels();

};

/**
 * @brief MetaManager class - stores and prints out metadata
 * 
 */
class MetaManager{

    meta_data metaInfo;
    std::vector<MetaData> metadata; 

    public:
    /**
     * @brief Construct a new Meta Manager object
     * 
     */
    MetaManager() = default;

    /**
     * @brief Parameterized constructer for a new Meta Manager object
     * 
     * @param fileName 
     */
    MetaManager(std::ifstream &fileName);

    /**
     * @brief prints out metadata
     * 
     */
    void printMeta();

    /**
     * @brief Get the Size object
     * 
     * @return int 
     */
    int getSize() const;


};

#endif