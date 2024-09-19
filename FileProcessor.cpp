#include "Fileprocessor.h"

#include <iostream>
#include <fstream>



FileProcessor::FileProcessor(){

};

FileProcessor::FileProcessor(std::string specFile, std::string logFile) {
    std::ifstream inputFilec(specFile, std::ios::app);
    std::ofstream outputFile(logFile, std::ios::app);
    
};

// Read the total number of levels, initial lives, and grid size from the file
void FileProcessor::readSpecFile(int& allLevels, int& lives, int& gridSize) {
    
    if (!inputFile.is_open()) {
        throw std::runtime_error("Specification file stream is not open.");
    }

    // Clear previous errors
    //inputFileStream.clear();
    
    // Read values from the file
    if (!(inputFile >> allLevels >> gridSize >> lives)) {
        throw std::runtime_error("Error reading from specification file.");
    }

if (inputFile.is_open()) {
        inputFile >> allLevels;
        inputFile >> gridSize;
        inputFile >> lives;
    }
    // Output values for debugging
    std::cout << "Levels: " << allLevels << ", Grid Size: " << gridSize << ", Lives: " << lives << std::endl;
};

// Read the percentage data for coins, mushrooms, Goombas, Koopas, and empty spaces for a specific level
void FileProcessor::readLevelInfo(int level, int &c_percent, int &m_percent, int &g_percent, int &k_percent, int &n_percent) {
    std::string line;
    int lineNumber = 0;

    // Seek to the start of the level data
    while (lineNumber < (level * 5) && std::getline(inputFile, line)) {
        lineNumber++;
    }

    if (lineNumber == (level * 5)) {
        inputFile >> c_percent >> m_percent >> g_percent >> k_percent >> n_percent;
    }
    //std::cout << "File Info: " << c_percent << ", " << m_percent << ", " << g_percent << ", " << k_percent << ", " << n_percent;
};

// Write an action log to the log file
void FileProcessor::record(std::string &action) {
    if (logFile.is_open()) {
        logFile << action << std::endl;
    }
    //std::cout << action;
};