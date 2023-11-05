#include "../ball.h"
#include "../enemy.h"
#include "../player.h"
#include "../data.h"
#include "../utils.h"
#include "raylib-cpp.hpp"

int Utils::getNearestBall(raylib::Vector2 pos, bool ignoreAlmostDead, int ignoreNumber) {
    int closestBall = -1;
    float closestDistance = 1000; // there will be always one closer
    float distance;

    for (int b = 0; b < ballCount; ++b) {
        if (b != ignoreNumber) {
            if (ignoreAlmostDead) {
                if (ball[b].pos.x > 30 && ball[b].pos.x < screenWidth - 30 && ball[b].pos.y > 30 &&
                    ball[b].pos.y < screenHeight - 30) {
                    if (!ball[b].isDead) {

                        distance = pos.Distance(ball[b].pos);
                        if (distance <= closestDistance) {
                            closestDistance = distance;
                            closestBall = b;
                        }
                    }
                }
            }
            else{ if (ball[b].pos.x > 0 && ball[b].pos.x < screenWidth  && ball[b].pos.y > 0 &&
                      ball[b].pos.y < screenHeight ) {
                    if (!ball[b].isDead) {

                        distance = pos.Distance(ball[b].pos);
                        if (distance <= closestDistance) {
                            closestDistance = distance;
                            closestBall = b;
                        }
                    }
                }}
        }
    }
    return closestBall;
}

int Utils::getNearestEnemy(raylib::Vector2 pos, int ignoreNumber) {
    int closestEnemy = -1;
    float closestDistance = 1000; // there will be always one closer
    float distance;

    for (int e = 0; e < enemyCount; ++e) {
        if (e != ignoreNumber) {
            if (!enemy[e].isDead) {

                distance = pos.Distance(enemy[e].pos);
                if (distance <= closestDistance) {
                    closestDistance = distance;
                    closestEnemy = e;
                }

            }
        }
    }
    return closestEnemy;
}

int Utils::getNearestPlayer(raylib::Vector2 pos, int ignoreNumber) {
    int closestPlayer = -1;
    float closestDistance = 1000; // there will be always one closer
    float distance;

    for (int p = 0; p < playerCount; ++p) {
        if (p != ignoreNumber) {
            distance = pos.Distance(player[p].pos);
            if (distance <= closestDistance) {
                closestDistance = distance;
                closestPlayer = p;

            }
        }
    }
    return closestPlayer;
}

int Ball::getNearestBall() {
    return Utils::getNearestBall(pos, ballNumber);
}

int Ball::getNearestEnemy() {
    return Utils::getNearestEnemy(pos);
}

int Ball::getNearestPlayer() {
    return Utils::getNearestPlayer(pos);
}

int Enemy::getNearestBall() {
    return Utils::getNearestBall(pos, true);
}

int Enemy::getNearestEnemy() {
    return Utils::getNearestEnemy(pos, enemyNumber);
}

int Enemy::getNearestPlayer() {
    return Utils::getNearestPlayer(pos);
}

int Player::getNearestBall() {
    return Utils::getNearestBall(pos);
}

int Player::getNearestEnemy() {
    return Utils::getNearestEnemy(pos);
}

int Player::getNearestPlayer() {
    return Utils::getNearestPlayer(pos, playerNumber);
}
