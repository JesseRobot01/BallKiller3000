#include "../gui.h"
#include "../data.h"
#include "../gameHandler.h"
#include "raylib-cpp.hpp"

void Gui::renderGameOver() {
    // The game over screen
    DrawRectangle(0, 0, screenWidth, screenHeight, ColorAlpha(GRAY, 0.625));

    raylib::DrawText("Game Over!!!", screenWidth / 2 - 3 * 60, screenHeight / 2 - 30, 60, RED);
    raylib::DrawText("Press enter to restart", screenWidth / 2 - 3 * 60 - 10, screenHeight / 2 + 30, 30, RED);
    if (IsKeyPressed(KEY_ENTER)) GameHandler::startGame();


    // draws a restart button
    raylib::Rectangle restartButton(screenWidth / 2 - MeasureText("Restart", 30) / 2 - 10, screenHeight / 2 + 65,
                                    MeasureText("Restart", 30) + 20, 50);
    DrawRectangleRec(restartButton, ColorAlpha(RED, 0.25));

    raylib::DrawText("Restart", screenWidth / 2 - MeasureText("Restart", 30) / 2, screenHeight / 2 + 75,
                     30, RED);

    if (IsGestureDetected(GESTURE_TAP) &&
        CheckCollisionPointRec(GetMousePosition(),
                               restartButton)) {
        GameHandler::startGame();
    }
}