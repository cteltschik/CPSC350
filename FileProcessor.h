#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <string>
#include <fstream>

class FileProcessor {
public:
    FileProcessor();
    FileProcessor(std::string inputFile, std::string outputFile);
    void readSpecFile(int& allLevels, int& initialLives, int& gridSize);
    void readLevelInfo(int level, int &c_percent, int &m_percent, int &g_percent, int &k_percent, int &n_percent);
    void record(std::string &action);

private:
    std::ifstream inputFile;  // For reading input file
    std::ofstream logFile;    // For writing log file

};

#endif