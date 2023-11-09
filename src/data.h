#ifndef BALLKILLER3000_DATA_H
#define BALLKILLER3000_DATA_H

#include "player.h"
#include "ball.h"
#include "enemy.h"

// window
extern float screenWidth;
extern float screenHeight;


// game states
extern bool isGameActive;
extern bool isGamePaused;
extern bool isGameOver;
extern bool isGameAiGame;
extern bool isSettingsPageShown;

extern int level;

extern int knownTouchPoints;
extern int frameCounter;

extern bool controlStickEnabled;
extern bool dragEnabled;
extern float dragSensitivity;

// entities
extern Player *player;
extern Ball *ball;
extern Enemy *enemy;

extern int playerCount;
extern int ballCount;
extern int ballsInScreen;
extern int enemyCount;
extern int enemiesInScreen;

#endif
