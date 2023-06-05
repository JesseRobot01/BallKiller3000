#ifndef BALL_KILLER_DATA_H
#define BALL_KILLER_DATA_H
// I put everything in a seperated file to keep things clean end easy to maintain

extern int moveSpeed;
extern const int screenWidth;
extern const int screenHeight;
extern int playerPosX;
extern int playerPosY;
extern int ballCount;
extern int *ballPosX;
extern int *ballPosY;
extern int ballsOnScreen;
extern bool isBallPosGenerated;
extern bool isEnemyPosGenerated;
extern int liveCount;
extern bool isGameOver;
extern int scoreCount;
extern int enemyCount;
extern int *enemyPosX;
extern int *enemyPosY;
extern int highScore;
extern int *enemyPreference;

#endif
