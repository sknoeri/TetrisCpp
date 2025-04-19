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
    DrawText("Welcome to Tetris!", 50, 200, 20, LIGHTGRAY);
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
    case KEY_UP:
        rotateBlock();
    default:
        break;
    }
}

void Game::moveBlockLeft()
{
    currentBlock.Move(0,-1);
    if (isBlockOutside() || blockFits()==false)
    {
        currentBlock.Move(0,1);
    }
    
}

void Game::moveBlockRight()
{
    currentBlock.Move(0,1);
    if (isBlockOutside() || blockFits()==false)
    {
        currentBlock.Move(0,-1);
    }
}

void Game::moveBlockDown()
{
    currentBlock.Move(1,0);
    if (isBlockOutside() || blockFits()==false)
    {
        currentBlock.Move(-1,0);
        lockBlock();
    }
}

void Game::lockBlock()
{
    std::vector<blockPosition> tiles = currentBlock.getCellPositions();
    for(blockPosition item :tiles)
    {
        grid.grid[item.row][item.column] = currentBlock.id; // fixes the block in the grid
    }
    currentBlock = nextBlock; // spawns a new block
    nextBlock = getRandomBlock();
    grid.clearFullRows(); // return the score
}

void Game::rotateBlock()
{
    currentBlock.Rotate();
    if(isBlockOutside()==true || blockFits() == false)
    {
        currentBlock.undoRotation();
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

bool Game::blockFits()
{
    std::vector<blockPosition> tiles = currentBlock.getCellPositions();
    for(blockPosition item: tiles)
    {
        if (grid.isCellEmpy(item.row,item.column) == false)
        {
            return false;
        }
    }
    return true;
}