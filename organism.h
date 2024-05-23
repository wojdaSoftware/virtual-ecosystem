
class Organism
{

public:
	const unsigned short maxMeals;
	const unsigned short reproductionCost;

private:
	unsigned short healthCount;
	unsigned short mealCount;

public:
	Organism(unsigned short lifespan,
		unsigned short maxMeals,
		unsigned short reproductionCost);

	bool isAlive() const
	{
		return healthCount > 0;
	}

	bool isHungry() const
	{
		return isAlive() && mealCount < maxMeals;
	}

	bool isBudding() const
	{
		return isAlive() && mealCount > reproductionCost;
	}

	unsigned short checkHealthCount() const
	{
		return healthCount;
	}

	unsigned short checkMealCount() const
	{
		return mealCount;
	}

	bool eat();
	bool reproduce();

	void simulationStep();

	//void printOrganism(const Organism& o)
	//{
	//	cout << "healthCount: "
	//		<< o.checkHealthCount()
	//		<< " mealCount: "
	//		<< o.checkMealCount() << endl
	//		<< " maxMeals: "
	//		<< o.maxMeals
	//		<< " reproductionCost: "
	//		<< o.reproductionCost << endl
	//		<< " hungry: " << o.isHungry()
	//		<< " budding: "
	//		<< o.isBudding() << endl << endl;
	//}

	//int main()
	//{
	//	// Test of object creation
	//	Organism organism1(8, 3, 2);
	//	Organism organism2 = organism1;
	//	Organism organism3(organism1);

	//	cout << "Result of object creation test:" << endl << endl;
	//	cout << "Organism1:" << endl;
	//	printOrganism(organism1);
	//	cout << "Organism2" << endl;
	//	printOrganism(organism1);
	//	cout << "Organism3" << endl;
	//	printOrganism(organism2);

	//	// Test of object independence
	//	organism1.eat();
	//	organism1.eat();
	//	organism2.eat();
	//	organism3.simulationStep();

	//	cout << "Result of object independence test:" << endl << endl;
	//	cout << "Organism1:" << endl;
	//	printOrganism(organism1);
	//	cout << "Organism2" << endl;
	//	printOrganism(organism2);
	//	cout << "Organism3" << endl;
	//	printOrganism(organism3);

	//	//3. Test symulacji
	//	Organism organism4(8, 3, 2);

	//	cout << "Wynik testu symulacji:"
	//		<< endl << endl;
	//	cout << "Stan pocz¹tkowy:" << endl;
	//	printOrganism(organism4);

	//	for (int i = 1; i < 11; i++) {

	//		organism4.simulationStep();

	//		if (organism4.isBudding()) {
	//			organism4.reproduce();
	//			cout << "---> Potomek" << endl;
	//		}
	//		else organism4.eat();

	//		cout << "Po wykonaniu kroku symulacji: "
	//			<< i << endl;
	//		printOrganism(organism4);
	//	}

	//	return 0;
	//}

	// Accessing the SimulationSettings object
	//SimulationSettings& settings1 = SimulationSettings::getSimulationSettings();
	//SimulationSettings& settings2 = SimulationSettings::getSimulationSettings();
	//SimulationSettings& settings3 = SimulationSettings::getSimulationSettings();

	//cout << "Fetching settings 3 times" << endl;
	//cout << "Settings 1: "; displaySettings(settings1);
	//cout << "Settings 2: "; displaySettings(settings2);
	//cout << "Settings 3: "; displaySettings(settings3);

	//cout << endl << "Changing a value only once" << endl;
	//settings2.algaeLifeMax = 100;
	//cout << "Settings 1: "; displaySettings(settings1);
	//cout << "Settings 2: "; displaySettings(settings2);
	//cout << "Settings 3: "; displaySettings(settings3);

	//cout << endl << "Testing RandomGenerator" << endl;
	//cout << "Random numbers of type int:" << endl;
	//cout << " from 0 to 5: ";
	//for (int i = 0; i < 10; i++)
	//    cout << RNG::generateFromZeroTo(5) << " ";
	//cout << endl << " from 0 to 3: ";
	//for (int i = 0; i < 10; i++)
	//    cout << RNG::generateFromZeroTo(3) << " ";
	//cout << endl << " from 0 to 20: ";
	//for (int i = 0; i < 10; i++)
	//    cout << RNG::generateFromZeroTo(20) << " ";

	//cout << endl << endl;

	//cout << "Random numbers of type long: " << endl;
	//cout << " from -2 to 2:";
	//for (int i = 0; i < 10; i++)
	//    cout << RNG::generateBetween(-2L, 2L) << " ";

	//cout << endl << endl
	//    << "Random numbers of type unsigned short: " << endl;
	//cout << " from 2 to 6: ";
	//unsigned short min = 2, max = 6;

	//for (int i = 0; i < 10; i++)
	//    cout << RNG::generateBetween(max, min) << " ";

	//cout << endl << endl;

	//return 0;
};
