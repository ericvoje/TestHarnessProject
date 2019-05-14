/////////////////////////////////////////////////////////////////////
// TestHarness.cpp - Handler for executing function tests          //
// ver 2.0                                                         //
// Language:    C++, Visual Studio 2019                            //
// Application: Test Harness - Project 2,                          //
//              CSE687 - Object Oriented Design                    //
// Author:      Eric Voje, Kuohsun Tsai                            //
//              ervoje@syr.edu, kutsai@syr.edu                     //
/////////////////////////////////////////////////////////////////////

#include <iostream>

#include "TestHarness.h"
#include "..\Logger\Logger.h"
#include "..\Executive\Executive.h"
#include "..\Executive\ITest.h"
#include "..\Executive\TestDriver.h"

using namespace TestHarness;
using namespace Executive;
using namespace Logger;
using namespace std;

/////////////////////////////////////////////////////////////////////
//
//    Harness Function Definitions
//
/////////////////////////////////////////////////////////////////////

// Execute any tests held by this harness
bool Harness::execute()
{
	_log.logMessage(_ll, "Executing tests.");
	bool result = _testDriver->execute();
	_log.logMessage(_ll, "Execution completed.");
	return result;
}

// Parse XML file for test instructions
void Harness::parseTestXML(std::string path)
{
	ifstream file(path);
	string line;

	// Open file
	if (!file.is_open())
	{
		// Open failed
		_log.logMessage(log_med, "Failed to open file at: " + path);
		return;
	}

	// Read XML file
	bool testfound = false;
	bool exefound = false;
	string testfile = "";
	string libpath = "";

	while (getline(file, line))
	{
		// Look for <TestRequest> tag
		if (!testfound)
		{
			if (line.substr(line.find("<"), line.find(">"))._Equal("TestRequest"))
			{
				// Found TestRequest object
				testfound = true;
			}
		}
		
		// Look for <exe> tag
		if (testfound && !exefound)
		{
			if (line.substr(line.find("<"), line.find(">"))._Equal("exe"))
			{
				// Found exe
				exefound = true;
				testfile = line.substr(line.find(">") + 1, line.rfind("<"));
			}
		}

		// Look for libraries or close brackets
		if (testfound && exefound)
		{
			if (line.substr(line.find("<"), line.find(">"))._Equal("/TestRequest"))
			{
				TestedCode t();
				_testDriver->addTest(t);

				testfound = false;
				exefound = false;
			}
		}
	}

	file.close();
}

// Create new TestHarness object
Harness::Harness(LogLevel logLevel)
{
	_ll = logLevel;
	_testDriver = TestFactory::create();
}

// Create new TestHarness object
Harness::~Harness()
{
	delete _testDriver;
}


#ifdef TEST_TESTHARNESS

int main()
{
	Log log(&cout, log_verbose);

	log.logMessage(log_min, "Testing TestHarness functions.");

	Harness th(log_min);
	th.parseTestXML("");

	bool result = th.execute();

	if (result)
		log.logMessage(log_min, "Test Passed!");
	else
		log.logMessage(log_min, "Test Failed.");

	log.logMessage(log_min, "End test.");
}

#endif

