#include "../gui.h"
#include "../data.h"
#include "../pos.h"

void Gui::resizeWindow() {
    //reset screenHeights and withs
    screenWidth = GetRenderWidth();
    screenHeight = GetRenderHeight();

    // reset all the positions
    playerPos[0] = Vector2(screenWidth / 2, screenHeight / 2);
    playerPos[1] = Vector2(-1000, -1000);

    if (isGameMultiPlayerGame) {
        playerPos[0] = Vector2(screenWidth / 2 - 60, screenHeight / 2);
        playerPos[1] = Vector2(screenWidth / 2 + 60, screenHeight / 2);
    }

    for (int b = 0; b < ballsInScreen; ++b) {
        ballPos[b] = Pos::generateRandomPos(Data::ball);
    }
    for (int e = 0; e < enemiesInScreen; ++e) {
        enemies[e].pos = Pos::generateRandomPos(Data::enemy);
    }

}