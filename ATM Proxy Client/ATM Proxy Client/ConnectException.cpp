#include "ConnectException.h"

string ConnectException::getError()
{
	string error = ("CONNECTION ERROR (code = " + to_string(code) + "): " + message);
	return error;
}