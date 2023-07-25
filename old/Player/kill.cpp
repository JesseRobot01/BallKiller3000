#include "../player.h"
#include "../data.h"
#include "../score.h"


void Player::kill() {
    liveCount--;
    if (liveCount == 0) {
        isGameOver = true;
        Score::saveHigh(scoreCount);
    }
}