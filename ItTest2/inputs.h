#pragma once
#include <iostream>

/**
 * \brief Get int user intput.
 *
 * \param welcomeMessage - message to display to the user
 * \param min - minimum value
 * \param max - maximum value
 *
 * \return int user input
 */
int getIntUserInput(std::string welcomeMessage, int min = 0, int max = INT_MAX);

/**
 * \brief Get string user input.
 *
 * \param welcomeMessage - message to display to the user
 *
 * \return string user input
 */
std::string getStringUserInput(std::string welcomeMessage);

/**
 * \brief Get double user input.
 *
 * \param welcomeMessage - message to display to the user
 * \param min - minimum value
 * \param max - maximum value
 *
 * \return double user input
 */
double getDoubleUserInput(std::string welcomeMessage, double min = 0, double max = DBL_MAX);

/**
 * \brief Get bool user input.
 *
 * \param welcomeMessage - message to display to the user
 *
 * \return bool user input
 */
bool getBoolUserInput(std::string welcomeMessage);
