#include "pch.h"
#include "MyClassOne.h"

namespace MyDLL
{
	MyClassOne::MyClassOne()
	{
		varone = 123;
	}

	void MyClassOne::Setvar(int val)
	{
		varone = val;
	}

	int MyClassOne::Getvar()
	{
		return varone;
	}
}