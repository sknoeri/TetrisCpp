#include "block.h"


Block::Block()
{
    cellSize = 30;
    rotaionState = 0;
    colors = getCellColors();
}


void Block::Draw()
{
    std::vector<blockPosition> titels = cells[rotaionState];
    for(blockPosition item: titels){
        DrawRectangle(item.column*cellSize+1,item.row * cellSize+1, cellSize-1,cellSize-1, colors[id]);
    }
}