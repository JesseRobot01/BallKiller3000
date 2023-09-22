#include "../utils.h"
#include <iostream>
#include <random>

int Utils::random(int min, int max) {
    // Create a random device to obtain a seed
    std::random_device rd;

    // Create a random number generator using the seed
    std::mt19937 rng(rd());

    // Create a uniform distribution between min and max
    std::uniform_int_distribution<int> random(min, max);

    return random(rng);
}

float Utils::random(float min, float max) {
    // Create a random device to obtain a seed
    std::random_device rd;

    // Create a random number generator using the seed
    std::mt19937 rng(rd());

    // Create a uniform distribution between min and max
    std::uniform_real_distribution<float> random(min, max);

    return random(rng);
}
