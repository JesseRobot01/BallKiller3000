#ifndef BALL_KILLER_SCORE_H
#define BALL_KILLER_SCORE_H


class Score {
public:
    static void saveHigh(int score);

    static void loadHigh();

    static void checkIfExtraLife();
};


#endif