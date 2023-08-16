#include "../utils.h"
#include "../data.h"
#include "../pos.h"

/**
 * Find the nearest x in a specific pos.
 *
 * @param findNearest What to find.
 * @param pos The pos to start looking for.
 * @param ignoreNumber A number to ignore, useful for when the given pos is an enemy pos and you need to find the nearest enemy
 *
 * @example Utils::getNearest(Data::enemy, enemyPos[3], 3);
 * @return The nearest enemy number from the given pos (except 3).
 */
int Utils::getNearest(Data::Types findNearest, raylib::Vector2 pos, int ignoreNumber) {
    int closestNumber = -1;
    float closestDistance = 1000;
    float distance;

    if (findNearest == Data::enemy) {
        for (int e = 0; e < enemyCount; ++e) {
            if (e != ignoreNumber) {
                if (Pos::isPosSafePos(enemyPos[e])) {

                    distance = pos.Distance(enemyPos[e]);
                    if (distance < closestDistance) {
                        closestDistance = distance;
                        closestNumber = e;
                    }
                }
            }
        }
    }
    if (findNearest == Data::ball) {
        for (int b = 0; b < ballCount; ++b) {
            if (b != ignoreNumber) {
                if (Pos::isPosSafePos(ballPos[b])) {

                    distance = pos.Distance(ballPos[b]);
                    if (distance <= closestDistance) {
                        closestDistance = distance;
                        closestNumber = b;
                    }
                }
            }
        }
    }
    if (findNearest == Data::player) {
        if (!isGameMultiPlayerGame) return 0; // no need to scan if the second player isn't present
        else {
            for (int p = 0; p < 1; ++p) {
                if (p != ignoreNumber) {
                    distance = pos.Distance(playerPos[p]);
                    if (distance <= closestDistance) {
                        closestDistance = distance;
                        closestNumber = p;
                    }
                }
            }
        }
    }

    return closestNumber;
}