// BASE CLASSES: BUILDBOARD, LIFE
// 1st CHILD CLASSES: POWERLEVEL, READFILE
// 2nd CHILD CLASSES: COINS, GOOMBA, KOOPTROOP, BOSS, WARP
// 3rd CHILD CLASSES: MOVE

#include <iostream>
#include <fstream>

#include "GamePlay.h"
#include "BuildBoard.h"

int main (int argc, char** argv){

std::cout << "You have entered " << argc << " arguments" << std::endl;
    for (int i = 0; i < argc; i++){
        std::cout << "arg" << i << ": " << argv[i] << std::endl;
    }

std::string inputFile = argv[1];
std::string outputFile = argv[2];


FileProcessor file(inputFile, outputFile);
GamePlay game(inputFile, outputFile);
game.beginPlay();



    return 0;
};