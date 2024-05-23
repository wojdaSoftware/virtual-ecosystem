#pragma once

#include <random>

class RandomGenerator {
private:
    static std::random_device device;
    RandomGenerator() {}

public:
    static unsigned short generateBetween(unsigned short min, unsigned short max);
    static long generateBetween(long min, long max);
    static int generateFromZeroTo(int max);
};

typedef RandomGenerator RNG;