#ifndef BALLKILLER3000_PLAYER_H
#define BALLKILLER3000_PLAYER_H

#include "raylib-cpp.hpp"

// fix the circular thing
class Ball;

class Enemy;

class Player {
private:
    void checkCollisionWithBalls();

    raylib::Vector2 getTouchPointMove();

    void updateTouchPoints();

    raylib::Vector2 getMouseMove();

    static int getWantedPlayer(raylib::Vector2 posToCheck);

    raylib::Vector2 getKeyboardMove() const;

    void generateAIMove();

public:
    int playerNumber = -1;
    float size = 20;
    float speed = 3;

    raylib::Vector2 pos;

    int score = 0;
    int highScore = 0;
    int lives = 2;

    bool isDead = false;
    bool isAi = false;

    raylib::Color colour = RED;
    raylib::Color deadColour = GRAY;
    raylib::Color controlStickBaseColour = ColorAlpha(GRAY, 0.75);
    raylib::Color controlStickDragColour = ColorAlpha(BLACK, 0.75);

    bool isTouchingScreen;
    bool isControlStickBasePlayer = false;
    bool isUsingMouse;
    int touchPointIndex;
    raylib::Vector2 controlStickStartPos;
    raylib::Vector2 controlStickCurrentPos;

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
