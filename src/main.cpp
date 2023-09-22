#include <iostream>
#include "raylib-cpp.hpp"
#include "version.h"
#include "player.h"
#include "ball.h"
#include "enemy.h"
#include "data.h"
#include "gameHandler.h"
#include "gui.h"

// window
float screenWidth = 800;
float screenHeight = 450;

// game states
bool isGameActive;
bool isGamePaused;
bool isGameOver;

int level;

// entities
Player *player;
Ball *ball;
Enemy *enemy;

int playerCount;
int ballCount;
int ballsInScreen;
int enemyCount;
int enemiesInScreen;


int main() {
    // initialises the window
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    raylib::Window gameWindow((int) screenWidth, (int) screenHeight, "Ballkiller v"  BALL_KILLER_VERSION);

    // Set window properties
    SetExitKey(KEY_NULL);
    gameWindow.SetTargetFPS(60);



    // Main game loop (executes every frame)
    while (!gameWindow.ShouldClose()) {
        if (IsKeyPressed(KEY_ESCAPE)) {
            if (isGameActive) {
                isGamePaused = true;
            }
        }
        // Get window resize
        if (screenWidth != (float) gameWindow.GetRenderWidth()) {
            Gui::resizeWindow();
        }
        if (screenHeight != (float) gameWindow.GetRenderHeight()) {

            Gui::resizeWindow();
        }

        gameWindow.BeginDrawing();
        gameWindow.ClearBackground(RAYWHITE);


        if (isGameActive) {
            Gui::gameElements();

            if (isGameOver) {
                Gui::gameOver();
            } else if (isGamePaused) {
                Gui::pauseMenu();
            }

            if (!isGamePaused) {
                for (int p = 0; p < playerCount; ++p) {
                    player[p].getMove();
                }
                for (int e = 0; e < enemyCount; ++e) {
                    enemy[e].generateMove();
                }
            }


            Gui::gameOverlay();

        } else {
            Gui::startScreen();
        }

        // draw version
        raylib::DrawText("v"  BALL_KILLER_VERSION,
                         (int) screenWidth - (int) (std::string(BALL_KILLER_VERSION).length() * 5) - 10,
                         (int) screenHeight - 15, 10, GRAY);

        gameWindow.EndDrawing();

        if (isGameActive && !isGameOver) {
            //check game over
            bool isPlayerAlive = false;
            for (int p = 0; p < playerCount; ++p) {
                if (!player[p].isDead) isPlayerAlive = true;
            }
            if (!isPlayerAlive) {
                isGameOver = true;
                if (playerCount == 2) {
                    for (int p = 0; p < playerCount; ++p) {
                        if (player[p].score > player[p].highScore)
                            GameHandler::saveHigh(player[p].score, true, p);
                    }
                } else if (player[0].score > player[0].highScore)GameHandler::saveHigh(player[0].score);

                for (int p = 0; p < playerCount; ++p) {
                    if (player[p].score > player[p].highScore) player[p].highScore = player[p].score;
                }
            }
        }

        if (gameWindow.ShouldClose()) {
            if (isGameActive) {
                if (playerCount == 2) {
                    for (int p = 0; p < playerCount; ++p) {
                        if (player[p].score > player[p].highScore) GameHandler::saveHigh(player[p].score, true, p);
                    }
                } else if (player[0].score > player[0].highScore) GameHandler::saveHigh(player[0].score);
            }

            gameWindow.Close();
        }

    }

    return 0;
}

// fix msvc release
#if defined(MSVC)

int WinMain() {
    return main();
}

#endif