#include "../gui.h"
#include "../data.h"
#include "../gameHandler.h"
#include "raylib-cpp.hpp"

void Gui::renderStartScreen() {
    DrawRectangle(0, 0, screenWidth, screenHeight, ColorAlpha(GRAY, 0.625));

    raylib::DrawText("BallKiller3000", screenWidth / 2 - MeasureText("BallKiller3000", 60) / 2, screenHeight / 2 - 50,
                     60, RED);
    raylib::DrawText("By JesseRobot01", screenWidth / 2 - MeasureText("By JesseRobot01", 15) / 2, screenHeight / 2 + 10,
                     15, GRAY);

    raylib::Rectangle singlePlayerButton(screenWidth / 2 - MeasureText("Single-Player", 30) - 10,
                                         screenHeight / 2 + 35,
                                         MeasureText("Single-Player", 30) + 20, 50);

    raylib::Rectangle multiPlayerButton(screenWidth / 2 + 30 - 10,
                                        screenHeight / 2 + 35,
                                        MeasureText("Single-Player", 30) + 20, 50);


    DrawRectangleRec(singlePlayerButton, ColorAlpha(RED, 0.25));
    DrawRectangleRec(multiPlayerButton, ColorAlpha(RED, 0.25));

    raylib::DrawText("Single-Player", screenWidth / 2 - MeasureText("Single-Player", 30), screenHeight / 2 + 45,
                     30, RED);

    raylib::DrawText("Multi-Player",
                     screenWidth / 2 - MeasureText("Multi-Player", 30) / 2 + MeasureText("Single-Player", 30) / 2 + 30,
                     screenHeight / 2 + 45,
                     30, RED);

    if (IsGestureDetected(GESTURE_TAP) &&
        CheckCollisionPointRec(GetMousePosition(),
                               singlePlayerButton)) {
        isGameMultiPlayerGame = false;
        hasGameStarted = true;
        GameHandler::startGame();
    }
    if (IsGestureDetected(GESTURE_TAP) &&
        CheckCollisionPointRec(GetMousePosition(),
                               multiPlayerButton)) {
        isGameMultiPlayerGame = true;
        hasGameStarted = true;
        GameHandler::startGame();
    }
}
