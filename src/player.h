#ifndef BALLKILLER3000_PLAYER_H
#define BALLKILLER3000_PLAYER_H

#include "raylib-cpp.hpp"

// fix the circular thing
class Ball;

class Enemy;

class Player {
private:
    void checkCollisionWithBalls();

public:
    int playerNumber = -1;
    float size = 20;
    float speed = 3;

    raylib::Vector2 pos;

    int score = 0;
    int highScore = 0;
    int lives = 2;

    bool isDead = false;

    raylib::Color colour = RED;
    raylib::Color deadColour = GRAY;
    raylib::Color controlStickBaseColour = ColorAlpha(GRAY, 0.75);
    raylib::Color controlStickDragColour = ColorAlpha(BLACK, 0.75);


    bool hasCollision(Ball ballToCheck);

    bool hasCollision(Enemy enemyToCheck);

    bool hasCollision(Player playerToCheck);

    int getNearestBall();

    int getNearestEnemy();

    int getNearestPlayer();

    void getMove();

    bool isInScreen(Vector2 posToCheck);

    bool isInScreen() {
        return isInScreen(pos);
    }

    void move(Vector2 moveTo);

};

#endif
