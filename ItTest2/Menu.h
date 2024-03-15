#pragma once

#include <iostream>
#include <vector>
#include "MenuOption.h"
#include "MammalController.h"

using namespace std;

/**
 * \brief Responsible for managing a collection of menu options (menu).
 * Basic usage - initialize a menu with vector of MenuOption, then call actions
 */
class Menu
{
	vector<MenuOption> options;

public:
	enum optionsIds {
		PRINT = 1,
		ADD_MAMMAL,
		READ_FROM_FILE,
		SAVE_TO_FILE,
		EXIT,
	};

	void initializeMenu(std::unique_ptr<MammalController>& mammalController);
	void display();

	static void printWelcomeMessage();

	/**
	 * \brief Calling a menu action.
	 *
	 * \param index of option to call
	 */
	void choose(int index);
};
