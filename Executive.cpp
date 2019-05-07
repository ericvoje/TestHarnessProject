/////////////////////////////////////////////////////////////////////
// Executive.cpp - executes test functions                         //
// ver 1.0                                                         //
// Language:    C++, Visual Studio 2019                            //
// Application: Test Harness - Project 2,                          //
//              CSE687 - Object Oriented Design                    //
// Author:      Eric Voje, Kuohsun Tsai                            //
//              ervoje@syr.edu, kutsai@syr.edu                     //
/////////////////////////////////////////////////////////////////////

#include "Executive.h"
#include "TestHarness.h"
#include "Logger.h"

using namespace Executive;
using namespace TestHarness;

// Constructor
Executor::Executor(Logger::Log log)
{
	// Hang onto Log object
	//this->log = log;
}

// Destructor
Executor::~Executor()
{

}

// Function that handles execution of a TestedCode object
bool Executor::execute(std::vector<TestedCode> tv)
{
	// Loop through each test and execute
	int nTests = 0;
	bool returnVal = true;

	for (auto& test : tv)
	{
		// Increment nTests
		++nTests;
		bool funcRet;

		// Run the function within a safe try/catch block
		try {
			funcRet = test.func();

			if (funcRet == true) {
				// Test Passed
				logger.logMessage(log_min, "Test " + std::to_string(nTests) + " Passed");
				if (!test.passMsg.empty())
					logger.logMessage(log_med, test.passMsg);
			}
			else {
				// Test Failed
				logger.logMessage(log_min, "Test " + std::to_string(nTests) + " Failed");
				if (!test.failMsg.empty())
					logger.logMessage(log_med, test.failMsg);
			}
		}
		catch (const char* msg) {
			// Caught an exception
			std::cerr << msg;
			logger.logMessage(log_min, "Exception Thrown!");
			logger.logMessage(log_min, "Test " + std::to_string(nTests) + " Failed");
			if (!test.failMsg.empty())
				logger.logMessage(log_med, test.failMsg);
		}

		// Keep track of our return value
		returnVal = returnVal && funcRet;
	}
	return returnVal;
}
