#include "Level.h"


Level::Level() : levelNum(0), allLevels(0), board(0){
  
};

// Constructor to initialize the level with a grid size
Level::Level(int gridSize, int levelNum, int allLevels) : board(gridSize), levelNum(levelNum), allLevels(allLevels) {

};

// Method to build the level based on the percentage data for coins, mushrooms, Goombas, Koopas, and empty spaces
void Level::makeLevel(int c_percent, int m_percent, int g_percent, int k_percent, int n_percent) {
    board.placeCoins(c_percent);
    board.placeMushrooms(m_percent);
    board.placeGoombas(g_percent);
    board.placeKoopTroops(k_percent);
    board.placeNothing(n_percent);
};

// Method to retrieve the character at a specific position
char Level::getPosition(int row, int col) {
    return board.getElement(row, col);
};

// Method to set a character at a specific position in the grid
void Level::setPosition(int row, int col, char character) {
    board.setElement(row, col, character);
};

// Method to display the current state of the level to the output file
void Level::displayLevel(std::ofstream &outputFile) {
    board.displayBoard(outputFile);
};

bool Level::isLastLevel(){
   if (levelNum == allLevels - 1){
       return true;
   }; 
   return false;
};

int Level::getLevelNum(){
    return levelNum;
};

int Level::getGridSize(){
    return board.getSize();
};