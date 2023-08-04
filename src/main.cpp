#include <iostream>
#include "raylib-cpp.hpp"
#include "version.h"
#include "data.h"
#include "pos.h"
#include "gameHandler.h"
#include "enemyAi.h"
#include "gui.h"

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

// the variables
int screenWidth = 800;
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
int enemiesInScreen;
int *enemyPreference;

bool isGameOver = true;

bool isTouchingScreen = false;
bool isControlStickBasePlayer = false;

raylib::Vector2 controlStickStartPos;
raylib::Vector2 controlStickCurrentPos;

int main() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);

    //initialise the variables
    GameHandler::startGame();

    //initialises the window
    raylib::Window window(screenWidth, screenHeight, "BallKiller3000 v" BALL_KILLER_VERSION);
    SetTargetFPS(60);

    // main game loop (executes every frame)
    while (!window.ShouldClose()) {
        if (screenWidth != window.GetRenderWidth() && screenHeight != window.GetRenderHeight()) {
            screenWidth = window.GetRenderWidth();
            screenHeight = window.GetRenderHeight();
            Gui::resizeWindow();
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        Gui::renderDefaultScreen();

        // move the player
        if (!isGameOver) {
            Gui::renderControlStick();
            Pos::getPlayerMoveInput();
        }


        EndDrawing();


        EnemyAi::generateMove();
    }

    return 0;
}