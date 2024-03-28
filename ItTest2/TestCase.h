#pragma once
#include <iostream>
#include <vector>
#include <functional>
#include "Mammal.h"
#include "TestResult.h"
#include "MammalController.h"

class TestCase
{
public:
	std::string title;

	std::vector<Mammal*> vectorToTest;

	Mammal* mammalToAdd;
	std::vector<Mammal*> expectedAddResult;

	TestResult runTest(std::unique_ptr<MammalController>& mammalController);

	TestCase(
		std::string title,
		std::vector<Mammal*> vectorToTest,
		Mammal* mammalToAdd,
		std::vector<Mammal*> expectedAddResult
	) : title(title),
		vectorToTest(vectorToTest),
		mammalToAdd(mammalToAdd),
		expectedAddResult(expectedAddResult)
	{}
};

