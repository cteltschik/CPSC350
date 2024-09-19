#ifndef BUILDBOARD_H
#define BUILDBOARD_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

class BuildBoard {
public:
    BuildBoard();
    BuildBoard(int gridSize);  
    ~BuildBoard();           

    void placeCoins(int c_percentage);      
    void placeMushrooms(int m_percentage); 
    void placeGoombas(int g_percentage);    
    void placeKoopTroops(int k_percentage); 
    void placeNothing(int n_percentage);    

    char getElement(int row, int col);      
    void setElement(int row, int col, char element); 
    void displayBoard(std::ofstream &outputFile);
    int getSize();    

private:
    int size;        // Size of the grid (NxN)
    char **grid;     // 2D array representing the grid
    int total;       // Total number of grid spaces

    void initializeGrid();  // Initialize the grid with empty characters
};

#endif