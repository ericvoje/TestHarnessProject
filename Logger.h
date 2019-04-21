

#ifndef LOGGER_H
#define LOGGER_H

#include <string>

// Possible logging levels
enum LogLevel { log_min, log_med, log_verbose};

namespace Logger
{

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