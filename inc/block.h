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
    int id;
    std::map<int, std::vector<blockPosition>> cells;
private:
    int cellSize;
    int rotaionState;
    std::vector<Color> colors;
};