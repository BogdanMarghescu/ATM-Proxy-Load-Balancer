#pragma once
#include"Log.h"

class Exception
{
protected:
	int code;
	string message;
public:
	Exception() : code(0), message("Unknown Error!\n") { ; }
	Exception(int c, const string& msg) : code(c), message(msg) { ; }
	Exception(const Exception& ex) : code(ex.code), message(ex.message) { ; }
	const int getCode() const { return code; }
	const string& getMessage() const { return message; }
	virtual string getError();
};