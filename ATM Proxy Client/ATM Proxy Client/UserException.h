#pragma once
#include "Exception.h"
#include "User.h"

class UserException : public Exception
{
public:
	UserException(int c);	//1 - wrong username or password, 2 - user already existent
	string getError();
};