#pragma once
#include "settings.h"

class Surroundings;

class Inhabitant
{
protected:
	char symbol;

public:
	Inhabitant(char _symbol =
		SimulationSettings::
		getSimulationSettings().unknownIcon);

	Inhabitant(const Inhabitant& inhabitant);

	virtual char whatSymbol() const final;

	virtual ~Mieszkaniec();

	virtual InhabitantType whoAreYou() = 0;

	virtual InhabitantIntent
		chooseAction(Surroundings surroundings) = 0;

	virtual Inhabitant* giveOffspring() = 0;

	virtual void
		acceptPrey(Inhabitant* inhabitant) = 0;
};

