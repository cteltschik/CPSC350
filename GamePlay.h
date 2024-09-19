#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <iostream>

#include "Level.h"
#include "Mario.h"
#include "FileProcessor.h"

class GamePlay{
    public:
       GamePlay(std::string inputFile, std::string outputFile);
       ~GamePlay();
       void beginPlay();
    private:
       int currLevel;
       int allLevels;
       int lives;
       int gridSize;
       std::string action;

       Level& currentLevel;
       Level* levels;
       Mario mario;
       FileProcessor fileProcessor;

       void makeLevels();
       void playLevel();
       void logPlayerActions(std::string action);
};

#endif