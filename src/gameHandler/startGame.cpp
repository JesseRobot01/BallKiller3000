#include <iostream>
#include "../gameHandler.h"
#include "../data.h"

void GameHandler::startGame(bool multiPlayerGame) {
    // Activate game
    isGameActive = true;
    isGameOver = false;

    level = 0;

    // initialises player
    delete[] player;

    if (multiPlayerGame) {
        playerCount = 2;
    } else {
        playerCount = 1;
    }

    player = new Player[playerCount];

    for (int p = 0; p < playerCount; ++p) {
        player[p].playerNumber = p;
        player[p].highScore = getHigh();
        player[p].pos = Vector2(screenWidth / 2, screenHeight / 2);

        if (playerCount == 2) {
            if (p == 0) {
                player[p].pos = Vector2(screenWidth / 2 - 60, screenHeight / 2);

                player[p].colour = RED;
                player[p].controlStickBaseColour = ColorAlpha(MAROON, 0.75);
                player[p].controlStickDragColour = ColorAlpha(RED, 0.75);
            } else if (p == 1) {
                player[p].pos = Vector2(screenWidth / 2 + 60, screenHeight / 2);

                player[p].colour = GREEN;
                player[p].controlStickBaseColour = ColorAlpha(DARKGREEN, 0.75);
                player[p].controlStickDragColour = ColorAlpha(GREEN, 0.75);
            }

            player[p].highScore = getHigh(true, p);

        }


    }

    levelUp();
}