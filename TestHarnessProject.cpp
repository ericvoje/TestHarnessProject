/////////////////////////////////////////////////////////////////////
// TestHarnessProject.cpp - Main entry point for project. Example  //
//              code demonstrating major functionality of the      //
//              Test Harness Project                               //
// ver 2.0                                                         //
// Language:    C++, Visual Studio 2019                            //
// Application: Test Harness - Project 2,                          //
//              CSE687 - Object Oriented Design                    //
// Author:      Eric Voje, Kuohsun Tsai                            //
//              ervoje@syr.edu, kutsai@syr.edu                     //
/////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>

#include "TestHarness.h"
#include "Logger.h"

// Return true
bool foo()
{
	return true;
}


// Return false
bool bar()
{
	return false;
}

// Throw exception
bool foo2()
{
	throw "This function is broken...\n";
	return true;
}

// Run the TestHarnessProject executable
int main()
{

/* Old Code
	
	// TestHarness will execute our functions in a controlled environment
	TestHarness::Harness toTest = TestHarness::Harness(log_verbose);

	// Functions can be executed by passing their function pointer
	// into the execute function itself
	toTest.execute(foo);
	toTest.execute(bar);
	toTest.execute(foo2);

	// Or functions can be tested in a list by creating TestFunc objects
	TestHarness::TestFunc function1;
	function1.func = foo;

	TestHarness::TestFunc function2;
	function2.func = bar;

	TestHarness::TestFunc function3;
	function3.func = foo2;
	function3.failMsg = "Function 3 is bad.";
	function3.passMsg = "This function is perfect!";

	TestHarness::TestFunc function4;
	function4.func = foo;
	function4.failMsg = "Function 4 is bad.";
	function4.passMsg = "This function is perfect!";

	// Create vector of TestFunc objects to pass in functions as a list
	std::vector<TestHarness::TestFunc> funcVector;

	funcVector.push_back(function1);
	funcVector.push_back(function2);
	funcVector.push_back(function3);
	funcVector.push_back(function4);

	// Pass the entire vector into the execute function to execute the tests in order
	toTest.execute(funcVector);

*/

	std::cout << "This doesn't work yet." << std::endl;

	exit(0);
}


