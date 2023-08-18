#include "../gui.h"
#include "../data.h"
#include "raylib-cpp.hpp"

void Gui::renderGameContent() {
    // renders the balls, enemies and the player
    for (int b = 0; b < ballCount; ++b) {
        DrawCircleV(ballPos[b], ballSize[b], BLUE);
    }
    for (int e = 0; e < enemyCount; ++e) {
        DrawRectangleV(enemies[e].pos, enemySize[e], YELLOW);


    }
    DrawCircleV(playerPos[0], playerSize[0], RED);

    if (isGameMultiPlayerGame) {
        DrawCircleV(playerPos[1], playerSize[1], GREEN);
    }
}