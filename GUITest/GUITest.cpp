#include "GUITest.h"

using namespace System;

using namespace System::Diagnostics;
using namespace System::Globalization;
using namespace System::IO;
using namespace System::Reflection;
using namespace System::Windows;
using namespace System::Windows::Data;

[System::STAThreadAttribute]

int main(array<System::String^>^ args)
{
	Application^ app = gcnew Application();

	app->Run(gcnew testingWindow::TestingWindow());
}