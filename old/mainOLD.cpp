#include <iostream>
#include "raylib-cpp.hpp"
#include "data.h"
#include "player.h"
#include "balls.h"
#include "enemy.h"
#include "score.h"
#include "game.h"
#include "version.h"

#if defined(PLATFORM_WEB)

#include <emscripten/emscripten.h>

#endif


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
int *ballPosX = new int[99];
int *ballPosY = new int[99];

int enemyCount;
int *enemyPosX = new int[99];
int *enemyPosY = new int[99];
int *enemyPreference = new int[99];

bool isBallPosGenerated;
bool isEnemyPosGenerated;
bool isGameOver;

int main_old() {
    Game::startGame();
    Score::loadHigh();
    raylib::Window window(screenWidth, screenHeight, "BallKiller3000 v"  BALL_KILLER_VERSION);
    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);


        for (int b = 0; b < ballCount; ++b) {
            if (!isBallPosGenerated) {
                ballPosX[b] = Balls::generateBallPos('x');
                ballPosY[b] = Balls::generateBallPos('Y');
            }
            DrawCircle(ballPosX[b], ballPosY[b], 30, BLUE); // makes a test ball
        }
        isBallPosGenerated = true;

        // generate player
        DrawCircle(playerPosX, playerPosY, 20, RED); // makes a temp player

        //generates enemies
        for (int e = 0; e < enemyCount; e++) {
            if (!isEnemyPosGenerated) {
                enemyPosX[e] = Balls::generateBallPos(
                        'x'); //the ball pos generator works just fine for the enemy's one
                enemyPosY[e] = Balls::generateBallPos('y');

                Enemy::givePreference(e);
            }
            DrawRectangle(enemyPosX[e], enemyPosY[e], 60, 30, YELLOW);
        }
        isEnemyPosGenerated = true;


        // GUI
        if (isGameOver) {
            DrawText("Game Over!!!", screenWidth / 2 - 3 * 60, screenHeight / 2 - 30, 60, RED);
            DrawText("Press enter to restart", screenWidth / 2 - 3 * 60 - 10, screenHeight / 2 + 30, 30, RED);
            if (IsKeyPressed(KEY_ENTER)) Game::startGame();
        }


        raylib::DrawText("Lives: " + std::to_string(liveCount), 20, 10, 20, RED);
        raylib::DrawText("Score: " + std::to_string(scoreCount), 220, 10, 20, RED);
        raylib::DrawText("High: " + std::to_string(highScore), 420, 10, 20, RED);
        raylib::DrawText("v"  BALL_KILLER_VERSION, screenWidth - (std::string(BALL_KILLER_VERSION).length() * 5) - 10,
                         screenHeight - 15, 10, GRAY);

        EndDrawing();
        if (!isGameOver) {
            Player::movePlayer();
        }

        Enemy::move();

    }
    return 0;
}

