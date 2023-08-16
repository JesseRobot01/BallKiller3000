#include "../gui.h"
#include "../data.h"
#include "../gameHandler.h"
#include "raylib-cpp.hpp"

void Gui::renderPauseMenu() {
    // old background, Maybe it will ever be useful, so I kept it in, disabled
    // DrawRectangle(screenWidth / 2 - MeasureText("Continue", 30) - 40, screenHeight / 2 - 80,MeasureText("Continue", 30) * 2 + 20 + 90,50 + 60 + 30 + 60, ColorAlpha(GRAY, 0.625));

    DrawRectangle(0, 0, screenWidth, screenHeight, ColorAlpha(GRAY, 0.625));

    raylib::DrawText("Pause", screenWidth / 2 - MeasureText("Pause", 60) / 2, screenHeight / 2 - 50, 60, RED);

    raylib::Rectangle continueButton(screenWidth / 2 - MeasureText("Continue", 30) - 10,
                                     screenHeight / 2 + 35,
                                     MeasureText("Continue", 30) + 20, 50);

    raylib::Rectangle quitButton(screenWidth / 2 - 10 + 30,
                                 screenHeight / 2 + 35,
                                 MeasureText("Continue", 30) + 20, 50);

    DrawRectangleRec(continueButton, ColorAlpha(RED, 0.25));
    DrawRectangleRec(quitButton, ColorAlpha(RED, 0.25));

    raylib::DrawText("Continue", screenWidth / 2 - MeasureText("Continue", 30),
                     screenHeight / 2 + 45,
                     30, RED);

    raylib::DrawText("Quit",
                     screenWidth / 2 - MeasureText("Quit", 30) / 2 + MeasureText("Continue", 30) / 2 + 30,
                     screenHeight / 2 + 45,
                     30, RED);


    if (IsGestureDetected(GESTURE_TAP) &&
        CheckCollisionPointRec(GetMousePosition(),
                               continueButton)) {
        isGamePaused = false;
    }

    if (IsGestureDetected(GESTURE_TAP) &&
        CheckCollisionPointRec(GetMousePosition(),
                               quitButton)) {
        GameHandler::saveHigh();
        CloseWindow();
    }

}