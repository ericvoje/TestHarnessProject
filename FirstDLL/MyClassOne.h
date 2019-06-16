#pragma once

namespace MyDLL
{
	class MyClassOne
	{
	private:
		int varone;
	public:
		__declspec(dllexport) MyClassOne();//constructor
		__declspec(dllexport) void Setvar(int val);
		__declspec(dllexport) int Getvar();
	};
}
