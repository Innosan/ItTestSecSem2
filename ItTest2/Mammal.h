#pragma once

#include <iostream>
class Mammal
{
	std::string title;
	std::string diet;
	double weight;
	std::string habitat;

public:
	Mammal(std::string title, std::string diet, double weight, std::string habitat) : title(title), diet(diet), weight(weight), habitat(habitat) {}

	virtual void description() {};

	std::string getTitle() { return title; }
	std::string getDiet() { return diet; }
	double getWeight() { return weight; }
	std::string getHabitat() { return habitat; }
};

