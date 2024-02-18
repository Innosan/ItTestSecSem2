#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include "Mammal.h"

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
};

