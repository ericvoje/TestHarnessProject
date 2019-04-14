#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "TestHarness.h"

// Execute the function under test and report the results
bool TestHarness::execute()
{

	try {
		int ret = fcnPtr(argument1, argument2);
		if (ret == expResp)
			return true;
		else
			return false;
	}
	catch (const char* msg) {
		//std::cout << "Exception " << e << "occurred. Test failed.\n";
		std::cerr << msg << "\n"; 
	}
	return false;
}

// Create a new TestHarness object by providing a function pointer
TestHarness::TestHarness(int (*func)(int, int), int arg1, int arg2, int rc)
{
	fcnPtr = func;
	argument1 = arg1;
	argument2 = arg2;
	expResp = rc;
}
