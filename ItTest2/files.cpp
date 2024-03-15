#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include <vector>

#include "Mammal.h"
#include "Herbivore.h"
#include "Carnivore.h"

#include "files.h"

using namespace std;

// Function to check if a file exists
bool fileExists(const std::string& filename) {
	std::ifstream file(filename);
	return file.is_open();
}

// Function to prompt user for overwrite confirmation
bool confirmOverwrite(const std::string& filename) {
	std::cout << "File '" << filename << "' already exists." << std::endl;
	std::cout << "Do you want to overwrite it? (y/n): ";

	char answer;
	std::cin >> answer;

	return std::tolower(answer) == 'y';
}

vector<Mammal*> getMammalsFromFile(string fileName) {
	vector<Mammal*> mammals;

	ifstream inputFile(fileName);
	if (!inputFile.is_open()) {
		cerr << "Error opening file: " << fileName << endl;
		return mammals; // Return empty vector on error
	}

	string line;
	while (getline(inputFile, line)) {
		// Handle empty lines or lines with incorrect formatting
		if (line.empty()) {
			cerr << "Warning: Skipped empty line." << endl;
			continue;
		}

		stringstream ss(line);
		string token;
		int fieldCount = 0;

		string title = "";
		string diet = "";
		double weight = 0.0;
		string habitat = "";

		// Additional fields for inherited classes
		bool isMigrating = false;
		double aggressionRate = 0.0;

		// Extract data from the line
		while (getline(ss, token, ',')) {
			try {
				switch (fieldCount) {
				case 0: title = token; break;
				case 1: weight = stod(token); break;
				case 2: habitat = token; break;
				case 3: diet = token; break;
				case 4:
					if (diet == "Herbivore") {
						isMigrating = (token == "1" ? true : false);
					}
					else if (diet == "Carnivore") {
						aggressionRate = stod(token);
					}
					break;
				default:
					// Handle unexpected field count
					std::cerr << "Warning: parsing " << fieldCount << " field: " << "wrong number of fields" << std::endl;
				}
			}
			catch (const std::invalid_argument& e) {
				// Handle conversion error
				std::cerr << "Warning: converting field " << fieldCount << ": " << e.what() << std::endl;
				// You can choose to skip the line, continue without the value, or throw an exception
			}

			fieldCount++;
		}

		// Create a Mammal object and add it to the vector
		if (diet == "Herbivore") {
			mammals.push_back(new Herbivore(title, weight, habitat, isMigrating));
		}
		else if (diet == "Carnivore") {
			mammals.push_back(new Carnivore(title, weight, habitat, aggressionRate));
		}
		else {
			mammals.push_back(new Mammal(title, weight, habitat, diet));
		}
	}

	inputFile.close();
	return mammals;
};

bool isFilePathValid(const std::string& filePath) {

	// Regular expression to match a valid file path (Windows)
	regex filePathRegex("^(?:[a-zA-Z]\\:|\\\\)\\\\([^\\\\]+\\\\)*[^\\/:*?\"<>|]+\\.csv$");

	if (!regex_match(filePath, filePathRegex)) {
		std::cerr << "Error: Invalid file path." << std::endl;
		return false;
	}

	return true;
}

void exportToFile(const vector<Mammal*>& mammals) {
	string fileName = "";

	string path = "";

	do {
		cout << "Input file name (only csv available): ";
		cin >> fileName;

		cout << "Input full path: \n";
		cin >> path;

	} while (!isFilePathValid(path + fileName));

	string fullPath = path + fileName;
	cout << "Full path: " << fullPath << endl;

	// Check if file exists and prompt user for overwrite
	if (fileExists(fullPath)) {
		if (!confirmOverwrite(fullPath)) {
			std::cerr << "Error: File already exists and user chose not to overwrite." << std::endl;
			return;
		}
	}

	ofstream outputFile(fullPath);
	if (!outputFile.is_open()) {
		cerr << "Error opening file: " << fullPath << endl;
		return; // Return on error
	}

	for (Mammal* mammal : mammals) {
		outputFile << mammal->getTitle() << ","
			<< mammal->getWeight() << ","
			<< mammal->getHabitat() << ","
			<< mammal->getDiet();

		// Check if the mammal is a Herbivore or Carnivore and write additional data
		if (Herbivore* herbivore = dynamic_cast<Herbivore*>(mammal)) {
			outputFile << "," << (herbivore->getIsMigrating() ? 1 : 0);
		}
		else if (Carnivore* carnivore = dynamic_cast<Carnivore*>(mammal)) {
			outputFile << "," << carnivore->getAggressionRate();
		}

		outputFile << "\n";
	}

	outputFile.close();
}
