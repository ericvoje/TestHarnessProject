#ifndef TESTHARNESS_H
#define TESTHARNESS_H

/////////////////////////////////////////////////////////////////////
// TestHarness.h - Handler for executing function tests            //
// ver 2.0                                                         //
// Language:    C++, Visual Studio 2019                            //
// Application: Test Harness - Project 2,                          //
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
*
* Version 2.0:
* 
*/

#include "Logger.h"
#include "Executive.h"
#include "ITest.h"

namespace TestHarness {

	// Class that holds individual test functions
	class TestedCode {
	public:
		TestedCode(int (*func)());
		~TestedCode();

		std::string passMsg;
		std::string failMsg;
		int (*func)();
	};

	// Class that contains the test framework
	class TestDriver : public ITest
	{
	public:
		bool test();

		// Constructor and Destructor
		TestDriver(int (*func)());
		~TestDriver();

		void addTest(TestDriver t)
		{
			toTest.push_back(t);
		}

	private:
		std::vector<TestedCode> toTest;
		Executive::Executor executor;
	};

	// TestFactory Factory Method
	inline ITest* TestFactory::create(int (*func)())
	{
		return new TestDriver(func);
	}

	// Object that contains all of the information to execute our function under test
	class Harness {
	public:
		//bool execute(bool (*func)());
		//bool execute(TestFunc func);
		//bool execute(std::vector<TestFunc> funcVector);
		
		bool execute();

		// Constructors
		Harness(LogLevel logLevel);
		~Harness();

	private:
		Logger::Log logger;
		int nTests = 0;
	};

}

#endif TESTHARNESS_H