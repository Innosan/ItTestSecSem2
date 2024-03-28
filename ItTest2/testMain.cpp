#include "testMain.h"
#include "MammalController.h"
#include "TestCase.h"
#include "Carnivore.h"
#include "Herbivore.h"

void testMain() {
	std::unique_ptr<MammalController> mammalController = std::make_unique<MammalController>();

	// Testing mammals
	// Mammal 1 - base mammal
	auto baseMammal = new Mammal {
		"Base mammal 2",
		10.0,
		"Desert",
		"Unknown"
	};

	// Mammal 2 - carnivore
	auto carnivore = new Carnivore {
		"Carnivore",
		20.0,
		"Forest",
		0.5
	};

	// Mammal 3 - herbivore
	auto herbivore = new Herbivore {
		"Herbivore",
		30.0,
		"Jungle",
		true
	};

	const auto testCases = std::vector<TestCase> {
		TestCase(
			"Adding object of base class to vector",
			std::vector<Mammal*> {
				new Mammal {
					"Base mammal",
					10.0,
					"Desert",
					"Unknown"
				}
			},
			new Mammal {
				"Base mammal 223",
				10.0,
				"Desert",
				"Unknown"
			},
			std::vector<Mammal*> {
				new Mammal {
					"Base mammal",
					10.0,
					"Desert",
					"Unknown"
				},
				new Mammal {
					"Base mammal 2",
					10.0,
					"Desert",
					"Unknown"
				},
			}
		),
		TestCase(
			"Adding object of derived class to vector",
			std::vector<Mammal*> {
				new Mammal {
					"Base mammal",
					10.0,
					"Desert",
					"Unknown"
				}
			},
			new Carnivore {
				"Carnivore",
				20.0,
				"Forest",
				0.5
			},
			std::vector<Mammal*> {
				new Mammal {
					"Base mammal",
					10.0,
					"Desert",
					"Unknown"
				},
				new Carnivore {
					"Carnivore",
					20.0,
					"Forest",
					0.5
				},
			}
		),
		TestCase(
			"Adding object of derived class to vector",
			std::vector<Mammal*> {
				new Mammal {
					"Base mammal",
					10.0,
					"Desert",
					"Unknown"
				}
			},
			new Herbivore {
				"Herbivore",
				30.0,
				"Jungle",
				true
			},
			std::vector<Mammal*> {
				new Mammal {
					"Base mammal",
					10.0,
					"Desert",
					"Unknown"
				},
				new Herbivore {
					"Herbivore",
					30.0,
					"Jungle",
					true
				},
			}
		),
		TestCase(
			"Adding object to empty vector",
			std::vector<Mammal*> {},
			new Mammal {
				"Base mammal 2",
				10.0,
				"Desert",
				"Unknown"
			},
			std::vector<Mammal*> { 
				new Mammal{
					"Base mammal 2",
					10.0,
					"Desert",
					"Unknown"
				}
			}
		)
	};

	bool allTestsPassed = true;
	for (auto testCase : testCases) {
		auto result = testCase.runTest(mammalController);

		if (!result.status) {
			allTestsPassed = false;
			std::cout << result.message << std::endl;
		}
	}

	allTestsPassed ? 
		std::cout << "All tests passed!" << std::endl : 
		std::cout << "Some tests failed!" << std::endl;
};
