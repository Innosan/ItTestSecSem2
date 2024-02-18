#pragma once

#include <iostream>
#include "Mammal.h"

class Herbivore : public Mammal
{
	bool isMigrating;

public:
	Herbivore(std::string title, float weight, std::string habitat, bool isMigrating) : Mammal(title, "Herbivore", weight, habitat) {
		this->isMigrating = isMigrating;
	}

	void description() override {
		std::cout << "This is a herbivorous mammal - " << getTitle() << std::endl;
		std::cout << "Weight: " << getWeight() << " kg" << std::endl;
		std::cout << "Habitat: " << getHabitat() << std::endl;
		std::cout << "Migrating: " << (isMigrating ? "yes" : "no") << std::endl;
	};
};
