#include "../gui.h"
#include "../data.h"
#include "version.h"
#include "raylib-cpp.hpp"

void Gui::renderGameGui() {

    if (!isGameMultiPlayerGame) {
        raylib::DrawText("Lives: " + std::to_string(lives[0]), 20, 10, 20, RED);
        raylib::DrawText("Score: " + std::to_string(score[0]), 140, 10, 20, RED);
        raylib::DrawText("High: " + std::to_string(highScore), 260, 10, 20, RED);
        raylib::DrawText("Level: " + std::to_string(level), 380, 10, 20, RED);
    }
    if (isGameMultiPlayerGame) {
        raylib::DrawText("Lives: " + std::to_string(lives[0]), 20, 10, 20, RED);
        raylib::DrawText("Lives: " + std::to_string(lives[1]), 20, 40, 20, GREEN);

        raylib::DrawText("Score: " + std::to_string(score[0]), 140, 10, 20, RED);
        raylib::DrawText("Score: " + std::to_string(score[1]), 140, 40, 20, GREEN);

        raylib::DrawText("High: " + std::to_string(highScore), 260, 10, 20, RED);
        raylib::DrawText("Level: " + std::to_string(level), 380, 10, 20, RED);
    }
    raylib::DrawText("v"  BALL_KILLER_VERSION, screenWidth - (std::string(BALL_KILLER_VERSION).length() * 5) - 10,
                     screenHeight - 15, 10, GRAY);

}