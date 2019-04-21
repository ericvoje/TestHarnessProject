#ifndef TESTHARNESS_H
#define TESTHARNESS_H
/////////////////////////////////////////////////////////////////////
// TestHarness.h - Handler for executing function tests            //
// ver 1.0                                                         //
// Language:    C++, Visual Studio 2019                            //
// Application: Test Harness - Project 1,                          //
//              CSE687 - Object Oriented Design                    //
// Author:      Eric Voje, Kuohsun Tsai                            //
//              ervoje@syr.edu, kutsai@syr.edu                     //
/////////////////////////////////////////////////////////////////////
/*
* Package Operations:
* -------------------
* The TestHarness package provides the Harness object which handles the
* execution of test functions in a safe environment. The Harness object
* also creates a Log object that will print messages to the log.
*
* Maintenance History:
* --------------------
* Version 1.0:
*   Initial version. Harness object executes functions in a try-catch block.
*/

#include "Logger.h"

namespace TestHarness {

	class TestFunc {
	public:
		bool (*func)();
		std::string passMsg;
		std::string failMsg;
	};

	// Object that contains all of the information to execute our function under test
	class Harness {

	private:
		Logger::Log logger;
		int nTests = 0;

	public:
		bool execute(bool (*func)());
		bool execute(TestFunc func);
		bool execute(std::vector<TestFunc> funcVector);

		Harness(LogLevel logLevel);
		~Harness();
	};

}

#endif TESTHARNESS_H