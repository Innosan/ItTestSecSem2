#include <iostream>
#include <vector>

#include "Carnivore.h"
#include "Herbivore.h"
#include "Mammal.h"
#include "Menu.h"
#include "inputs.h"

int main()
{
	// Initialize the mammal controller
	std::unique_ptr<MammalController> mammalController = std::make_unique<MammalController>();

	// Add some mammals
	mammalController->addMammal(new Carnivore("Lion", 200, "Savannah", 0.9));
	mammalController->addMammal(new Herbivore("Elephant", 5000, "Savannah", true));
	mammalController->addMammal(new Carnivore("Tiger", 300, "Jungle", 0.8));
	mammalController->addMammal(new Herbivore("Giraffe", 800, "Savannah", false));
	mammalController->addMammal(new Mammal("Giraffe", 800, "Savannah", "Unknown"));

	Menu::printWelcomeMessage();
	std::unique_ptr<Menu> menu = std::make_unique<Menu>();
	menu->initializeMenu(mammalController);

	int pickedItem = 0;

	do {
		menu->display();

		pickedItem = getIntUserInput("Choose an option: ", Menu::optionsIds::PRINT - 1, Menu::optionsIds::EXIT + 1);

		menu->choose(pickedItem);
	} while (pickedItem != Menu::optionsIds::EXIT);
}
