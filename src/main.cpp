#include <iostream>
#include "raylib.h"
#include "data.h"
#include "player.h"
#include "balls.h"
#include "enemy.h"
#include "score.h"
#include "game.h"


const int screenWidth = 800;
const int screenHeight = 450;

int playerPosX;
int playerPosY;
int moveSpeed = 3;
int liveCount;
int scoreCount;
int highScore;

int ballCount;
int ballsOnScreen;
int *ballPosX = new int[1];
int *ballPosY = new int[1];

int enemyCount;
int *enemyPosX = new int[1];
int *enemyPosY = new int[1];
int *enemyPreference = new int[1];

bool isBallPosGenerated;
bool isEnemyPosGenerated;
bool isGameOver;

int main() {
    Player player;
    Balls balls;
    Enemy enemy;
    Score score;
    Game game;

    game.startGame();
    score.loadHigh();

    InitWindow(screenWidth, screenHeight, "BallKiller3000");
    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        std::string liveMess = "Lives: " + std::to_string(liveCount);
        std::string scoreMess = "Score: " + std::to_string(scoreCount);
        std::string highMess = "High: " + std::to_string(highScore);
        DrawText(liveMess.c_str(), 20, 10, 20, RED);
        DrawText(scoreMess.c_str(), 220, 10, 20, RED);
        DrawText(highMess.c_str(), 420, 10, 20, RED);


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

                enemy.givePreference(e);
            }
            DrawRectangle(enemyPosX[e], enemyPosY[e], 60, 30, YELLOW);
        }
        isEnemyPosGenerated = true;

        if (isGameOver) {
            DrawText("Game Over!!!", screenWidth / 2 - 3 * 60, screenHeight / 2 - 30, 60, RED);
            DrawText("Press return to restart", screenWidth / 2 - 3 * 60 - 10, screenHeight / 2 + 30, 30, RED);
            if (IsKeyPressed(KEY_ENTER)) player.resetGame();
        };

        EndDrawing();
        if (!isGameOver) {
            player.movePlayer();
        }

        enemy.move();

    }
    return 0;
}

