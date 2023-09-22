#ifndef BALLKILLER3000_BALL_H
#define BALLKILLER3000_BALL_H

#include "raylib-cpp.hpp"

// fix the circular thing
class Enemy;

class Player;

class Ball {
private:
    raylib::Vector2 generateRandomPos();

public:
    int ballNumber = -1;

    raylib::Vector2 pos;
    float size = 30;

    float minimalSize = 20;
    float maximalSize = 40;

    void initialise();

    Color colour = BLUE;

    bool isDead = false;

    bool hasCollision(Ball ballToCheck);

    bool hasCollision(Enemy enemyToCheck);

    bool hasCollision(Player playerToCheck);

    int getNearestBall();

    int getNearestEnemy();

    int getNearestPlayer();

    bool isInScreen(Vector2 posToCheck);

    bool isInScreen() {
        return isInScreen(pos);
    }

    void move(Vector2 moveTo);
};

#endif
