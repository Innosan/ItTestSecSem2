#include "TestCase.h"
#include "TestResult.h"
#include "testUtils.h"

TestResult TestCase::runTest(std::unique_ptr<MammalController>& mammalController) {
	mammalController->setMammals(this->vectorToTest);
	mammalController->addMammal(this->mammalToAdd);

	const bool isVectorsEquals = runVectorCheck(mammalController->getMammals(), this->expectedAddResult);
	std::string resultMessage = isVectorsEquals ? "Test " + this->title + "passed!" : "Test " + this->title + "failed!";

	return TestResult(isVectorsEquals, resultMessage);
}
