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
    bool GameOver;
    int score;

private:
    bool isBlockOutside();
    bool blockFits();
    void Reset();
    void updateScore(int rowsCleard);
    void rotateBlock();
    void lockBlock();
    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
};