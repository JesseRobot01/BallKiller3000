#include <iostream>
#include "raylib-cpp.hpp"
#include "game.h"
#include "score.h"
#include "data.h"
#include "version.h"

// the variables
int screenWidth = 800;
int screenHeight = 450;

Vector2 playerPos;
float moveSpeed = 3;
int liveCount;
int scoreCount;
int highScore;

raylib::Vector2 *ballPos = new raylib::Vector2[1];;
int ballCount;
int ballsOnScreen;


Vector2 *enemyPos = new Vector2[1];
int enemyCount;
int *enemyPreference = new int[99];

bool isBallPosGenerated;
bool isEnemyPosGenerated;
bool isGameOver;


int main() {
    // initializes the variables
    Game::startGame();
    Score::loadHigh;

    // initializes the window
    raylib::Window window(screenWidth, screenHeight, "BallKiller v"  BALL_KILLER_VERSION);
    SetTargetFPS(60);

    while (!window.ShouldClose()) {
        ClearBackground(RAYWHITE);
    }


}