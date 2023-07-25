#ifndef BALL_KILLER_DATA_H
#define BALL_KILLER_DATA_H

#include "raylib-cpp.hpp"
// I put everything in a seperated file to keep things clean end easy to maintain

extern int screenWidth;
extern int screenHeight;
extern Vector2 playerPos;
extern float moveSpeed;
extern int liveCount;
extern int scoreCount;
extern int highScore;
extern raylib::Vector2 *ballPos;;
extern int ballCount;
extern int ballsOnScreen;
extern Vector2 *enemyPos;
extern int enemyCount;
extern int *enemyPreference;
extern bool isBallPosGenerated;
extern bool isEnemyPosGenerated;
extern bool isGameOver;


#endif
