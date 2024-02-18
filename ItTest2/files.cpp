#include <iostream>
#include <fstream>
#include <sstream>

#include <vector>
#include "Mammal.h"
#include "files.h"
#include <regex>

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

vector<Mammal> getFilesFromFile(string fileName) {
	vector<Mammal> newMammals;

	ifstream inputFile(fileName);
	if (!inputFile.is_open()) {
		cerr << "Error opening file: " << fileName << endl;
		return newMammals; // Return empty vector on error
	}

	string line;
	while (getline(inputFile, line)) {

		// Handle empty lines or lines with incorrect formatting
		if (line.empty()) {
			cerr << "Warning: Skipped empty line." << endl;
			continue;
		}

		//stringstream ss(line);
		//string token;
		//int fieldCount = 0;

		//int id = 0;
		//string title = "";
		//string createdAt = "";
		//int size = 0;
		//int usage = 0;

		//// Extract data from the line
		//while (getline(ss, token, ',')) {
		//	try {
		//		switch (fieldCount) {
		//		case 0: id = stoi(token); break;
		//		case 1: title = token; break;
		//		case 2: createdAt = token; break;
		//		case 3: size = stoi(token); break;
		//		case 4: usage = stoi(token); break;
		//		default:
		//			// Handle unexpected field count
		//			std::cerr << "Warning: parsing " << fieldCount << " field: " << "wrong number of fileds" << std::endl;
		//		}
		//	}
		//	catch (const std::invalid_argument& e) {
		//		// Handle conversion error
		//		std::cerr << "Warning: converting field " << fieldCount << ": " << e.what() << std::endl;
		//		// You can choose to skip the line, continue without the value, or throw an exception
		//	}

		//	fieldCount++;
		//}

		//// Create a File object and add it to the vector
		//Mammal mammal( title, createdAt, size, usage);
		//newMammals.push_back(file);
	}

	inputFile.close();
	return newMammals;
};

bool validateFileInput(string fileName, string path) {
	regex fileNameRegex("^[a-zA-Z0-9_.]+$");
	regex pathRegex("((?:[^/]*/)*)(.*)");

	return regex_match(fileName, fileNameRegex) && regex_match(path, pathRegex);
}

void exportToFile(vector<Mammal*> mammalsToExport) {
	string fileName = "";

	string path = "";

	do {
		cout << "Input file name: ";
		cin >> fileName;

		cout << "Input full path: \n";
		cin >> path;

	} while (!validateFileInput(fileName, path));


	string fullPath = path + fileName + ".csv";

	// Check if file exists and prompt user for overwrite
	if (fileExists(fullPath)) {
		if (!confirmOverwrite(fullPath)) {
			std::cerr << "Error: File already exists and user chose not to overwrite." << std::endl;
			return;
		}
	}

	// Write data to file
	ofstream file(path + fileName + ".csv");
	if (file.is_open()) {
		for (Mammal* mammal : mammalsToExport) {
			file << mammal->getDiet() << "," << mammal->getTitle() << "," << mammal->getHabitat() << ","
				<< mammal->getWeight() << "\n";
		}
		file.close();
	}
	else {
		std::cerr << "Error opening file for writing." << std::endl;
	}
};
