#include "Exception.h"

string Exception::getError()
{
	string error = ("GENERAL ERROR(code = " + to_string(code) + "): " + message);
	return error;
}