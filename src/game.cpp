#include "game.h"

Game::Game()
{
    grid = Grid();
    blocks = getAllBlocks();
    currentBlock = getRandomBlock();
    nextBlock = getRandomBlock();
};

Block Game::getRandomBlock()
{
    if(blocks.empty())
    {
        blocks = getAllBlocks();
    }
    int randomIndex = rand() % blocks.size();
    Block block = blocks[randomIndex];
    blocks.erase(blocks.begin() + randomIndex);
    return block;
};

std::vector<Block> Game::getAllBlocks()
{
    return {Iblock(), Lblock(), Jblock(), Zblock(), Sblock(), Oblock(), Tblock()};
};

void Game::Draw()
{
    grid.Draw();
    currentBlock.Draw();
}

void Game::handleInput()
{
    int keyPressed = GetKeyPressed();
    switch (keyPressed)
    {
    case KEY_LEFT:
        moveBlockLeft();
        break;
    case KEY_RIGHT:
        moveBlockRight();
        break;
    case KEY_DOWN:
        moveBlockDown();
        break;
    default:
        break;
    }
}

void Game::moveBlockLeft()
{
    currentBlock.Move(0,-1);
    if (isBlockOutside())
    {
        currentBlock.Move(0,1);
    }
    
}

void Game::moveBlockRight()
{
    currentBlock.Move(0,1);
    if (isBlockOutside())
    {
        currentBlock.Move(0,-1);
    }
}

void Game::moveBlockDown()
{
    currentBlock.Move(1,0);
    if (isBlockOutside())
    {
        currentBlock.Move(-1,0);
    }
}

bool Game::isBlockOutside()
{
    std::vector<blockPosition> tiles = currentBlock.getCellPositions();
    for(blockPosition item: tiles)
    {
        if (grid.isCellOutside(item.row,item.column))
        {
            return true;
        }
        
    }
    return false;
}