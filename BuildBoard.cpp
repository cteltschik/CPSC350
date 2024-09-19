#include "BuildBoard.h"

BuildBoard::BuildBoard(){
    
};

BuildBoard::BuildBoard(int gridSize) : size(gridSize), total(gridSize * gridSize) {
    grid = new char*[size];
    for (int i = 0; i < size; i++) {
        grid[i] = new char[size](); // Initialize with '\0'
    }
    initializeGrid();
}

// Destructor to deallocate memory
BuildBoard::~BuildBoard() {
    for (int i = 0; i < size; i++) {
        delete[] grid[i];
    }
    delete[] grid;
}

int BuildBoard::getSize(){
    return size;
};

// Initialize the grid with empty spaces ('x' for nothing)
void BuildBoard::initializeGrid() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            grid[i][j] = 'x';  // Set all to empty spaces initially
        }
    }
}

// Get element at a specific grid position
char BuildBoard::getElement(int row, int col) {
    return grid[row][col];
}

// Set an element at a specific grid position
void BuildBoard::setElement(int row, int col, char element) {
    grid[row][col] = element;
}

// Place coins based on percentage
void BuildBoard::placeCoins(int c_percentage) {
    int coinsToPlace = (c_percentage * total) / 100;
    while (coinsToPlace > 0) {
        int randRow = std::rand() % size;
        int randCol = std::rand() % size;
        if (grid[randRow][randCol] == 'x') {
            grid[randRow][randCol] = 'c';
            coinsToPlace--;
        }
    }
}

// Place mushrooms based on percentage
void BuildBoard::placeMushrooms(int m_percentage) {
    int mushToPlace = (m_percentage * total) / 100;
    while (mushToPlace > 0) {
        int randRow = std::rand() % size;
        int randCol = std::rand() % size;
        if (grid[randRow][randCol] == 'x') {
            grid[randRow][randCol] = 'm';
            mushToPlace--;
        }
    }
}

// Place Goombas based on percentage
void BuildBoard::placeGoombas(int g_percentage) {
    int goomToPlace = (g_percentage * total) / 100;
    while (goomToPlace > 0) {
        int randRow = std::rand() % size;
        int randCol = std::rand() % size;
        if (grid[randRow][randCol] == 'x') {
            grid[randRow][randCol] = 'g';
            goomToPlace--;
        }
    }
}

// Place Koopa Troopas based on percentage
void BuildBoard::placeKoopTroops(int k_percentage) {
    int koopToPlace = (k_percentage * total) / 100;
    while (koopToPlace > 0) {
        int randRow = std::rand() % size;
        int randCol = std::rand() % size;
        if (grid[randRow][randCol] == 'x') {
            grid[randRow][randCol] = 'k';
            koopToPlace--;
        }
    }
}

// Place empty spaces based on percentage
void BuildBoard::placeNothing(int n_percentage) {
    int nothingToPlace = (n_percentage * total) / 100;
    while (nothingToPlace > 0) {
        int randRow = std::rand() % size;
        int randCol = std::rand() % size;
        if (grid[randRow][randCol] == 'x') {
            grid[randRow][randCol] = 'x'; // Already empty but reconfirm
            nothingToPlace--;
        }
    }
}

// Display the current state of the board to the output file
void BuildBoard::displayBoard(std::ofstream &outputFile) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            outputFile << grid[i][j] << ' ';
        }
        outputFile << '\n';
    }
}