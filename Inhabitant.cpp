#include "Inhabitant.h"

Inhabitant::Inhabitant(char _symbol) {
	symbol = _symbol;
}

Inhabitant::Inhabitant(const Inhabitant& inhabitant) {
	symbol = inhabitant.symbol;
}

char Inhabitant::whatSymbol() const {
	return symbol;
}

Inhabitant::~Inhabitant{

}