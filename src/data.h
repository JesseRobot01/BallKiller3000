#ifndef BALLKILLER3000_DATA_H
#define BALLKILLER3000_DATA_H

#include "raylib-cpp.hpp"
#include "enemy.h"


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
extern float moveSpeed;

extern int score[2];
extern int highScore;
extern int lives[2];
extern int level;
extern int ballsInScreen;
extern int ballCount;
extern int enemiesInScreen;
extern float *ballSize;
extern int enemyCount;
extern bool isGameOver;
extern bool hasGameStarted;
extern bool isGamePaused;
extern bool isGameMultiPlayerGame;

extern bool isTouchingScreen[2];
extern bool isControlStickBasePlayer;
extern raylib::Vector2 controlStickStartPos[2];
extern raylib::Vector2 controlStickCurrentPos[2];

extern float playerSize[2];
extern float minimalBallSize;
extern float maximalBallSize;

extern Enemy *enemies;

#endif
