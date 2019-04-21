// TestHarnessProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

#include "TestHarness.h"
#include "Logger.h"

#define TESTSIZE 10

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
	// TestHarness will execute our functions in a controlled environment
	TestHarness::Harness toTest = TestHarness::Harness(log_verbose);

	//toTest.execute(foo);
	//toTest.execute(bar);
	//toTest.execute(foo2);

	TestHarness::testFunc function1;
	function1.func = foo;

	TestHarness::testFunc function2;
	function2.func = bar;

	TestHarness::testFunc function3;
	function3.func = foo2;

	TestHarness::testFunc function4;
	function4.func = foo;

	// Create vector of testFunc types to pass in functions as a list
	std::vector<TestHarness::testFunc> funcVector;

	funcVector.push_back(function1);
	funcVector.push_back(function2);
	funcVector.push_back(function3);
	funcVector.push_back(function4);

	toTest.execute(funcVector);

	exit(0);

}


