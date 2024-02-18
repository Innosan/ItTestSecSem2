#include <iostream>
#include <vector>

#include "Menu.h"
#include "MenuOption.h"
#include "Herbivore.h"
#include "Carnivore.h"
#include "Mammal.h"

void Menu::initializeMenu(std::unique_ptr<MammalController>& mammalController) {
	vector<MenuOption> items = {
		// Print files
		MenuOption(this->PRINT, "Print mammals",  [&mammalController]() {
			mammalController->listMammals();
		}),

		// Exit
		MenuOption(this->EXIT, "Exit",  []() { exit(EXIT_SUCCESS); })
	};

	this->options = items;
};

void Menu::display() {
	std::cout << "\n";

	for (MenuOption item : this->options) {
		item.print();
	}
}

void Menu::choose(int index) {
	this->options[index - 1].callAction();
}

void Menu::printWelcomeMessage() {
	cout << "Fomin Mikhail Vital\'evich, group 4307, number 25" << endl;
	cout << "Test 2, task 12." << endl;

	cout << "The test specifies a base and derived class." << endl << endl;
	cout << "It is necessary to develop fields and methods inherited from the base class, as well as your own components of derived classes." << endl;
	cout << "The base class can be abstract. " << "Implement the ability to obtain a list of objects in a container." << endl;
	cout << "Provide necessary checks of source data." << endl;
};
