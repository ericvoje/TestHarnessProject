/////////////////////////////////////////////////////////////////////
// Executive.cpp - executes test functions                         //
// ver 1.0                                                         //
// Language:    C++, Visual Studio 2019                            //
// Application: Test Harness - Project 4,                          //
//              CSE687 - Object Oriented Design                    //
// Author:      Eric Voje, Kuohsun Tsai, Chaulladevi Bavda          //
//              ervoje@syr.edu, kutsai@syr.edu, cvbavda@syr.edu    //
/////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Executive.h"
#include "TestDriver.h"
#include "ITest.h"
#include "..\Logger\Logger.h"
#include "..\TestHarness\TestHarness.h"
#include "..\FileSystem\FileSystem.h"
#include <Windows.h>
#include "..\FirstDLL\MathLibrary.h"


#include "..\FirstDLL\MyClassOne.h" 
#include "..\FirstDLL\MyClassTwo.h" 
using namespace MyDLL;


using namespace Executive;
using namespace TestHarness;
using namespace Logging;



// Constructor
Executor::Executor()
{
	_log.write("Executor object created.\n");
}

// Destructor
Executor::~Executor()
{
}

// Function that handles execution of a TestedCode object
bool Executor::execute(TestedCode t)
{
	bool funcRet = false;
	//_log.write("Executor execution started.\n");
	Rslt::write("Executor execution started.\n");

	// Run the function within a safe try/catch block
	try {
		funcRet = (t.func() == 0);

		if (funcRet == true) {
			// Test Passed
			_log.write("Test Passed");
			if (!t.passMsg.empty())
				_log.write(t.passMsg);
		}
		else {
			// Test Failed
			_log.write("Test  Failed");
			if (!t.failMsg.empty())
				_log.write(t.failMsg);
		}
	}
	catch (const char* msg) {
		// Caught an exception
		std::cerr << msg;
		_log.write("Exception Thrown!");
		_log.write("Test Failed");
		if (!t.failMsg.empty())
			_log.write(t.failMsg);
	}

	return funcRet;
}

std::string getFile(std::string filename)
{
	std::string buffer;
	char c;

	std::ifstream in(filename);
	if (!in) {
		std::cout << filename << " File cannot be found";   exit(1);
	}

	while (in.get(c)) {
		buffer += c;
	}
	in.close();

	return buffer;
}

std::vector<std::string> getData(const std::string& text, std::string tags)
{
	std::vector<std::string> collection;
	unsigned int position = 0, start;

	while (true)
	{
		start = text.find("<" + tags, position);
		if (start == std::string::npos) {
			return collection;
		}

		start = text.find(">", start);
		start++;

		position = text.find("</" + tags, start);
		if (position == std::string::npos) {
			return collection;
		}
		collection.push_back(text.substr(start, position - start));
	}
}

void stripAllTags(std::string& text)
{
	unsigned int start = 0, pos;

	while (start < text.size())
	{
		start = text.find("<", start);
		if (start == std::string::npos) {
			break;
		}

		pos = text.find(">", start);
		if (pos == std::string::npos) {
			break;
		}
		text.erase(start, pos - start + 1);
	}
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
	std::cout << " The Test result " << std::endl;
	
	Rslt::attach(&std::cout);
	Rslt::start();
	Rslt::write("Testing Execute Package\n");

	Rslt::flush();

	//Test DLL
	std::cout << "Test DLL" << std::endl;

	MyClassOne sc1;
	std::cout << "default value of variable from dll : " << sc1.Getvar() << std::endl;
	sc1.Setvar(88);
	std::cout << "value of variable from dll : " << sc1.Getvar() << std::endl;

	MyClassTwo sc2;
	std::cout << "default value of variable from dll : " << sc2.Getvar() << std::endl;
	sc2.Setvar(200);
	std::cout << "value of variable from dll : " << sc2.Getvar() << std::endl;
	

	// Create our TestedCode objects
	TestedCode t1((int (*)()) testfunc1);
	t1.failMsg = "Example Test 1 Failed!";
	t1.passMsg = "Example Test 1 Passed!";
	TestedCode t2((int (*)()) testfunc2);
	TestedCode t3((int (*)()) testfunc3);

	Harness th = Harness();

	th.addTest(t1);
	th.addTest(t2);
	th.addTest(t3);

	th.execute();

	Rslt::flush();

	//ITest* testDriver = TestFactory::create();

	//testDriver->addTest(t1);
	//testDriver->addTest(t2);
	//testDriver->addTest(t3);
	//testDriver->execute();

	// ToDo: Create TestHarness
	
	// Parse TestRequest XML
	std::string filename = "TestRequest.xml";
	std::string tag = "TestDriver";
	
	bool stripTags = true;

	std::string text = getFile(filename);
	std::vector<std::string> all = getData(text, tag);
	for (std::string& s : all)
	{
		if (stripTags) stripAllTags(s);
		std::cout << s << '\n';
	}

	// Execute tests

	//log.logMessage(log_min, "End test.");

	//Test GUI
	/*
	Application^ appGUI = gcnew Application();
	appGUI->Run(gcnew testingWindow::TestingWindow());
	*/
	
	//DLL
	/*
	HMODULE dll = LoadLibrary(L".dll");
	if (NULL != dll) {
		//GetProcAddress(dll, L".dll");

		std::cout << "\n failed to load TestMe.dll\n\n";
		
	}
	else {
		std::cout << " cannot load the dll fie";
	}
	*/
	
	
	std::cin.get();
	return 0;
	
	
}
#endif