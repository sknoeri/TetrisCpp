#pragma once
#include <vector>
#include <map>
#include <iostream>
#include "blockPosition.h"
#include "colors.h"


class Block{
public:
    Block();
    void Draw();
    void Move(int rows, int columns);
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