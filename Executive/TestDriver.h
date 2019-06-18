#ifndef TESTDRIVER_H
#define TESTDRIVER_H
/////////////////////////////////////////////////////////////////////
// TestDrvier.h - Class that holds and manages function tests      //
// ver 1.0                                                         //
// Language:    C++, Visual Studio 2019                            //
// Application: Test Harness - Project 2,                          //
//              CSE687 - Object Oriented Design                    //
// Author:      Eric Voje, Kuohsun Tsai                            //
//              ervoje@syr.edu, kutsai@syr.edu                     //
/////////////////////////////////////////////////////////////////////


#include <string>
#include <thread>
#include <vector>

#include "ITest.h"
#include "Executive.h"
#include "..\Logger\Logger.h"

#define NTHREADS 1

namespace Executive
{

	// TestDriver class holds all relevant data for a batch of tests
	class TestDriver :
		public ITest
	{
	public:
		TestDriver();
		~TestDriver()
		{
			stop();
		}

		void addTest(TestedCode t);
		void start();
		void stop();
		bool execute();
		int nTests();

	private:
		Executor _exe;
		std::thread _th[NTHREADS];
		bool _running[NTHREADS];
		//std::vector<TestedCode> _tests;
		Async::BlockingQueue<TestedCode> _bq = Async::BlockingQueue<TestedCode>();
		int _nTests = 0;
	};

	// Factory to create new TestDriver objects
	inline ITest* TestFactory::create()
	{
		return new TestDriver();
	}

}

#endif