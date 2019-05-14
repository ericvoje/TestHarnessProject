/////////////////////////////////////////////////////////////////////
// Logger.cpp - print log messages, filtered by log level          //
// ver 2.0                                                         //
// Language:    C++, Visual Studio 2019                            //
// Application: Test Harness - Project 2,                          //
//              CSE687 - Object Oriented Design                    //
// Author:      Eric Voje, Kuohsun Tsai                            //
//              ervoje@syr.edu, kutsai@syr.edu                     //
/////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <chrono> 
#include <ctime>

#include "Logger.h"

using namespace Logger;
using namespace std;

// Returns the LogLevel of our Log instance
LogLevel Log::getLogLevel()
{
	return level;
}

// Sets the LogLevel
void Log::setLogLevel(LogLevel setLevel)
{
	// Check that the LogLevel is valid
	if (setLevel < log_min || setLevel > log_verbose) {
		level = log_verbose;
	}
	// Otherwise set the value to what they wanted
	level = setLevel;
}

// Function that only prints log messages that are allowed at our current LogLevel
void Log::logMessage(LogLevel minLvl, std::string s)
{
	// Always print timestamp if log_verbose level is set
	if (level == log_verbose) {

		time_t rawtime;
		struct tm timeinfo;
		char buffer[80];

		time(&rawtime);
		localtime_s(&timeinfo, &rawtime);

		strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", &timeinfo);
		std::string str(buffer);

		*_out << "[" << str << "] ";
	}

	// Only print values that are at or less than
	// our current LogLevel
	if (level >= minLvl) {
		*_out << s << std::endl;
	}
}

// Default Log constructor
Log::Log()
{
	setLogLevel(log_verbose);
}

// Creates a new Logger with the given LogLevel
Log::Log(LogLevel logLevel)
{
	setLogLevel(logLevel);
}

// Creates new Log log with given logLevel and output stream
Log::Log(ostream *fp, LogLevel logLevel)
{
	setLogLevel(logLevel);
	setStream(fp);
}

// Set the output stream of the Log
void Log::setStream(std::ostream *fp) {
	_out = fp;
}

#ifdef TEST_LOGGER

// Main 
int main()
{

	Log log(&cout, log_verbose);

	log.logMessage(log_min, "Log Test Beginning.");

	log.logMessage(log_verbose, "Verbose log message.");

	log.logMessage(log_min, "Min log message.");

	log.logMessage(log_verbose, "End log test.");

}

#endif