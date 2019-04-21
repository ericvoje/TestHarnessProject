#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

#include "TestHarness.h"
#include "Logger.h"

namespace TestHarness {


	// Execute the function under test and report the results
	bool Harness::execute(bool (*func)())
	{
		// Run the function within a safe try/catch block
		try {
			bool ret = func();

			if (ret == true) {
				// Test Passed
				logger.logMessage(log_min, "Test Passed");
				return true;
			}
			else {
				// Test Failed
				logger.logMessage(log_min, "Test Failed");
				return false;
			}
		}
		catch (const char* msg) {
			// Caught an exception
			std::cerr << msg;
			logger.logMessage(log_min, "Exception Thrown!");
			logger.logMessage(log_min, "Test Failed");
		}
		return false;
	}

	// Call execute from testFunc type
	bool Harness::execute(TestFunc func) {
		return execute(func.func);
	}

	// Call execute from testFunc Vector
	bool Harness::execute(std::vector<TestFunc> funcVector) {

		int nFunc = 0;
		bool result = true;

		// Iterate through our TestHarness objects and execute them
		for(std::vector<TestFunc>::iterator it = funcVector.begin(); it != funcVector.end(); ++it)
		{
			logger.logMessage(log_verbose, "Function number " + std::to_string(++nFunc) + " executing.");
			result = execute(it->func) && result;
		}

		return result;
	}

	// Destructor
	// Remove Logger
	Harness::~Harness()
	{
		//delete logger;
	}

	// Create a new TestHarness object by providing a function pointer
	Harness::Harness(LogLevel logLevel)
	{
		logger = Logger::Log(logLevel);
	}

}