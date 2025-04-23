#include "colors.h"



const Color darkGrey = DARKGRAY;
const Color green = GREEN;
const Color red = RED;
const Color blue = BLUE;
const Color yellow = YELLOW;
const Color purple = PURPLE;
const Color orange = ORANGE;
const Color cyan = {21,204,209,255};
const Color lightblue = {60, 85, 160, 255} ;

std::vector<Color> getCellColors(){
    // The order of the vecotr matters because it is used to color the blocks
    return {darkGrey, green, red, blue, yellow, purple, orange, cyan};
}