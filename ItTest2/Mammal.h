#pragma once

#include <iostream>
class Mammal
{
	std::string title;
	double weight;
	std::string habitat;
	std::string diet;

public:
	Mammal(std::string title, double weight, std::string habitat, std::string diet) : title(title), weight(weight), habitat(habitat), diet(diet) {}

	virtual void description() {
		std::cout << "This is an unknown mammal - " << getTitle() << std::endl;
		std::cout << "Weight: " << getWeight() << " kg" << std::endl;
		std::cout << "Habitat: " << getHabitat() << std::endl;
	};

	std::string getTitle() { return title; }
	std::string getDiet() { return diet; }
	double getWeight() { return weight; }
	std::string getHabitat() { return habitat; }
};
