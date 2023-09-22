#include "../data.h"
#include "../gui.h"

void Gui::gameElements() {
    // Draw the balls
    for (int b = 0; b < ballCount; ++b) {
        if (!ball[b].isDead)
            DrawCircleV(ball[b].pos, ball[b].size, ball[b].colour);
    }
    // Draw the enemies
    for (int e = 0; e < enemyCount; ++e) {
        if (!enemy[e].isDead)
            DrawRectangleV(enemy[e].pos, enemy[e].size, enemy[e].colour);
    }
    // Draw the players
    for (int p = 0; p < playerCount; p++) {
        DrawCircleV(player[p].pos, player[p].size, player[p].isDead ? player[p].deadColour : player[p].colour);
    }
}