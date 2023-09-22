#include "../data.h"
#include "../gui.h"
#include "../gameHandler.h"

void Gui::startScreen() {
    // Define button sizes
    raylib::Rectangle singlePlayerButton(screenWidth / 2 - (float) MeasureText("Single-Player", 30) - 10,
                                         screenHeight / 2 + 35,
                                         (float) MeasureText("Single-Player", 30) + 20, 50);

    raylib::Rectangle multiPlayerButton(screenWidth / 2 + 30 - 10,
                                        screenHeight / 2 + 35,
            // Yes, I know, multi-player button has single-player in its code, but this makes it the same size.
                                        (float) MeasureText("Single-Player", 30) + 20, 50);

    // Draw the elements
    // Draw the background
    DrawRectangle(0, 0, (int) screenWidth, (int) screenHeight, ColorAlpha(GRAY, 0.625));

    // Draw text
    raylib::DrawText("BallKiller3000", (int) screenWidth / 2 - MeasureText("BallKiller3000", 60) / 2,
                     (int) screenHeight / 2 - 50,
                     60, RED);
    raylib::DrawText("By JesseRobot01", (int) screenWidth / 2 - MeasureText("By JesseRobot01", 15) / 2,
                     (int) screenHeight / 2 + 10,
                     15, GRAY);

    DrawRectangleRec(singlePlayerButton, ColorAlpha(RED, 0.25));
    DrawRectangleRec(multiPlayerButton, ColorAlpha(RED, 0.25));

    raylib::DrawText("Single-Player",
                     (int) screenWidth / 2 - MeasureText("Single-Player", 30),
                     (int) screenHeight / 2 + 45,
                     30, RED);

    raylib::DrawText("Multi-Player",
                     (int) screenWidth / 2 - MeasureText("Multi-Player", 30) / 2 +
                     MeasureText("Single-Player", 30) / 2 + 30,
                     (int) screenHeight / 2 + 45,
                     30, RED);


    // Handles Buttons
    if (IsGestureDetected(GESTURE_TAP) &&
        CheckCollisionPointRec(GetMousePosition(),
                               singlePlayerButton)) {

        GameHandler::startGame();
    }
    if (IsGestureDetected(GESTURE_TAP) &&
        CheckCollisionPointRec(GetMousePosition(),
                               multiPlayerButton)) {
        GameHandler::startGame(true);
    }
}