#pragma once
#include "settings.h"

class Surroundings
{
private:
    InhabitantType neighbor[3][3];

    InhabitantType* innerElement(Position position);

    static Position randomPosition();

public:
    Surroundings(InhabitantType type = UNKNOWN);

    void determineNeighbor(Position position, InhabitantType type);

    InhabitantType whoIsNeighbor(Position position);

    unsigned short countNeighbors(InhabitantType type) const;

    Position randomNeighbor(InhabitantType type);

    static void changeIndexByPosition(Position position, long& row, long& col);

    static void changeIndexByPosition(Position position, unsigned int& row, unsigned int& col);
};

