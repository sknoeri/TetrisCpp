#pragma once
#include "grid.h"
#include <random>
#include "../src/blocks.cpp"
class Game
{
public:
    Game();
    Block getRandomBlock();
    std::vector<Block> getAllBlocks();
    void Draw();
    void handleInput();
    void moveBlockLeft();
    void moveBlockRight();
    void moveBlockDown();
    Grid grid;

private:
    bool isBlockOutside();
    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
};