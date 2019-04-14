// TestHarnessProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

#include "TestHarness.h"

#define TESTSIZE 10

// Return the higher number
int foo(int a, int b)
{
	if (a >= b)
		return a;
	else
		return b;
}


// Return lower number
int bar(int a, int b)
{
	if (a >= b)
		return b;
	else
		return a;
}

// Throw exception
int foo2(int a, int b)
{
	throw "This function is broken...";
	return 0;
}

// Run the TestHarnessProject executable
int main()
{
    std::cout << "Hello World!\n"; 

	// Create array of TestHarness objects to iterate through
	std::vector<TestHarness> toTest;

	int logLevel = 0;

	// Populate our list of functions to test
	toTest.push_back(TestHarness(foo, 5, 4, 5));
	toTest.push_back(TestHarness(bar, 5, 4, 4));
	toTest.push_back(TestHarness(foo2, 5, 4, 5));

	// Iterate through our TestHarness objects and execute them
	for(std::vector<TestHarness>::iterator it = toTest.begin(); it != toTest.end(); ++it)
	{
		bool result = it->execute();
		if (result)
			std::cout << "Test Passed\n";
		else
			std::cout << "Test Failed\n";

	}

	exit(0);

}


