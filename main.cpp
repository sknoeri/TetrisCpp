#include <iostream>
#include "grid.h"
extern "C" {
#include <raylib.h>
}
int main() {
    // Initialization
    const int screenWidth = 300;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Tetris - Raylib");
    SetTargetFPS(60); // Set the game to run at 60 frames per second

    Grid grid = Grid(); // Create a Grid object
    grid.grid[0][0] = 1;
    grid.grid[3][9] = 2;
    grid.grid[3][4] = 3;

    grid.Print(); // Print the grid to the console
    // Main game loop
    while (!WindowShouldClose()) { // Detect window close button or ESC key
        // Update

        // Draw
        BeginDrawing();
        ClearBackground(DARKBLUE);
        grid.Draw(); // Draw the grid
        DrawText("Welcome to Tetris!", 50, 200, 20, LIGHTGRAY);

        EndDrawing();
    }

    // De-Initialization
    CloseWindow(); // Close window and OpenGL context

    return 0;
}