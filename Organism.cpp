#include "organism.h"

Organism::Organism(unsigned short lifespan, unsigned short maxMeals, unsigned short reproductionCost)
	: maxMeals(maxMeals), reproductionCost(reproductionCost), healthCount(lifespan), mealCount(0) {}

bool Organism::eat() {
	if (isHungry()) {
		mealCount++;
		return true;
	}
	else return false;
}

bool Organism::reproduce() {
	if (isBudding()) {
		mealCount -= reproductionCost;
		return true;
	}
	else return false;
}

void Organism::simulationStep() {
	if (isAlive()) healthCount--;
}