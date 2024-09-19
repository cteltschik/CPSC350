#ifndef MARIO_H
#define MARIO_H

#include "BuildBoard.h"
#include "Level.h"

class Mario {
public: 
    Mario();
    Mario(int startLives);
    void move(int dir, Level &currLevel);
    void interact(Level &currLevel);
    void logMarioActions(std::ofstream &logFile, int level, int row, int col, std::string &action);
     int getRandDir();
private:
    int lives;
    int coins;
    int powerLevel;
    int row, col;
    int moves;
    int enemiesDefeated;
    int randChance;
    int levelNum;
    std::string action;

    void collectCoin();
    void eatMushroom();
    std::string fightEnemy(char enemy, Level &currLevel);
    std::string fightBoss(char boss, Level &currLevel);
    std::string handleWarpPipe(Level &currLevel);
    void updatePosition(int dir);
   

    
};



#endif