#pragma once
#include "Exception.h"

class TaskException : public Exception
{
public:
	TaskException(int c, const string& msg) : Exception(c, msg) { ; }
	string getError();
};