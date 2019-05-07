#ifndef EXECUTIVE_H
#define EXECUTIVE_H
/////////////////////////////////////////////////////////////////////
// Executive.h - executes test functions                           //
// ver 1.0                                                         //
// Language:    C++, Visual Studio 2019                            //
// Application: Test Harness - Project 2,                          //
//              CSE687 - Object Oriented Design                    //
// Author:      Eric Voje, Kuohsun Tsai                            //
//              ervoje@syr.edu, kutsai@syr.edu                     //
/////////////////////////////////////////////////////////////////////
/*
* Package Operations:
* -------------------
* The Executive package defines the Executor class, which handles
* executing test functions within a safe environment.
*
* Maintenance History:
* --------------------
* Version 1.0:
*   Initial version. Executor object handles test execution.
*/

#include <vector>
#include "TestHarness.h"
#include "Logger.h"

namespace Executive {

	// Class that handles execution of test functions
	class Executor {
	public:
		Executor(Logger::Log log);
		Executor::Executor();
		~Executor();

		bool execute(std::vector<TestHarness::TestedCode> tv);

	private:
		Logger::Log logger;

	};

}

#endif