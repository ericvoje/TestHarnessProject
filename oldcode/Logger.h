#ifndef LOGGER_H
#define LOGGER_H
/////////////////////////////////////////////////////////////////////
// Logger.h - print log messages, filtered by log level            //
// ver 2.0                                                         //
// Language:    C++, Visual Studio 2019                            //
// Application: Test Harness - Project 2,                          //
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
*
* Version 2.0:
*
*/

#include <string>
#include <iostream>
#include <fstream>

// Possible logging detail levels
enum LogLevel { log_min, log_med, log_verbose};

namespace Logger {

	// Class that handles logging messages.
	// Can set the log level to allow user to change
	// the level of detail that is printed in the logs.
	class Log {
	public:
		LogLevel getLogLevel();
		void setLogLevel(LogLevel setLevel);
		void logMessage(LogLevel minLvl, std::string s);
		void setStream(std::ostream *fp);

		// Constructors
		Log();
		Log(LogLevel logLevel);
		~Log();

		// Operators
		Log(const Log&) = delete;
		Log& operator=(const Log&) = delete;

	private:
		LogLevel level;
		std::ostream* _out = &std::cout;
	};
}
#endif