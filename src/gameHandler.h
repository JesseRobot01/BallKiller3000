#ifndef BALLKILLER3000_GAMEHANDLER_H
#define BALLKILLER3000_GAMEHANDLER_H

class GameHandler {
public:
    static void startGame();

    static void checkLevelUp(bool firstTimeRun = false);

    static int loadHigh();

    static void saveHigh(bool forced = false);

    static void endGame(bool forced = false);
};


#endif