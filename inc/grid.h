#pragma once // sam e as #ifndef/#define etc
#include <iostream>
#include <vector>
#include <raylib.h> // Include raylib for graphics
class Grid {
public:
    Grid();
    void Initalize();
    void Print();
    void Draw(); // Function to draw the grid
    int grid[20][10]; // 20 rows and 10 columns
private:
    std::vector<Color> getCellColors(); // Function to get colors for each cell
    int numRows;
    int numCols;
    int cellSize;
    std::vector<Color> colors; // Vector to store colors for each cell
};
