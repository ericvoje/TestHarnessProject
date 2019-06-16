#include "MyClassTwo.h"

namespace MyDLL
{
	MyClassTwo::MyClassTwo()
	{
		vartwo = 345;
	}

	void MyClassTwo::Setvar(int val)
	{
		vartwo = val;
	}

	int MyClassTwo::Getvar()
	{
		return vartwo;
	}
}