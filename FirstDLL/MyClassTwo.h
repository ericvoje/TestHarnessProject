#pragma once
namespace MyDLL
{
	class MyClassTwo
	{
	private:
		int vartwo;
	public:
		__declspec(dllexport) MyClassTwo();//constructor
		__declspec(dllexport) void Setvar(int val);
		__declspec(dllexport) int Getvar();
	};
}