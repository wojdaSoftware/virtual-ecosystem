#include "Surroundings.h"
#include "RandomGenerator.h"
#include "settings.h"

InhabitantType* Surroundings::innerElement(Position position) {
    switch (position) {
    case RIGHT: return &neighbor[1][2];
    case TOP_RIGHT: return &neighbor[0][2];
    case TOP: return &neighbor[0][1];
    case TOP_LEFT: return &neighbor[0][0];
    case LEFT: return &neighbor[1][0];
    case BOTTOM_LEFT: return &neighbor[2][0];
    case BOTTOM: return &neighbor[2][1];
    case BOTTOM_RIGHT: return &neighbor[2][2];
    case NOWHERE: return nullptr;
    }
    return nullptr;
}

Position Surroundings::randomPosition() {
    unsigned short min = 0, max = 8;
    return static_cast<Position>(RandomGenerator::generateBetween(min, max));
}

Surroundings::Surroundings(InhabitantType type) {
    for (auto i : { 0,1,2 })
        for (auto j : { 0,1,2 })
            neighbor[i][j] = type;

    neighbor[1][1] = UNKNOWN;
}

void Surroundings::determineNeighbor(Position position, InhabitantType type) {
    if (position != UNKNOWN)
        *innerElement(position) = type;
}

InhabitantType Surroundings::whoIsNeighbor(Position position) {
    if (position != UNKNOWN)
        return *innerElement(position);
    else return UNKNOWN;
}

unsigned short Surroundings::countNeighbors(InhabitantType type) const {
    unsigned short counter = 0;

    for (int i : {0, 1, 2})
        for (int j : {0, 1, 2}) {
            if (i == 1 && j == 1) continue;
            if (neighbor[i][j] == type) counter++;
        }

    return counter;
}

Position Surroundings::randomNeighbor(InhabitantType type) {
    if (countNeighbors(type) == 0) return NOWHERE;
    else {
        Position position = Surroundings::randomPosition();

        while (whoIsNeighbor(position) != type)
            position = Surroundings::randomPosition();

        return position;
    }
}

void Surroundings::changeIndexByPosition(Position position, long& row, long& col) {
    if (position == TOP_RIGHT || position == RIGHT || position == BOTTOM_RIGHT)
        col++;
    else if (position == TOP_LEFT || position == LEFT || position == BOTTOM_LEFT)
        col--;

    if (position == TOP_LEFT || position == TOP || position == TOP_RIGHT)
        row--;
    else if (position == BOTTOM_LEFT || position == BOTTOM || position == BOTTOM_RIGHT)
        row++;
}

void Surroundings::changeIndexByPosition(Position position, unsigned int& row, unsigned int& col) {
    long r = static_cast<long>(row);
    long c = static_cast<long>(col);

    changeIndexByPosition(position, r, c);

    row = static_cast<unsigned int>(r);
    col = static_cast<unsigned int>(c);
}
