#include "pch.h"
#include<iostream>
using namespace std;

#include "MyClassOne.h" 
#include "MyClassTwo.h" 
using namespace MyDLL;
using namespace std;


int main()
{
	cout << "DLL Test" << endl;

	MyClassOne sc1;
	cout << "default value of variable from dll : " << sc1.Getvar() << endl;
	sc1.Setvar(88);
	cout << "value of variable from dll : " << sc1.Getvar() << endl;

	MyClassTwo sc2;
	cout << "default value of variable from dll : " << sc2.Getvar() << endl;
	sc2.Setvar(200);
	cout << "value of variable from dll : " << sc2.Getvar() << endl;

	cin.get();

	return 0;
}