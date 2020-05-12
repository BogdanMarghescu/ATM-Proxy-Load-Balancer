#pragma once
#include <iostream>
#include <vector>

class Base64
{
private:
	static Base64* instance;
	Base64() {};
	Base64(const Base64&) = delete;
	~Base64() {};

public:
	static Base64& getInstance();
	static void destroyInstance();
	static std::string encode(const std::string& msg);
	static std::string decode(const std::string& msg);
};