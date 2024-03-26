#include <iostream>

#include "MammalController.h"

#include "Herbivore.h"
#include "Carnivore.h"
#include "Mammal.h"

#include "inputs.h"

Mammal* MammalController::getMammalFromUser() {
	std::string title = getStringUserInput("Enter the title of the mammal: ");
	double weight = getDoubleUserInput("Enter the weight of the mammal: ", 0, 10000);
	std::string habitat = getStringUserInput("Enter the habitat of the mammal: ");

	return new Mammal(title, weight, habitat, "Unknown");
}

Herbivore* MammalController::getHerbivoreFromUser() {
	Mammal* baseMammal = MammalController::getMammalFromUser();
	bool isMigrating = getBoolUserInput("Is the herbivore migrating? (yes/no): ");

	auto* newHerbivore = new Herbivore(baseMammal->getTitle(), baseMammal->getWeight(), baseMammal->getHabitat(), isMigrating);
	delete baseMammal; // We don't need the baseMammal anymore, so we can delete it

	return newHerbivore;
}

Carnivore* MammalController::getCarnivoreFromUser() {
	Mammal* baseMammal = MammalController::getMammalFromUser();
	double aggressionRate = getDoubleUserInput("Enter the aggression rate of the carnivore: ", -1, 2);

	auto* newCarnivore = new Carnivore(baseMammal->getTitle(), baseMammal->getWeight(), baseMammal->getHabitat(), aggressionRate);
	delete baseMammal; // We don't need the baseMammal anymore, so we can delete it

	return newCarnivore;
}
