#pragma once
#include "Exception.h"

class ConnectException : public Exception
{
public:
	ConnectException(int c, const string& msg) : Exception(c, msg) { ; }
	string getError();
};