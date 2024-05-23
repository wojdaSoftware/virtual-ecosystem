#pragma once

enum InhabitantType { ALGA, FUNGUS, BACTERIUM, EMPTY, WALL, CORPSE, UNKNOWN };
enum InhabitantAction { REPRODUCE, HUNT, DECOMPOSE, NONE };
enum Position { RIGHT = 0, TOP_RIGHT = 1, TOP = 2, TOP_LEFT = 3, LEFT = 4, BOTTOM_LEFT = 5, BOTTOM = 6, BOTTOM_RIGHT = 7, NOWHERE = 8 };

class SimulationSettings {
public:
	const char
		algaeIcon = '*',
		fungusIcon = '#',
		bacteriumIcon = '@',
		corpseIcon = '+',
		unknownIcon = '?',
		voidIcon = '_',
		separatorIcon = ' ';

	unsigned short
		algaeLifeMin = 5,
		algaeLifeMax = 10,
		algaeReproductionCost = 2,
		algaeFoodLimit = 6,

		fungusLifeMin = 40,
		fungusLifeMax = 60,
		fungusReproductionCost = 3,
		fungusFoodLimit = 30,

		bacteriumLifeMin = 25,
		bacteriumLifeMax = 40,
		bacteriumReproductionCost = 3,
		bacteriumFoodLimit = 10;

	bool isValidResidentIcon(char symbol) const {
		return symbol == algaeIcon || symbol == fungusIcon || symbol == bacteriumIcon || symbol == corpseIcon || symbol == voidIcon;
	}

	bool isValidSeparator(char symbol) const {
		return symbol == separatorIcon;
	}

private:
	SimulationSettings() {}
	SimulationSettings(SimulationSettings&);
public:
	static SimulationSettings& getSimulationSettings() {
		static SimulationSettings settings;
		return settings;
	}
};