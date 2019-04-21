/////////////////////////////////////////////////////////////////////
// TestHarness.cpp - Handler for executing function tests          //
// ver 1.0                                                         //
// Language:    C++, Visual Studio 2019                            //
// Application: Test Harness - Project 1,                          //
//              CSE687 - Object Oriented Design                    //
// Author:      Eric Voje, Kuohsun Tsai                            //
//              ervoje@syr.edu, kutsai@syr.edu                     //
/////////////////////////////////////////////////////////////////////

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
		TestFunc test;
		test.func = func;
		return execute(test);
	}

	// Call execute from testFunc type
	bool Harness::execute(TestFunc toTest) {

		logger.logMessage(log_med, "Running Test " + std::to_string(++nTests));

		// Run the function within a safe try/catch block
		try {
			bool ret = toTest.func();

			if (ret == true) {
				// Test Passed
				logger.logMessage(log_min, "Test " + std::to_string(nTests) + " Passed");
				if(!toTest.passMsg.empty())
					logger.logMessage(log_med, toTest.passMsg);
				return true;
			}
			else {
				// Test Failed
				logger.logMessage(log_min, "Test " + std::to_string(nTests)+ " Failed");
				if (!toTest.failMsg.empty())
					logger.logMessage(log_med, toTest.failMsg);
				return false;
			}
		}
		catch (const char* msg) {
			// Caught an exception
			std::cerr << msg;
			logger.logMessage(log_min, "Exception Thrown!");
			logger.logMessage(log_min, "Test " + std::to_string(nTests) + " Failed");
			if (!toTest.failMsg.empty())
				logger.logMessage(log_med, toTest.failMsg);
		}
		return false;
	}

	// Call execute from testFunc Vector
	bool Harness::execute(std::vector<TestFunc> funcVector) {

		int nFunc = 0;
		bool result = true;

		// Iterate through our TestHarness objects and execute them
		for(std::vector<TestFunc>::iterator it = funcVector.begin(); it != funcVector.end(); ++it)
		{
			logger.logMessage(log_verbose, "Function number " + std::to_string(++nFunc) + " executing.");
			result = execute(*it) && result;
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