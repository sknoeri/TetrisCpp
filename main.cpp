#include <iostream>
#include <ctime>
#include "game.h"
extern "C" {
#include <raylib.h>
}

double lastUpdateTime = 0;

bool eventTriggered(double interval)
{
    double currentTime = GetTime();
    if(currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }else{
        return false;
    }
}

int main() {
    srand(time(NULL));
    // Initialization
    const int screenWidth = 300;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Tetris - Raylib");
    SetTargetFPS(60); // Set the game to run at 60 frames per second

    // Grid grid = Grid(); // Create a Grid object
    // grid.grid[0][0] = 1;
    // grid.grid[3][9] = 2;
    // grid.grid[3][4] = 3;
    // grid.Print(); // Print the grid to the console

    // Iblock block; //= Zblock();
    // block.Move(0,0);
    Game game = Game(); // Create a Game object
    // Main game loop
    while (!WindowShouldClose()) { // Detect window close button or ESC key
        // Update

        // Draw
        game.handleInput();
        if(eventTriggered(0.01)==true)
        {
            game.moveBlockDown();
        }
        BeginDrawing();
        ClearBackground(DARKBLUE);
        game.Draw(); // Draw the grid
        

        EndDrawing();
    }

    // De-Initialization
    CloseWindow(); // Close window and OpenGL context

    return 0;
}