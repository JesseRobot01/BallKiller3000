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

extern raylib::Vector2 playerPos;
extern raylib::Vector2 *ballPos;
extern raylib::Vector2 *enemyPos;
extern raylib::Vector2 *enemySize;
extern float moveSpeed;

extern int score;
extern int highScore;
extern int lives;
extern int level;
extern int ballsInScreen;
extern int ballCount;
extern int enemyCount;
extern int enemiesInScreen;
extern int *enemyPreference;
extern float *ballSize;

extern bool isGameOver;

extern bool isTouchingScreen;
extern bool isControlStickBasePlayer;
extern raylib::Vector2 controlStickStartPos;
extern raylib::Vector2 controlStickCurrentPos;

extern float playerSize;
extern float minimalEnemySizeX;
extern float minimalEnemySizeY;
extern float maximalEnemySizeX;
extern float maximalEnemySizeY;
extern float minimalBallSize;
extern float maximalBallSize;

#endif
