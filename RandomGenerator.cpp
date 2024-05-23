#include "randomgenerator.h"

std::random_device RandomGenerator::device;

unsigned short RandomGenerator::generateBetween(unsigned short min, unsigned short max) {
    if (min > max) {
        unsigned short temp = min;
        min = max;
        max = temp;
    }
    std::uniform_int_distribution<unsigned short> distribution(min, max);
    return distribution(RandomGenerator::device);
}

long RandomGenerator::generateBetween(long min, long max) {
    if (min > max) {
        long temp = min;
        min = max;
        max = temp;
    }
    std::uniform_int_distribution<long> distribution(min, max);
    return distribution(RandomGenerator::device);
}

int RandomGenerator::generateFromZeroTo(int max) {
    std::uniform_int_distribution<int> distribution(0, max);
    return distribution(RandomGenerator::device);
}