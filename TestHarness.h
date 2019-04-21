

#ifndef TESTHARNESS_H
#define TESTHARNESS_H

#include "Logger.h"


namespace TestHarness {

	class testFunc {
	public:
		bool (*func)();
	};

	// Object that contains all of the information to execute our function under test
	class Harness {

	private:
		Logger::Log logger;

	public:
		bool execute(bool (*func)());
		bool execute(testFunc func);
		bool execute(std::vector<testFunc> funcVector);

		Harness(LogLevel logLevel);
		~Harness();
	};

}


#endif TESTHARNESS_H