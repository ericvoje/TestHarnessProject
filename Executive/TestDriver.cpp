
#include <functional>
#include <string>
#include "TestDriver.h"
#include "Executive.h"
#include "..\Logger\Logger.h"

using namespace Executive;
//using namespace Logging;
using Show = Logging::StaticLogger<1>;

//////////////////////////
// TestDriver Functions
//////////////////////////

// TestDriver constructor
TestDriver::TestDriver()
{
	//_log.logMessage(log_verbose, "TestDriver created.");
	_nTests = 0;

	// Initialize test threads
	for (int i = 0; i < NTHREADS; i++)
	{
		_running[i] = false;
	}
}

// Start test threads
void TestDriver::start()
{

	// Loop through and start each thread
	for (int i = 0; i < NTHREADS; i++)
	{
		if (_running[i])
		{
			// Do nothing if already running
			continue;
		}
		else
		{
			_running[i] = true;
			// Function that will run in the thread
			std::function<void()> tp = [=](int n) {
				while (_running[n])
				{
					TestedCode test = _bq.deQ();

					Show::write("Starting Test");
					bool result = _exe.execute(test);
					if (result)
						Show::write(test.passMsg);
					else
						Show::write(test.failMsg);
				}
			};

			// Start thread
			_th[i] = std::thread(tp, i);
		}
	}

}

// Stop any running threads
void TestDriver::stop()
{
	// Loop through and stop each thread
	for (int i = 0; i < NTHREADS; i++)
	{
		_running[i] = false;
	}

	// Join each thread
	for (int i = 0; i < NTHREADS; i++)
	{
		_th[i].join();
	}

}

// Add test object
void TestDriver::addTest(TestedCode t)
{
	//_tests.push_back(t);
	_bq.enQ(t);
	_nTests++;
	//_log.logMessage(log_verbose, "Test added to TestDriver.");
}


// Execute all TestedCode objects held by this TestDriver
bool TestDriver::execute()
{
	int nTests = 0;
	int nPassed = 0;
	int nFailed = 0;
	bool overallResult = true;

	/*
	// Loop through each test and execute them one by one
	for (auto& test : _tests)
	{
		//_log.logMessage(log_min, "Test " + to_string(++nTests));
		bool result = _exe.execute((TestedCode) test);

		if (result)
			nPassed++;
		else
			nFailed++;

		overallResult &= result;
	}
	*/

	//_log.logMessage(log_min, "Total Tests : " + to_string(nTests));
	//_log.logMessage(log_min, "Tests Passed : " + to_string(nPassed));
	//_log.logMessage(log_min, "Tests Failed : " + to_string(nFailed));

	return overallResult;
}

// Return the number of tests this TestDriver contains
int TestDriver::nTests()
{
	return _nTests;
}
