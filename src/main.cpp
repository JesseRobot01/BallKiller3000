#include <iostream>
#include "raylib.h"


int main() {
    int moveSpeed = 3;
    const int screenWidth = 800;
    const int screenHeight = 450;

    int playerPosX = screenWidth / 2;
    int playerPosY = screenHeight / 2;

    InitWindow(screenWidth, screenHeight, "BallKiller3000 Test");


    SetTargetFPS(60);
    // Main game loop
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);


        DrawCircle(playerPosX, playerPosY, 20, RED); // makes a temp player
        EndDrawing();


        if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
            if (playerPosY >= 0)
                playerPosY -= moveSpeed;
        }
        if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
            if (playerPosY <= screenHeight)
                playerPosY += moveSpeed;
        }

        if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
            if (playerPosX >= 0)
                playerPosX -= moveSpeed;

        }
        if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
            if (playerPosX <= screenWidth)
                playerPosX += moveSpeed;


        }
    }

    return 0;
}

