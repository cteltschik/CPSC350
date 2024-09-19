#ifndef LEVEL_H
#define LEVEL_H

#include <iostream>

#include "BuildBoard.h"

class Level{
    public: 
       Level();
       Level(int gridSize, int levelNum, int allLevels);
       void makeLevel(int c_percent, int m_percent, int g_percent, int k_percent, int n_percent);
       char getPosition(int row, int col);
       void setPosition(int row, int col, char character);
       void displayLevel(std::ofstream &outputFile);
       bool isLastLevel();
       int getLevelNum();
       int getGridSize();
    
    private:
       int levelNum;
       int allLevels;
       BuildBoard board;
       
};





#endif