#include "UserException.h"

UserException::UserException(int c) : Exception(c, "")
{
	switch (c)
	{
	case 1:		///	1 - wrong username
		message = "Incorrect username or password!";
		break;

	case 2:		///	3 - user already existent
		message = "User is already existent!";
		break;

	default:
		message = "Unknown user error!";
		break;
	}
}

string UserException::getError()
{
	string error = ("USER ACCOUNT ERROR (code = " + to_string(code) + "): " + message);
	return error;
}