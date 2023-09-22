#include "../data.h"
#include "../gui.h"

void Gui::gameOverlay() {
    for (int p = 0; p < playerCount; ++p) {
        raylib::DrawText("Lives: " + std::to_string(player[p].lives), 20, p * 30 + 10, 20, player[p].colour);
        raylib::DrawText("Score: " + std::to_string(player[p].score), 140, p * 30 + 10, 20, player[p].colour);
        raylib::DrawText("High: " + std::to_string(player[p].highScore), 260, p * 30 + 10, 20, player[p].colour);
    }

    raylib::DrawText("Level: " + std::to_string(level), 380, 10, 20, RED);
}