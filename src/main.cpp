#include <iostream>
#include "raylib-cpp.hpp"
#include "version.h"
#include "data.h"
#include "pos.h"
#include "gameHandler.h"
#include "enemyAi.h"

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

// the variables
int screenWidth = 900;
int screenHeight = 450;


raylib::Vector2 playerPos;
raylib::Vector2 *ballPos;
raylib::Vector2 *enemyPos;
raylib::Vector2 *enemySize;
float moveSpeed = 3;

int score;
int highScore;
int lives;
int level;
int ballsInScreen;
int ballCount;
int enemyCount;
int *enemyPreference;

bool isGameOver = true;



int main() {
//initialize the variables
    GameHandler::startGame();

    //initializes the window
    raylib::Window window(screenWidth, screenHeight, "BallKiller3000 v" BALL_KILLER_VERSION);
    SetTargetFPS(60);

    // main game loop (executes every frame)
    while (!window.ShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // renders the balls, enemies and the player
        for (int b = 0; b < ballCount; ++b) {
            DrawCircleV(ballPos[b], 30, BLUE);
        }
        for (int e = 0; e < enemyCount; ++e) {
            DrawRectangleV(enemyPos[e], enemySize[e], YELLOW);


        }

        DrawCircleV(playerPos, 20, RED);

        // Draws the GUI
        raylib::DrawText("Lives: " + std::to_string(lives), 20, 10, 20, RED);
        raylib::DrawText("Score: " + std::to_string(score), 140, 10, 20, RED);
        raylib::DrawText("High: " + std::to_string(highScore), 260, 10, 20, RED);
        raylib::DrawText("Level: " + std::to_string(level), 380, 10, 20, RED);
        raylib::DrawText("v"  BALL_KILLER_VERSION, screenWidth - (std::string(BALL_KILLER_VERSION).length() * 5) - 10,
                         screenHeight - 15, 10, GRAY);

        // The game over screen
        if (isGameOver) {
            DrawText("Game Over!!!", screenWidth / 2 - 3 * 60, screenHeight / 2 - 30, 60, RED);
            DrawText("Press enter to restart", screenWidth / 2 - 3 * 60 - 10, screenHeight / 2 + 30, 30, RED);
            if (IsKeyPressed(KEY_ENTER)) GameHandler::startGame();
        }


        EndDrawing();

        // move the player
        if (!isGameOver) {
            Pos::getPlayerMoveInput();
        }

        EnemyAi::generateMove();
    }

    return 0;
}