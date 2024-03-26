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
