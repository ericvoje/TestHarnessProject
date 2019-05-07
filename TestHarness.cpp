/////////////////////////////////////////////////////////////////////
// TestHarness.cpp - Handler for executing function tests          //
// ver 2.0                                                         //
// Language:    C++, Visual Studio 2019                            //
// Application: Test Harness - Project 2,                          //
//              CSE687 - Object Oriented Design                    //
// Author:      Eric Voje, Kuohsun Tsai                            //
//              ervoje@syr.edu, kutsai@syr.edu                     //
/////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

#include "TestHarness.h"
#include "Logger.h"

using namespace TestHarness;

/////////////////////////////////////////////////////////////////////
//
//    Harness Function Definitions
//
/////////////////////////////////////////////////////////////////////

// Execute the functions under test
bool Harness::execute()
{
	return driver.test();
}


// Destructor
// Remove Logger
Harness::~Harness()
{
	//delete logger;
}

// XML Parser, generates TestedCode objects
void Harness::parseTestXML(std::string xml)
{
	// Read XML string and genrate TestedCode object,
	// then add TestedCode to TestDriver object

	// ToDo: Create TestedCode object from XML
	TestedCode t;

	this->driver.addTest(t);
}

// Create a new TestHarness object by providing a function pointer
Harness::Harness(LogLevel logLevel)
{
	//logger = Logger::Log(logLevel);
	logger.setLogLevel(logLevel);
}

/////////////////////////////////////////////////////////////////////
//
//    TestedCode Function Definitions
//
/////////////////////////////////////////////////////////////////////

// Constructor for TestedCode object
TestedCode::TestedCode(int (*func)())
{
	this->func = func;
	this->passMsg = "";
	this->failMsg = "";
}

// Default constructor
TestedCode::TestedCode()
{

}

// Default destructor
TestedCode::~TestedCode()
{
	// ToDo
}

/////////////////////////////////////////////////////////////////////
//
//    TestDriver Function Definitions
//
/////////////////////////////////////////////////////////////////////

// Constructor for TestDriver class
TestDriver::TestDriver(int (*func)())
{
	TestedCode* t = new TestedCode(func);
	this->toTest.push_back(*t);
}

// Create empty TestDriver object
TestDriver::TestDriver()
{

}

// Deconstructor
TestDriver::~TestDriver()
{
	// Delete all TestedCode ojbects from toTest vector
	for (auto &t : this->toTest)
	{
		delete &t;
	}
}

// Method for executing an ITest object, which contains one or more test objects
bool TestDriver::test() {

	// Execute test functions 
	return executor.execute(toTest);
}
