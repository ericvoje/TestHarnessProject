#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "TestHarness.h"
#include "Logger.h"

// Execute the function under test and report the results
bool TestHarness::execute(bool (*func)())
{
	// Run the function within a safe try/catch block
	try {
		bool ret = func();
		
		if (ret == true) {
			// Test Passed
			logger.logMessage(log_min, "Test Passed");
			return true;
		} else {
			// Test Failed
			logger.logMessage(log_min, "Test Failed");
			return false;
		}
	}
	catch (const char* msg) {
		// Caught an exception
		std::cerr << msg; 
	}
	return false;
}

// Destructor
// Remove Logger
TestHarness::~TestHarness()
{
	//delete logger;
}

// Create a new TestHarness object by providing a function pointer
TestHarness::TestHarness(LogLevel logLevel)
{
	logger = Logger(logLevel);
}
