#ifndef LOGGER_H
#define LOGGER_H
/////////////////////////////////////////////////////////////////////
// Logger.h - print log messages, filtered by log level            //
// ver 1.0                                                         //
// Language:    C++, Visual Studio 2019                            //
// Application: Test Harness - Project 1,                          //
//              CSE687 - Object Oriented Design                    //
// Author:      Eric Voje, Kuohsun Tsai                            //
//              ervoje@syr.edu, kutsai@syr.edu                     //
/////////////////////////////////////////////////////////////////////
/*
* Package Operations:
* -------------------
* The Logger package defines the Log class, an object that handles writing
* messages to the log. The Log object can filter messages based on user
* preference, with 3 different levels of detail.
*
* Maintenance History:
* --------------------
* Version 1.0:
*   Initial version. Log object handles writing to the log.
*/

#include <string>

// Possible logging detail levels
enum LogLevel { log_min, log_med, log_verbose};

namespace Logger {

	// Class that handles logging messages.
	// Can set the log level to allow user to change
	// the level of detail that is printed in the logs.
	class Log {

	private:
		LogLevel level;

	public:
		LogLevel getLogLevel();
		void setLogLevel(LogLevel setLevel);
		void logMessage(LogLevel minLvl, std::string s);

		// Constructor
		Log();
		Log(LogLevel logLevel);
		~Log();

	};
}
#endif