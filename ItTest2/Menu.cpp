#include <iostream>
#include <vector>

#include "Menu.h"
#include "MenuOption.h"

#include "Herbivore.h"
#include "Carnivore.h"
#include "Mammal.h"
#include "MammalController.h"

#include "inputs.h"
#include "files.h"

void Menu::initializeMenu(std::unique_ptr<MammalController>& mammalController) {
	vector<MenuOption> items = {
		// Print files
		MenuOption(this->PRINT, "Print mammals",  [&mammalController]() {
			mammalController->listMammals();
		}),

		// Add mammal
		MenuOption(this->ADD_MAMMAL, "Add mammal",  [&mammalController]() {
			int type = getIntUserInput("Enter the type of mammal (1 - Base Mammal, 2 - Herbivore, 3 - Carnivore): ", 1 - 1, 3 + 1);

			switch (type)
			{
			case 1: {
				mammalController->addMammal(MammalController::getMammalFromUser());
				break;
			}
			case 2: {
				mammalController->addMammal(MammalController::getHerbivoreFromUser());
				break;
			}
			case 3: {
				mammalController->addMammal(MammalController::getCarnivoreFromUser());
				break;
			}
			default:
				break;
			}
		}),

		// Read from file
		MenuOption(this->READ_FROM_FILE, "Read from file",  [&mammalController]() {
			std::string filepath = getValidFilePath();

			vector<Mammal*> mammalsFromFile = getMammalsFromFile(filepath);

			if (mammalsFromFile.empty()) {
				cerr << "Error reading files from file." << endl;
			}
			else {
				mammalController->setMammals(mammalsFromFile);

				cout << endl << "Successfull read from file!" << endl << "Readed " << mammalsFromFile.size() << " mammal(s)!" << endl;
			}
		}),

		// Save to file
		MenuOption(this->SAVE_TO_FILE, "Save to file",  [&mammalController]() {
			vector<Mammal*> mammalsToExport = mammalController->getMammals();

			if (mammalsToExport.size() == 0) cout << "No files to export!";
			else exportToFile(mammalsToExport);
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
