#pragma once

#ifndef TESTHARNESS_H
#define TESTHARNESS_H

// Object that contains all of the information to execute our function under test
class TestHarness {

private:
	int (*fcnPtr)(int, int);
	int argument1;
	int argument2;
	int expResp;
public:
	bool execute();

	TestHarness(int (*func)(int, int), int arg1, int arg2, int rc);
};



#endif TESTHARNESS_H