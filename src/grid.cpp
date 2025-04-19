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

bool Grid::isCellEmpy(int row, int col)
{
    if(grid[row][col]==0)
    {
        return true;
    }else
    {
        return false;
    }
}

int Grid::clearFullRows()
{
    int completed = 0;
    for(int row = numRows-1; row>=0; row--)
    {
        if(isRowFull(row))
        {
            clearRow(row);
            completed ++;
        }
        else if (completed>0)
        {
            moveRowDown(row,completed);
        }
        
    }
    return completed;
}


bool Grid::isRowFull(int row)
{
    for(int col=0; col < numCols; col++)
    {
        if(grid[row][col] == 0)
        {
            return false;
        }
    }
    return true;
}

void Grid::clearRow(int row)
{
    for(int col=0; col<numCols; col++)
    {
        grid[row][col] == 0;
    }
}

void Grid::moveRowDown(int row, int numDownRows)
{
    for(int col = 0; col < numCols; col++)
    {
        grid[row + numDownRows][col] = grid[row][col];
        grid[row][col] = 0;
    }
}