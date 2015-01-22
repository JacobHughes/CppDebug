/*=======================================================
	Code written by Jacob Hughes

	Copyright (C) Jacob Hughes 2015

	Contact for use:

	yacolt@gmail.com
	https://github.com/JacobHughes/
=======================================================*/

#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <ctime>
#include <mutex>

//Different modes for the Logger
enum LoggerMode
{
	verbose,	//always output to cout
	silent		//do not output to cout
};

enum LoggerLevel
{
	normal,		//normal level messages
	critical	//critical level messages
};

using namespace std;

class Logger
{
	/*
		This is a singleton implementation of a logging class.
		The log() method is thread safe, and thus so is the operator<<

		The Logger maintains two log files, a fullLog (everything is logged here)
		and a critical log.

		Specific messages can be sent to the critical log by using the "critical"
		enum in the log() method.

		The logger can be made "silent" by setting the level. In silent mode, the
		logger will contine to append to log files, but will not output to cout.
		In verbose mode, appending will continue and cout will also be used for each
		message, regardless of LoggerLevel.
	*/
public:
	//Static instance to ensure only one Logger can exist
	static Logger & instance()
	{
		static Logger *instance = new Logger();
		return *instance;
	}

	~Logger();

	//Function to set the logging mode (verbose or silent)
	inline void setMode(LoggerMode m){ this->mode = m; };

	//operator<< to output to the normal level log file
	inline void operator << (const string &message) { this->log(normal, message); };
	
	//Function to log a message
	void log(LoggerLevel level, const string &message);

protected:
	//Constructor is protected / private
	Logger();

	//Set the default logging mode to be verbose
	LoggerMode mode = verbose;
	
	//Stream to output everything
	ofstream fullLog;

	//Stream to output critical flagged messages
	ofstream criticalLog;

	//Time and structures for handling time stamps
	time_t rawTime;
	struct tm timeInfo;
	string dateAddition;

	//Mutex for thread safe ofstreams
	mutex loggerMutex;
	
};

