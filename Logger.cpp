#include <iostream>
#include <string>
#include <chrono> 
#include <ctime>

#include "Logger.h"

// Returns the LogLevel of our Logger instance
LogLevel Logger::getLogLevel()
{
	return level;
}

// Sets the LogLevel
void Logger::setLogLevel(LogLevel setLevel)
{
	// Check that the LogLevel is valid
	if (setLevel < log_min || setLevel > log_verbose) {
		level = log_verbose;
	}
	// Otherwise set the value to what they wanted
	level = setLevel;
}

// Function that only prints log messages that are allowed at our current LogLevel
void Logger::logMessage(LogLevel minLvl, std::string s)
{
	// Print timestamp if log_verbose level is set
	if (level == log_verbose) {
		//char str[26];
		//std::time_t result = std::time(nullptr);
		//std::cout << "[" << ctime_s(str, sizeof str, &result) << "] ";
		
	}
	// Only print values that are at or less than
	// our current LogLevel
	if (level >= minLvl) {
		std::cout << s << std::endl;
	}
}

Logger::Logger()
{
	this->level = log_min;
}

// Creates a new Logger with the given LogLevel
Logger::Logger(LogLevel logLevel)
{
	this->level = log_min;
	this->setLogLevel(logLevel);
}

Logger::~Logger()
{

}
