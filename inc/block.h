#pragma once
#include <vector>
#include <map>
#include <iostream>
#include "blockPosition.h"
#include "colors.h"


class Block{
public:
    Block();
    void Draw(int offsetX, int offsetY);
    void Move(int rows, int columns);
    void Rotate();
    void undoRotation();
    std::vector<blockPosition> getCellPositions();
    void Move();
    int id;
    std::map<int, std::vector<blockPosition>> cells;
private:
    int cellSize;
    int rotaionState;
    std::vector<Color> colors;
    int rowOffset;
    int columnOffset;
};