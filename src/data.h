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
extern int *enemyPreference;

extern bool isGameOver;



#endif
