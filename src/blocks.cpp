#include "block.h"
#include "blockPosition.h"

class Lblock :public Block{
public:
    Lblock(){
        id = 1;
        cells[0] = {blockPosition(0,2),blockPosition(1,0),blockPosition(1,1),blockPosition(1,2)};
        cells[1] = {blockPosition(0,1),blockPosition(1,1),blockPosition(2,1),blockPosition(2,2)};
        cells[2] = {blockPosition(1,0),blockPosition(1,1),blockPosition(1,2),blockPosition(2,0)};
        cells[3] = {blockPosition(0,0),blockPosition(0,1),blockPosition(1,1),blockPosition(2,1)};
    };
};

class Jblock :public Block{
public:
    Jblock(){
        id = 2;
        cells[0] = {blockPosition(0,0),blockPosition(1,0),blockPosition(1,1),blockPosition(1,2)};
        cells[1] = {blockPosition(0,1),blockPosition(0,2),blockPosition(1,1),blockPosition(2,1)};
        cells[2] = {blockPosition(1,0),blockPosition(1,1),blockPosition(1,2),blockPosition(2,2)};
        cells[3] = {blockPosition(0,1),blockPosition(1,1),blockPosition(2,1),blockPosition(2,0)};
    };
};

class Iblock :public Block{
public:
    Iblock(){
        id = 3;
        cells[0] = {blockPosition(1,0),blockPosition(1,1),blockPosition(1,2),blockPosition(1,3)};
        cells[1] = {blockPosition(0,2),blockPosition(1,2),blockPosition(2,2),blockPosition(3,2)};
        cells[2] = {blockPosition(2,0),blockPosition(2,1),blockPosition(2,2),blockPosition(2,3)};
        cells[3] = {blockPosition(0,1),blockPosition(1,1),blockPosition(2,1),blockPosition(3,1)};
        Move(-1,0);
    };
};

class Oblock :public Block{
public:
    Oblock(){
        id = 4;
        cells[0] = {blockPosition(0,0),blockPosition(1,0),blockPosition(0,1),blockPosition(1,1)};
        Move(0,1);
    };
};

class Sblock :public Block{
public:
    Sblock(){
        id = 5;
        cells[0] = {blockPosition(0,1),blockPosition(0,2),blockPosition(1,0),blockPosition(1,1)};
        cells[1] = {blockPosition(0,1),blockPosition(1,1),blockPosition(1,2),blockPosition(2,2)};
        cells[2] = {blockPosition(1,1),blockPosition(1,2),blockPosition(2,0),blockPosition(2,1)};
        cells[3] = {blockPosition(0,0),blockPosition(1,0),blockPosition(1,1),blockPosition(2,1)};
    };
};

class Tblock :public Block{
public:
    Tblock(){
        id = 6;
        cells[0] = {blockPosition(0,1),blockPosition(1,0),blockPosition(1,1),blockPosition(1,2)};
        cells[1] = {blockPosition(0,1),blockPosition(1,1),blockPosition(1,2),blockPosition(2,1)};
        cells[2] = {blockPosition(1,0),blockPosition(1,1),blockPosition(1,2),blockPosition(2,1)};
        cells[3] = {blockPosition(0,1),blockPosition(1,0),blockPosition(1,1),blockPosition(2,1)};
    };
};

class Zblock :public Block{
public:
    Zblock(){
        id = 7;
        cells[0] = {blockPosition(0,0),blockPosition(0,1),blockPosition(1,1),blockPosition(1,2)};
        cells[1] = {blockPosition(0,2),blockPosition(1,1),blockPosition(1,2),blockPosition(2,1)};
        cells[2] = {blockPosition(1,0),blockPosition(1,1),blockPosition(2,1),blockPosition(2,2)};
        cells[3] = {blockPosition(0,1),blockPosition(1,0),blockPosition(1,1),blockPosition(2,0)};
    };
};