#pragma once
#include<iostream>
#include<vector>
using namespace std;

class User
{
private:
	static User* instance;
	string username, password;
	User(const string& user, const string& passwd) : username(user), password(passwd) { ; }
	User() : username(), password() { ; }
	User(const User&) = delete;
	~User() { ; }

public:
	static User& getInstance(const string& user, const string& passwd);
	static void destroyInstance();
};