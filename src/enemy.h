#ifndef BALLKILLER3000_ENEMY_H
#define BALLKILLER3000_ENEMY_H

#include "raylib-cpp.hpp"


// fix the circular thing
class Ball;

class Player;


class Enemy {
private:
    raylib::Vector2 generateRandomPos();

    void generateNeutralMove();

    void generateBallFindMove();

    void generateEnemyFindMove();

    void generatePlayerFindMove();

    void move(Vector2 moveTo, bool isGettingPushed = false);

    void rotate();

public:
    int enemyNumber = -1;

    raylib::Vector2 pos;
    raylib::Vector2 size;

    float speed = 30;

    bool isDead = false;

    float minimalSizeX = 50;
    float minimalSizeY = 20;
    float maximaSizeX = 70;
    float maximalSizeY = 40;

    void initialise();

    enum aiTypes {
        neutral,
        ballPreference,
        enemyPreference,
        playerPreference
    };

    aiTypes enemyAI;

    Color colour = YELLOW;

    bool hasCollision(Ball ballToCheck);

    bool hasCollision(Enemy enemyToCheck);

    bool hasCollision(Player playerToCheck);

    bool isInScreen(Vector2 posToCheck);

    int getNearestBall();

    int getNearestEnemy();

    int getNearestPlayer();

    bool isInScreen() {
        return isInScreen(pos);
    }

    void generateMove();


};

#endif
