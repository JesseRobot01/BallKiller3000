#include "../score.h"
#include "../data.h"

void Score::checkIfExtraLife() {
    if (scoreCount % 10 == 0) {
        liveCount++;
    }
}