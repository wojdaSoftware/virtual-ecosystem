#include <iostream>
#include "RandomGenerator.h"
#include "settings.h"
#include "Surroundings.h"

using namespace std;

void displaySettings(SimulationSettings& settings) {
    cout << "Algae symbol:" << settings.algaeIcon
        << " minLife=" << settings.algaeLifeMin
        << " maxLife=" << settings.algaeLifeMax << endl;
}

string typeName(InhabitantType type) {
    switch (type) {
    case ALGA: return "ALGA";
    case FUNGUS: return "FUNGUS";
    case BACTERIUM: return "BACTERIUM";
    case EMPTY: return "EMPTY";
    case WALL: return "WALL";
    case CORPSE: return "CORPSE";
    case UNKNOWN: return "UNKNOWN";
    }
}


int main() {
    Surroundings surroundings;

    surroundings.determineNeighbor(RIGHT, ALGA);
    surroundings.determineNeighbor(TOP_RIGHT, FUNGUS);
    surroundings.determineNeighbor(TOP, FUNGUS);
    surroundings.determineNeighbor(TOP_LEFT, ALGA);
    surroundings.determineNeighbor(LEFT, BACTERIUM);
    surroundings.determineNeighbor(BOTTOM_LEFT, BACTERIUM);
    surroundings.determineNeighbor(BOTTOM, ALGA);
    surroundings.determineNeighbor(BOTTOM_RIGHT, EMPTY);

    cout << "Surroundings report:" << endl;

    for (int i = 0; i < 8; i++) {
        Position p = static_cast<Position>(i);
        InhabitantType r = surroundings.whoIsNeighbor(p);
        cout << "position=" << p << " type=" << typeName(r) << endl;
    }

    cout << endl << "Counting neighbors of specific type:" << endl
        << " algae=" << surroundings.countNeighbors(ALGA) << endl
        << " fungi=" << surroundings.countNeighbors(FUNGUS) << endl
        << " corpses=" << surroundings.countNeighbors(CORPSE) << endl;

    cout << endl << "Randomizing neighbor:" << endl
        << " alga -> " << surroundings.randomNeighbor(ALGA) << endl
        << " empty -> " << surroundings.randomNeighbor(EMPTY) << endl
        << " corpse -> " << surroundings.randomNeighbor(CORPSE) << endl;

    long row, col;
    cout << endl << "Changing indexes [5][7] according to position:" << endl;

    for (int i = 0; i < 8; i++) {
        Position p = static_cast<Position>(i);
        row = 5; col = 7;
        Surroundings::changeIndexByPosition(p, row, col);
        cout << " position: " << p << " ->[" << row << "][" << col << "]" << endl;
    }

    cout << endl;

    return 0;
}


// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

