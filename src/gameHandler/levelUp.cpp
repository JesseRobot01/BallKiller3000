#include "../gameHandler.h"
#include "../data.h"
#include "../utils.h"
#include <iostream>


void GameHandler::levelUp() {
    if (isGameOver) return; // don't level up if the game is over.
    delete[] ball;
    delete[] enemy;
    level++;
    if (level % 2) {
        for (int p = 0; p < playerCount; ++p) {
            player[p].lives++;
            if (player[p].lives > 0) player[p].isDead = false; //give back live
        }
    }

    ballCount = level + 2;
    enemyCount = level;
    ballsInScreen = ballCount;
    enemiesInScreen = enemyCount;

    ball = new Ball[ballCount];
    enemy = new Enemy[enemyCount];


    // generate random ball and enemy pos
    for (int b = 0; b < ballCount; ++b) {
        ball[b].ballNumber = b;
        ball[b].initialise();
    }
    for (int e = 0; e < enemyCount; ++e) {
        enemy[e].enemyNumber = e;
        enemy[e].initialise();
    }

    int tries;
    // now fix collisions
    // this code does not fix collision 100%, but it reduces it.
    for (int a = 0; a < ballCount; ++a) {
        for (int b = 0; b < ballCount; ++b) {
            tries = 0;
            while (ball[a].hasCollision(ball[b]) && tries < 100) {
                ball[b].initialise(); // just reinitialise
                tries++;
            }
        }
    }
    for (int a = 0; a < enemyCount; ++a) {
        for (int b = 0; b < enemyCount; ++b) {
            tries = 0;
            while (enemy[a].hasCollision(enemy[b]) && tries < 100) {
                enemy[b].initialise(); // just reinitialise
                tries++;
            }
        }
    }

    // now ball-enemy
    for (int a = 0; a < ballCount; ++a) {
        for (int b = 0; b < enemyCount; ++b) {
            tries = 0;
            while (ball[a].hasCollision(enemy[b]) && tries < 100) {
                ball[a].initialise(); // just reinitialise
                tries++;
            }
        }
    }
}
