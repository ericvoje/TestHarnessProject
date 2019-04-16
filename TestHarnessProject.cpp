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
    std::cout << "Hello World!\n";

	// Create array of TestHarness objects to iterate through
	//std::vector<TestHarness> toTest;

	// Populate our list of functions to test
	//toTest.push_back(TestHarness(foo, 5, 4, 5));
	//toTest.push_back(TestHarness(bar, 5, 4, 4));
	//toTest.push_back(TestHarness(foo2, 5, 4, 5));

	// Iterate through our TestHarness objects and execute them
	/*for(std::vector<TestHarness>::iterator it = toTest.begin(); it != toTest.end(); ++it)
	{
		bool result = it->execute();
		if (result)
			std::cout << "Test Passed\n";
		else
			std::cout << "Test Failed\n";

	}*/

	TestHarness toTest = TestHarness(log_verbose);

	toTest.execute(foo);
	toTest.execute(bar);
	toTest.execute(foo2);


	exit(0);

}


