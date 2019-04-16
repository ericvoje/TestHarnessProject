#pragma once

#ifndef TESTHARNESS_H
#define TESTHARNESS_H

#include "Logger.h"

// Object that contains all of the information to execute our function under test
class TestHarness {

private:
	Logger logger;

public:
	bool execute(bool (*func)());

	TestHarness(LogLevel logLevel);
	~TestHarness();
};



#endif TESTHARNESS_H