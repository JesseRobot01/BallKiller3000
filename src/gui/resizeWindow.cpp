#include "../gui.h"
#include "../data.h"

void Gui::resizeWindow() {
    // Reset screenHeights and widths
    screenWidth = (float) GetRenderWidth();
    screenHeight = (float) GetRenderHeight();

    // reset the positions
    for (int p = 0; p < playerCount; ++p) {
        player[p].pos = Vector2(screenWidth / 2, screenHeight / 2);

        if (playerCount == 2) {
            if (p == 0) {
                player[p].pos = Vector2(screenWidth / 2 - 60, screenHeight / 2);
            } else if (p == 1) {
                player[p].pos = Vector2(screenWidth / 2 + 60, screenHeight / 2);
            }
        }
    }

    for (int b = 0; b < ballCount; ++b) {
        ball[b].initialise();
    }
    for (int e = 0; e < enemyCount; ++e) {
        enemy[e].initialise();
    }
}