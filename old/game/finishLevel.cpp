#include "../player.h"
#include "../data.h"


void Player::finishesLevel() {
    ballCount++;
    enemyCount++;
    ballsOnScreen = ballCount;
    isBallPosGenerated = false;
    isEnemyPosGenerated = false;
}