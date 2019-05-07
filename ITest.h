#ifndef ITEST_H
#define ITEST_H

#include "TestHarness.h"

namespace TestHarness {

	struct ITest {
		virtual ~ITest() {}
		virtual bool test() = 0;
		virtual void addTest(TestedCode t) = 0;
	};

	struct TestFactory
	{
		static ITest* create(int (*func)());
	};
}

#endif