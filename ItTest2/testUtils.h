#pragma once

#include <vector>
#include "Mammal.h"

/**
 * \brief Utility function to check if actual result vector is equal to expected result vector.
 *
 * \param vectorToCheck - actual vector to test.
 * \param expectedVector - expected result vector.
 *
 * \return true if vectors are equal, false otherwise.
 */
bool runVectorCheck(std::vector<Mammal*> vectorToCheck, std::vector<Mammal*> expectedVector);

