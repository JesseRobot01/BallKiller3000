#ifndef BALLKILLER3000_DATA_H
#define BALLKILLER3000_DATA_H

#include "raylib-cpp.hpp"


class Data {

public:
    enum Types {
        player, ball, enemy
    };

    enum Directions {
        up, down, left, right
    };

    enum Axis {
        x, y
    };


};

extern int screenWidth;
extern int screenHeight;

extern raylib::Vector2 playerPos[2];
extern raylib::Vector2 *ballPos;
extern raylib::Vector2 *enemyPos;
extern raylib::Vector2 *enemySize;
extern float moveSpeed;

extern int score[2];
extern int highScore;
extern int lives[2];
extern int level;
extern int ballsInScreen;
extern int ballCount;
extern int enemyCount;
extern int enemiesInScreen;
extern int *enemyPreference;
extern float *ballSize;

extern bool isGameOver;
extern bool hasGameStarted;
extern bool isGamePaused;
extern bool isGameMultiPlayerGame;

extern bool isTouchingScreen[2];
extern bool isControlStickBasePlayer;
extern raylib::Vector2 controlStickStartPos[2];
extern raylib::Vector2 controlStickCurrentPos[2];

extern float playerSize[2];
extern float minimalEnemySizeX;
extern float minimalEnemySizeY;
extern float maximalEnemySizeX;
extern float maximalEnemySizeY;
extern float minimalBallSize;
extern float maximalBallSize;

#endif
