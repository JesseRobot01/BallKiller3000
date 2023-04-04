#include <iostream>
#include "raylib.h"


int main() {
    int moveSpeed = 3;
    const int screenWidth = 800;
    const int screenHeight = 450;

    int playerPosX = 190;
    int playerPosY = 200;

    InitWindow(screenWidth, screenHeight, "BallKiller3000 Test");


    SetTargetFPS(60);
    // Main game loop
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Hello World", playerPosX, playerPosY, 20, RED);  // Example
        EndDrawing();


        if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
            playerPosY -= moveSpeed;
        }
        if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
            playerPosY += moveSpeed;
        }

        if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
            playerPosX -= moveSpeed;
        }
        if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
            playerPosX += moveSpeed;

        }
    }

    return 0;
}

