#include <iostream>
#include <ctime>
#include "game.h"
#include "colors.h"
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
    const int screenWidth = 600;
    const int screenHeight = 610;
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
        if(eventTriggered(0.2)==true)
        {
            game.moveBlockDown();
        }
        BeginDrawing();
        ClearBackground(DARKBLUE);
        DrawText("Score", 420, 5, 20, LIGHTGRAY);
        DrawRectangleRounded({370, 25, 170, 60}, 1.2, 6, lightblue);
        DrawText(std::to_string(game.score).c_str(), 445, 35, 40, LIGHTGRAY);
        DrawText("Next Block", 400, 120, 20, LIGHTGRAY);
        DrawRectangleRounded({330, 145, 250, 200}, 0.5, 6, lightblue);
        game.Draw(); // Draw the grid
        

        EndDrawing();
    }

    // De-Initialization
    CloseWindow(); // Close window and OpenGL context

    return 0;
}