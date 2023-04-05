#include <iostream>
#include "raylib.h"
#include "data.h"
#include "player.h"
#include "balls.h"


const int screenWidth = 800;
const int screenHeight = 450;

int playerPosX = screenWidth / 2;
int playerPosY = screenHeight / 2;
int moveSpeed = 3;

int ballCount = 3;
int ballsOnScreen = 3;
int ballPosX[3];
int ballPosY[3];
bool isPosGenerated = false;

int main() {
    Player player;
    Balls balls;


    InitWindow(screenWidth, screenHeight, "BallKiller3000 Test");
    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);


        for (int b = 0; b < ballCount; ++b) {
            if (!isPosGenerated) {
                ballPosX[b] = balls.generateBallPos('x');
                ballPosY[b] = balls.generateBallPos('Y');
            }
            DrawCircle(ballPosX[b], ballPosY[b], 30, BLUE); // makes a test ball
        }
        isPosGenerated = true;

        DrawCircle(playerPosX, playerPosY, 20, RED); // makes a temp player
        EndDrawing();

        player.movePlayer();


    }

    return 0;
}

