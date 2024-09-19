#include "Mario.h"

Mario::Mario(){
    
};

Mario::Mario(int startLives) : lives(startLives), coins(0), powerLevel(0), moves(0), enemiesDefeated(0){
};

void Mario::move(int dir, Level &currLevel) {
    updatePosition(dir);
    interact(currLevel);
};

void Mario::interact(Level &currLevel) {
    std::ofstream logFile;
    char position = currLevel.getPosition(row, col);
    
    switch (position) {
        case 'c':
            collectCoin();
            action = "Mario collected a coin";
            break;
        case 'm':
            eatMushroom();
            action = "Mario ate a mushroom";
            break;
        case 'g':
            action = fightEnemy('g', currLevel);
            break;
        case 'k':
            action = fightEnemy('k', currLevel);
            break;
        case 'b':
            action = fightBoss('b', currLevel);
            break;
        case 'w':
            handleWarpPipe(currLevel);
            action = "Mario warped";
            break;
        case 'x':
            action = "The position is empty";
            break;
        default:
            action = "Unknown position";
            break;
    }
    levelNum = currLevel.getLevelNum();
    logMarioActions(logFile, levelNum, row, col, action);
    ++moves;
};

void Mario::collectCoin() {
    ++coins;
    if (coins >= 20) {
        ++lives;
        coins = 0;
    }
}

void Mario::eatMushroom() {
    if (powerLevel < 2) {
        ++powerLevel;
    }
}

std::string Mario::fightEnemy(char enemy, Level &currLevel) {
    randChance = std::rand() % 100;
    bool defeated = false;

    if (enemy == 'g') {
        // Goomba: 80% win, 20% lose
        if (randChance < 80) {
            defeated = true;
        } else {
            defeated = false;
        }
    } else if (enemy == 'k') {
        // Koopa: 65% win, 35% lose
        if (randChance < 65) {
            defeated = true;
        } else {
            defeated = false;
        }
    }

    if (defeated) {
        action = enemy == 'g' ? "Mario fought a Goomba and won" : "Mario fought a Koopa and won";
        currLevel.setPosition(row, col, 'x'); // Clear the position
        if (++enemiesDefeated == 7) {
            ++lives;
            enemiesDefeated = 0; // Reset defeated count
        }
    } else {
        if (powerLevel > 0) {
            --powerLevel;
            action = enemy == 'g' ? "Mario fought a Goomba and lost" : "Mario fought a Koopa and lost";
        } else {
            --lives;
            action = enemy == 'g' ? "Mario fought a Goomba and lost a life" : "Mario fought a Koopa and lost a life";
            if (lives <= 0) {
                action = "Mario lost all lives";
            }
        }
    }
    
    return action;
};

std::string Mario::fightBoss(char boss, Level &currLevel) {
    randChance = std::rand() % 100;
    std::ofstream logFile;

    if (boss == 'b') {
        // 50% win, 50% lose
        if (randChance < 50) {
            // Mario wins the boss fight
            currLevel.setPosition(row, col, 'x');  // Clear the boss from the level
            action = "Mario defeated the Boss and cleared the level!";
            levelNum = currLevel.getLevelNum();
            if (currLevel.isLastLevel()) {
                // If it's the last level, Mario wins the game
                action += " Mario saved the princess and won the game!";
                logMarioActions(logFile, levelNum, row, col, action);
                std::exit(0);  // End the game
            } else {
                // Move to the next level
                action += " Mario moves to the next level!";
            }
            } else {
            // Mario loses the boss fight
            if (powerLevel > 1) {
                // Decrease power level by 2 if power level is greater than 1
                powerLevel -= 2;
                action = "Mario lost to the Boss. Power level decreased by 2.";
            } else {
                // If power level is 0 or 1, Mario loses a life
                --lives;
                powerLevel = 0;  // Reset power level to 0

                if (lives > 0) {
                    action = "Mario lost to the Boss and lost a life. Mario has " + std::to_string(lives) + " lives left and continues at the same position.";
                } else {
                    action = "Mario lost to the Boss and has no lives left. Game over.";
                    levelNum = currLevel.getLevelNum();
                    logMarioActions(logFile, levelNum, row, col, action);
                    std::exit(0);  // End the game
                }
            }
        }
    }
    return action;
};

std::string Mario::handleWarpPipe(Level &currLevel) {
    // Handle warping to a random position in the next level
    int newRow = std::rand() % currLevel.getGridSize();
    int newCol = std::rand() % currLevel.getGridSize();

    std::string actionBeforeWarp = "Mario entered a warp pipe at (" + std::to_string(row) + ", " + std::to_string(col) + ")";

    interact(currLevel);
};

void Mario::updatePosition(int dir) {
    // Update Mario's position on the grid based on the direction
    std::ofstream logFile;
    dir = getRandDir();

    switch(dir){
        case 1:
        action = "Mario will move UP.";

        case 2:
        action = "Mario will move DOWN.";

        case 3:
        action = "Mario will move LEFT";

        case 4:
        action = "Mario will move RIGHT";
    }
    logMarioActions(logFile, levelNum, row, col, action);
};

int Mario::getRandDir() {
    return std::rand() % 4;  // UP, DOWN, LEFT, RIGHT
};

void Mario::logMarioActions(std::ofstream &logFile, int level, int row, int col, std::string &action) {
    logFile << "Level: " << level << " Position: (" << row << ", " << col << ") Power Level: " << powerLevel
            << " Action: " << action << " Lives: " << lives << " Coins: " << coins << '\n';
};
