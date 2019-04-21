/////////////////////////////////////////////////////////////////////
// Logger.cpp - print log messages, filtered by log level          //
// ver 1.0                                                         //
// Language:    C++, Visual Studio 2019                            //
// Application: Test Harness - Project 1,                          //
//              CSE687 - Object Oriented Design                    //
// Author:      Eric Voje, Kuohsun Tsai                            //
//              ervoje@syr.edu, kutsai@syr.edu                     //
/////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <chrono> 
#include <ctime>

#include "Logger.h"

namespace Logger {

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

			std::cout << "[" << str << "] ";
		}

		// Only print values that are at or less than
		// our current LogLevel
		if (level >= minLvl) {
			std::cout << s << std::endl;
		}
	}

	// Generic Log creator
	Log::Log()
	{
		this->level = log_min;
	}

	// Creates a new Logger with the given LogLevel
	Log::Log(LogLevel logLevel)
	{
		this->level = log_min;
		this->setLogLevel(logLevel);
	}

	// Delete Log type
	Log::~Log()
	{

	}

}