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
int lives = 3;

int ballCount = 3;
int ballsOnScreen = 3;
int *ballPosX = new int[1];
int *ballPosY = new int[1];

int enemyCount = 3;
int *enemyPosX = new int[1];
int *enemyPosY = new int[1];

bool isBallPosGenerated = false;
bool isEnemyPosGenerated = false;
bool isGameOver = false;

int main() {
    Player player;
    Balls balls;


    InitWindow(screenWidth, screenHeight, "BallKiller3000 Test");
    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose()) {
        BeginDrawing();
        if (!isGameOver) {
            ClearBackground(RAYWHITE);


            for (int b = 0; b < ballCount; ++b) {
                if (!isBallPosGenerated) {
                    ballPosX[b] = balls.generateBallPos('x');
                    ballPosY[b] = balls.generateBallPos('Y');
                }
                DrawCircle(ballPosX[b], ballPosY[b], 30, BLUE); // makes a test ball
            }
            isBallPosGenerated = true;

            // generate player
            DrawCircle(playerPosX, playerPosY, 20, RED); // makes a temp player

            //generates enemies
            for (int e = 0; e < enemyCount; e++) {
                if (!isEnemyPosGenerated) {
                    enemyPosX[e] = balls.generateBallPos(
                            'x'); //the ball pos generator works just fine for the enemy's one
                    enemyPosY[e] = balls.generateBallPos('y');
                }
                DrawRectangle(enemyPosX[e], enemyPosY[e], 60, 30, YELLOW);
            }
            isEnemyPosGenerated = true;
        } else {
            DrawText("Game Over!!!", screenWidth / 2, screenHeight / 2, 20, RED);
        };

        EndDrawing();
        if (!isGameOver) {
            player.movePlayer();

        }
    }

    return 0;
}

