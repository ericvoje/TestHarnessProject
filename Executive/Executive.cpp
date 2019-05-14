/////////////////////////////////////////////////////////////////////
// Executive.cpp - executes test functions                         //
// ver 1.0                                                         //
// Language:    C++, Visual Studio 2019                            //
// Application: Test Harness - Project 2,                          //
//              CSE687 - Object Oriented Design                    //
// Author:      Eric Voje, Kuohsun Tsai                            //
//              ervoje@syr.edu, kutsai@syr.edu                     //
/////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Executive.h"
#include "TestDriver.h"
#include "ITest.h"
#include "..\Logger\Logger.h"
#include "..\TestHarness\TestHarness.h"

using namespace Executive;
using namespace TestHarness;
using namespace Logger;
using namespace std;

// Constructor
Executor::Executor()
{
	_log.logMessage(log_verbose, "Executor object created.");
}

// Destructor
Executor::~Executor()
{
}

// Function that handles execution of a TestedCode object
bool Executor::execute(TestedCode t)
{
	bool funcRet = false;

	_log.logMessage(log_verbose, "Executor execution started.");

	// Run the function within a safe try/catch block
	try {
		funcRet = t.func();

		if (funcRet == true) {
			// Test Passed
			_log.logMessage(log_min, "Test Passed");
			if (!t.passMsg.empty())
				_log.logMessage(log_med, t.passMsg);
		}
		else {
			// Test Failed
			_log.logMessage(log_min, "Test  Failed");
			if (!t.failMsg.empty())
				_log.logMessage(log_med, t.failMsg);
		}
	}
	catch (const char* msg) {
		// Caught an exception
		std::cerr << msg;
		_log.logMessage(log_min, "Exception Thrown!");
		_log.logMessage(log_min, "Test Failed");
		if (!t.failMsg.empty())
			_log.logMessage(log_med, t.failMsg);
	}

	return funcRet;
}

#ifdef TEST_EXECUTIVE

// Private test function 1 fails
bool testfunc1() {
	return false;
}

// Private test function 2 passes
bool testfunc2() {
	return true;
}

// Private test function 3 throws an exception
bool testfunc3() {
	throw "Exception thrown from testfunc3...\n";
	return true;
}

// Example code
int main()
{
	Log log(&cout, log_verbose);

	log.logMessage(log_min, "Testing Execute functions.");

	// Create our TestedCode objects
	TestedCode t1((int (*)()) testfunc1);
	t1.failMsg = "Example Test 1 Failed!";
	t1.passMsg = "Example Test 1 Passed!";
	TestedCode t2((int (*)()) testfunc2);
	TestedCode t3((int (*)()) testfunc3);

	//Harness th(log_verbose);

	ITest* testDriver = TestFactory::create();

	testDriver->addTest(t1);
	testDriver->addTest(t2);
	testDriver->addTest(t3);
	testDriver->execute();

	// ToDo: Create TestHarness
	// Parse TestRequest XML
	// Execute tests

	log.logMessage(log_min, "End test.");
}
#endif