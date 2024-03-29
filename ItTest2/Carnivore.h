#pragma once

#include <iostream>
#include "Mammal.h"

class Carnivore : public Mammal
{
	double aggressionRate;

public:
	Carnivore(std::string title, double weight, std::string habitat, double aggressionRate) : Mammal(title, weight, habitat, "Carnivore") {
		this->aggressionRate = aggressionRate;
	}

	void description() override {
		std::cout << "This is a carnivorous mammal - " << getTitle() << std::endl;
		std::cout << "Weight: " << getWeight() << " kg" << std::endl;
		std::cout << "Habitat: " << getHabitat() << std::endl;
		std::cout << "Aggression rate: " << aggressionRate << std::endl << std::endl;
	};

	double getAggressionRate() {
		return aggressionRate;
	}
};
