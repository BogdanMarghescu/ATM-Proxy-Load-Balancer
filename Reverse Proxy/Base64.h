#pragma once
#include <iostream>
#include <vector>
class Base64
{
public:
	static Base64& getInstance();
	static void destroyInstance();

	std::string encode(const std::string& msg);
	std::string decode(const std::string& msg);
private:
	static Base64* instance;

	Base64() {};
	Base64(const Base64&) = delete;
	~Base64() {};
};

