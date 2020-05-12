#include "TaskException.h"

string TaskException::getError()
{
	string error = ("TASK EXECUTION ERROR(code = " + to_string(code) + "): " + message);
	return error;
}