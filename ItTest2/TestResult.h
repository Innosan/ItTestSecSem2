#pragma once

#include <iostream>

class TestResult
{
public:
	bool status;
	std::string message;

	TestResult(bool status, std::string message) : status(status), message(message) {}
};

