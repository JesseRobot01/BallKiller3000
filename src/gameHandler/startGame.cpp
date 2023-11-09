#include <iostream>
#include "../gameHandler.h"
#include "../data.h"

void GameHandler::startGame(int gamePlayerCount, bool AIGame) {
    // Activate game
    if (!AIGame) {
        isGameActive = true;
        isGameAiGame = false;
    } else {
        isGameAiGame = true;
    }
    isGameOver = false;

    level = 0;

    // initialises player
    delete[] player;


    playerCount = gamePlayerCount;


    player = new Player[playerCount];

    int playerSpacing = screenWidth / (playerCount + 1);

    for (int p = 0; p < playerCount; ++p) {
        player[p].playerNumber = p;
        player[p].highScore = getHigh(playerCount != 1, p);
        player[p].pos = Vector2(playerSpacing * (p + 1), screenHeight / 2);
        player[p].isAi = AIGame;

        if (playerCount != 1) {

            switch (p) {
                case 0:
                    player[p].colour = RED;
                    player[p].controlStickBaseColour = ColorAlpha(MAROON, 0.75);
                    player[p].controlStickDragColour = ColorAlpha(RED, 0.75);
                    break;

                case 1:
                    player[p].colour = GREEN;
                    player[p].controlStickBaseColour = ColorAlpha(DARKGREEN, 0.75);
                    player[p].controlStickDragColour = ColorAlpha(GREEN, 0.75);
                    break;
            }
        }

    }
    levelUp();
}