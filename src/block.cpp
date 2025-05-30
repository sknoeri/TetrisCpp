#include "block.h"


Block::Block()
{
    cellSize = 30;
    rotaionState = 0;
    colors = getCellColors();
    rowOffset = 0;
    columnOffset = 3; // starts showing up in center of the grid
}


void Block::Draw(int offsetX, int offsetY)
{
    std::vector<blockPosition> tiles = getCellPositions();
    for(blockPosition item: tiles){
        DrawRectangle(item.column*cellSize+offsetX,item.row * cellSize+offsetY, cellSize-1,cellSize-1, colors[id]);
        // DrawRectangle(item.column*cellSize+6,item.row * cellSize+6, cellSize-1,cellSize-1, colors[id]);
    }
}

void Block::Move(int rows, int columns)
{
    rowOffset += rows;
    columnOffset += columns;
}

void Block::Rotate()
{
    rotaionState ++;
    if (rotaionState == cells.size())
    {
        rotaionState = 0;
    }
}

void Block::undoRotation()
{
    rotaionState --;
    if (rotaionState == -1)
    {
        rotaionState = cells.size()-1;
    }
}
std::vector<blockPosition> Block::getCellPositions()
{
    std::vector<blockPosition> tiles = cells[rotaionState];
    std::vector<blockPosition> moveTiles;
    for(blockPosition item: tiles){
        blockPosition newPos = blockPosition(item.row + rowOffset, item.column + columnOffset);
        moveTiles.push_back(newPos);
    }
    return moveTiles;
}