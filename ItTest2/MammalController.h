#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include "Mammal.h"
#include "Herbivore.h"
#include "Carnivore.h"

class MammalController
{
	std::vector<Mammal*> mammals;

public:
	void addMammal(Mammal* mammal) {
		mammals.push_back(mammal);
	}

	void listMammals() {
		for (auto* mammal : mammals) {
			mammal->description();
		}
	}

	void setMammals(std::vector<Mammal*> newMammals) {
		this->mammals = newMammals;
	}

	std::vector<Mammal*> getMammals() {
		return mammals;
	}

	static Mammal* getMammalFromUser();
	static Herbivore* getHerbivoreFromUser();
	static Carnivore* getCarnivoreFromUser();
};
