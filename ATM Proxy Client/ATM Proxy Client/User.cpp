#include "User.h"

User* User::instance = nullptr;

User& User::getInstance(const string& user, const string& passwd)
{
	if (!User::instance)
		User::instance = new User(user, passwd);
	return *User::instance;
}

void User::destroyInstance()
{
	if (instance)
	{
		delete instance;
		instance = nullptr;
	}
}