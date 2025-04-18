#pragma once // sam e as #ifndef/#define etc
#include <iostream>
#include <vector>
#include <raylib.h> // Include raylib for graphics
#include "colors.h"
class Grid {
public:
    Grid();
    void Initalize();
    void Print();
    void Draw(); // Function to draw the grid
    bool isCellOutside(int row, int column);
    int grid[20][10]; // 20 rows and 10 columns
private:
    int numRows;
    int numCols;
    int cellSize;
    std::vector<Color> colors; // Vector to store colors for each cell
};
