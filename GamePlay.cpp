#include "GamePlay.h"
#include <iostream>

GamePlay::GamePlay(std::string specFile, std::string logFile) : currentLevel(levels[currLevel]){
    FileProcessor(specFile, logFile);
    currLevel = 0;
    mario = 0;
    levels = nullptr;
    fileProcessor.readSpecFile(allLevels, lives, gridSize);
    levels = new Level[allLevels];
    makeLevels();
    
};

void GamePlay::beginPlay(){
    FileProcessor file(std::string specFile, std::string logFile);
    fileProcessor.readSpecFile(allLevels, lives, gridSize);
    while (lives > 0 && currLevel < allLevels) {
        playLevel();
        ++currLevel;
    }
    logPlayerActions(lives > 0 ? "Mario won!" : "Mario lost!");
    std::cout << lives <<  ", " << currLevel << std::endl;
};

void GamePlay::makeLevels(){
    int level, c_percent, m_percent, g_percent, k_percent, n_percent;
    for (int i = 0; i < allLevels; ++i) {
        levels[i] = Level(gridSize, i, allLevels);
        fileProcessor.readLevelInfo(level, c_percent, m_percent, g_percent, k_percent, n_percent);
        levels[i].makeLevel(c_percent, m_percent, g_percent, k_percent, n_percent);
    }
};

void GamePlay::playLevel(){
// process level
std::ofstream logFile;
int row = 0;
int col = 0;
int dir;

while(lives > 0){
    dir = mario.getRandDir();
    mario.move(dir, currentLevel);
    action = "Mario lost all lives on level " + std::to_string(currLevel + 1);
    logPlayerActions(action);
    return;

    currentLevel.displayLevel(logFile);

    if (currentLevel.isLastLevel()) {
            action = "Mario completed level " + std::to_string(currLevel + 1);
            logPlayerActions(action);
            break;
        }
    }
    action = "Mario moves to level " + std::to_string(currLevel + 2);
    logPlayerActions(action);
};

void GamePlay::logPlayerActions(std::string action){
    fileProcessor.record(action);
};

GamePlay::~GamePlay(){
    delete[] levels;
};

