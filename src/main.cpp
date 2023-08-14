#include "raylib-cpp.hpp"
#include "version.h"
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
float *ballSize;
int enemyCount;
int enemiesInScreen;
int *enemyPreference;

bool isGameOver = false;
bool hasGameStarted = false;
bool isGamePaused = false;

bool isTouchingScreen = false;
bool isControlStickBasePlayer = false;

raylib::Vector2 controlStickStartPos;
raylib::Vector2 controlStickCurrentPos;

float playerSize = 20;

float minimalEnemySizeX = 50;
float minimalEnemySizeY = 20;

float maximalEnemySizeX = 70;
float maximalEnemySizeY = 40;

float minimalBallSize = 20;
float maximalBallSize = 40;

int main() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);

    //initialise the variables
    GameHandler::startGame();

    //initialises the window
    raylib::Window window(screenWidth, screenHeight, "BallKiller3000 v" BALL_KILLER_VERSION);

    SetExitKey(KEY_NULL); // Disable exit key, replace it with a pause menu
    window.SetTargetFPS(60);

    // main game loop (executes every frame)
    while (!window.ShouldClose()) {
        if (screenWidth != window.GetRenderWidth()) {
            Gui::resizeWindow();
        }
        if (screenHeight != window.GetRenderHeight()) {

            Gui::resizeWindow();
        }

        //fetch pause button
        if (IsKeyPressed(KEY_ESCAPE) && !isGameOver && hasGameStarted) {
            if (!isGamePaused) {
                isGamePaused = true;
            } else {
                isGamePaused = false;
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        Gui::renderGameGui();

        if (hasGameStarted) {
            Gui::renderGameContent();
        } else { Gui::renderStartScreen(); }

        if(isGamePaused){
            Gui::renderPauseMenu();
        }

        // move the player
        if (hasGameStarted && !isGamePaused) {
            if (!isGameOver) {
                Gui::renderControlStick();
                Pos::getPlayerMoveInput();
            } else {
                Gui::renderGameOver();
            }
        }


        EndDrawing();

        if (hasGameStarted && !isGamePaused) {
            EnemyAi::generateMove();
        }
    }

    return 0;
}