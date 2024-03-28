#include "testUtils.h"

void printVector(std::vector<Mammal*> vectorToPrint) {
	for (size_t i = 0; i < vectorToPrint.size(); ++i) {
		std::cout << vectorToPrint[i]->getTitle() << std::endl;
	}
}

bool runVectorCheck(std::vector<Mammal*> vectorToCheck, std::vector<Mammal*> expectedVector) {
	bool passed = true;

	for (size_t i = 0; i < vectorToCheck.size(); ++i) {
		std::string actualId = vectorToCheck[i]->getTitle();
		std::string expectedId = expectedVector[i]->getTitle();

		// cout << "Actual: " << actualId << " Expected: " << expectedId << endl;

		if (actualId != expectedId) {
			std::cerr << "\n\nError: Mismatch at index " << i << ": "
				<< actualId << " != " << expectedId << "\n\n";

			std::cout << "Actual Vector: " << std::endl;
			printVector(vectorToCheck);

			std::cout << std::endl << "Expected Vector: " << std::endl;
			printVector(expectedVector);
			return false;
		}
	}

	return passed;
}