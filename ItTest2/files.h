#pragma once

#include <iostream>
#include <vector>

#include "Mammal.h"

using namespace std;

/**
 * \brief Check if a file exists.
 *
 * \param filename - name of the file to check
 *
 * \return true if the file exists, false otherwise
 */
bool fileExists(const std::string& filename);

/**
 * \brief Prompt user for overwrite confirmation.
 *
 * \param filename - name of the file to overwrite
 *
 * \return true if the user confirms the overwrite, false otherwise
 */
bool confirmOverwrite(const std::string& filename);

/**
 * Reads data from a file and constructs a vector of File objects.
 *
 * \param fileName The name of the file to read.
 * \return A vector of File objects, or an empty vector if there was an error.
 */
vector<Mammal*> getMammalsFromFile(string fileName);

/**
 * Exports data to a file.
 *
 * \param filesToExport A vector of File objects to export.
 */
void exportToFile(const vector<Mammal*>& mammals);

/**
 * \brief Check if a file path is valid.
 *
 * \param filePath - path to check
 *
 * \return true if the file path is valid, false otherwise
 */
bool isFilePathValid(const std::string& filePath);

/**
 * \brief Check if a file name is valid (general case and reserved Windows names).
 *
 * \param fileName - name to check
 *
 * \return true if the file name is valid, false otherwise
 */
bool isFileNameValid(const std::string& fileName);

/**
 * \brief Get a valid file path from the user.
 *
 * \return A valid file full path (with name).
 */
string getValidFilePath();
