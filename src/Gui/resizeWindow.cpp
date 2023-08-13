#include "../gui.h"
#include "../data.h"
#include "../pos.h"

void Gui::resizeWindow() {
    //reset screenHeights and withs
    screenWidth = GetRenderWidth();
    screenHeight = GetRenderHeight();

    // reset all the positions
    playerPos = Vector2(screenWidth / 2, screenHeight / 2);

    for (int b = 0; b < ballsInScreen; ++b) {
        ballPos[b] = Pos::generateRandomPos(Data::ball);
    }
    for (int e = 0; e < enemiesInScreen; ++e) {
        enemyPos[e] = Pos::generateRandomPos(Data::enemy);
    }

}