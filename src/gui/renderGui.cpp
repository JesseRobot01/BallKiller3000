#include "../gui.h"
#include "../data.h"
#include "../gameHandler.h"
#include "version.h"
#include "raylib-cpp.hpp"

void Gui::renderDefaultScreen() {

    // renders the balls, enemies and the player
    for (int b = 0; b < ballCount; ++b) {
        DrawCircleV(ballPos[b], 30, BLUE);
    }
    for (int e = 0; e < enemyCount; ++e) {
        DrawRectangleV(enemyPos[e], enemySize[e], YELLOW);


    }
    DrawCircleV(playerPos, 20, RED);

    raylib::DrawText("Lives: " + std::to_string(lives), 20, 10, 20, RED);
    raylib::DrawText("Score: " + std::to_string(score), 140, 10, 20, RED);
    raylib::DrawText("High: " + std::to_string(highScore), 260, 10, 20, RED);
    raylib::DrawText("Level: " + std::to_string(level), 380, 10, 20, RED);
    raylib::DrawText("v"  BALL_KILLER_VERSION, screenWidth - (std::string(BALL_KILLER_VERSION).length() * 5) - 10,
                     screenHeight - 15, 10, GRAY);

    // The game over screen
    if (isGameOver) {
        raylib::DrawText("Game Over!!!", screenWidth / 2 - 3 * 60, screenHeight / 2 - 30, 60, RED);
        raylib::DrawText("Press enter to restart", screenWidth / 2 - 3 * 60 - 10, screenHeight / 2 + 30, 30, RED);
        if (IsKeyPressed(KEY_ENTER)) GameHandler::startGame();

        // draws a restart button
        DrawRectangle(GetRenderWidth() / 2 - MeasureText("Restart", 30) / 2 - 10, GetRenderHeight() / 2 + 65,
                      MeasureText("Restart", 30) + 20, 50, ColorAlpha(RED, 0.25));

        raylib::DrawText("Restart", GetRenderWidth() / 2 - MeasureText("Restart", 30) / 2, GetRenderHeight() / 2 + 75,
                         30, RED);

        if (IsGestureDetected(GESTURE_TAP) &&
            CheckCollisionPointRec(GetMousePosition(),
                                   Rectangle(GetRenderWidth() / 2 - MeasureText("Restart", 30) / 2 - 10,
                                             GetRenderHeight() / 2 + 65,
                                             MeasureText("Restart", 30) + 20, 50))) {
            GameHandler::startGame();
        }
    }
}

void Gui::renderControlStick() {
    if (IsGestureDetected(GESTURE_DRAG)) {
        if (!isTouchingScreen) {
            controlStickStartPos = GetMousePosition();
            isTouchingScreen = true;
        }
        controlStickCurrentPos = controlStickStartPos.MoveTowards(GetMousePosition(), 50);

        DrawCircleV(controlStickStartPos, 50, ColorAlpha(GRAY, 0.75));
        DrawCircleV(controlStickCurrentPos, 30, ColorAlpha(BLACK, 0.75));
    } else {
        isTouchingScreen = false;
    }
};
