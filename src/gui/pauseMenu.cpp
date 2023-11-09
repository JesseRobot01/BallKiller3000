#include "../data.h"
#include "../gui.h"
#include "../gameHandler.h"

void Gui::pauseMenu() {
    // Define button sizes
    raylib::Rectangle continueButton(screenWidth / 2 - (float) MeasureText("Continue", 30) - 10,
                                     screenHeight / 2 + 35,
                                     (float) MeasureText("Continue", 30) + 20, 50);

    raylib::Rectangle quitButton(screenWidth / 2 + 30 - 10,
                                 screenHeight / 2 + 35,
                                 (float) MeasureText("Continue", 30) + 20, 50);

    raylib::Rectangle settingsButton(screenWidth / 2 - (float) MeasureText("Continue", 30) - 10,
                                     screenHeight / 2 + 100,
                                     (float) MeasureText("Continue", 30) * 2 + 50, 50);

    // Draw the elements
    // Draw the background
    DrawRectangle(0, 0, (int) screenWidth, (int) screenHeight, ColorAlpha(GRAY, 0.625));

    // Draw text
    raylib::DrawText("Pause", (int) screenWidth / 2 - MeasureText("Pause", 60) / 2,
                     (int) screenHeight / 2 - 50,
                     60, RED);

    DrawRectangleRec(continueButton, ColorAlpha(RED, 0.25));
    DrawRectangleRec(quitButton, ColorAlpha(RED, 0.25));
    DrawRectangleRec(settingsButton, ColorAlpha(RED, 0.25));


    raylib::DrawText("Continue",
                     (int) screenWidth / 2 - MeasureText("Continue", 30),
                     (int) screenHeight / 2 + 45,
                     30, RED);

    raylib::DrawText("Quit",
                     (int) screenWidth / 2 - MeasureText("Quit", 30) / 2 +
                     MeasureText("Continue", 30) / 2 + 30,
                     (int) screenHeight / 2 + 45,
                     30, RED);

    raylib::DrawText("Settings", (int) screenWidth / 2 - MeasureText("Continue", 30) - 10 +
                                 (MeasureText("Continue", 30) * 2 + 50 -
                                  MeasureText("Settings", 30)) / 2, (int) screenHeight / 2 + 110, 30, RED);

    //handle buttons
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) &&
        CheckCollisionPointRec(GetMousePosition(),
                               continueButton)) {

        isGamePaused = false;
    }
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) &&
        CheckCollisionPointRec(GetMousePosition(),
                               quitButton)) {
        isGameActive = false;
        isGamePaused = false;
        frameCounter = 0; // Resets the counter to start a new AI game

        if (playerCount == 2) {
            for (int p = 0; p < playerCount; ++p) {
                if (player[p].score > player[p].highScore) GameHandler::saveHigh(player[p].score, true, p);
            }
        } else if (player[0].score > player[0].highScore) GameHandler::saveHigh(player[0].score);
    }
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) &&
        CheckCollisionPointRec(GetMousePosition(), settingsButton)) { isSettingsPageShown = true; }

}