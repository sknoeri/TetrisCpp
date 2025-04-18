#include "grid.h"


Grid::Grid() {
    numRows = 20; // Number of rows in the grid
    numCols = 10; // Number of columns in the grid
    cellSize = 30; // Size of each cell in pixels
    Initalize(); // Call the initialization function
    colors = getCellColors(); // Get the colors for each cell
};
void Grid::Initalize() {
    // Initialize the grid with zeros
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            grid[i][j] = 0;
        }
    }
}

void Grid::Print() {
    // Print the grid to the console
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Grid::Draw() {
    // Draw the grid
    for ( int i = 0; i<numRows; i++) {
        for (int j = 0; j<numCols; j++){
            int cellValue = grid[i][j];
            DrawRectangle(j*cellSize+1,i*cellSize+1,cellSize-1,cellSize-1,colors[cellValue]);
        }
    }
}

bool Grid::isCellOutside(int row, int column)
{
    if(row >= 0 && row < numRows && column >=0 && column<numCols)
    {
        return false;
    }
    else
    {
        return true;
    }
}