#include "Base64.h"

Base64* Base64::instance = nullptr;

Base64& Base64::getInstance()
{
	if (!Base64::instance)
	{
		instance = new Base64();
	}
	return *instance;
}

void Base64::destroyInstance()
{
	if (Base64::instance)
	{
		delete Base64::instance;
		Base64::instance = nullptr;
	}
}

std::string Base64::encode(const std::string& msg)
{
	std::string out;
	unsigned val = 0;
	int valb = -6;
	for (char c : msg)
	{
		val = (val << 8) + c;
		valb += 8;
		while (valb >= 0)
		{
			out.push_back("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[(val >> valb) & 0x3F]);
			valb -= 6;
		}
	}
	if (valb > -6) out.push_back("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[((val << 8) >> (valb + 8)) & 0x3F]);
	while (out.size() % 4) out.push_back('=');
	return out;
}

std::string Base64::decode(const std::string& msg)
{
	std::string out;
	std::vector<int> T(256, -1);
	for (int i = 0; i < 64; i++) T["ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[i]] = i;
	unsigned val = 0;
	int valb = -8;
	for (char c : msg)
	{
		if (T[c] == -1) break;
		val = (val << 6) + T[c];
		valb += 6;
		if (valb >= 0)
		{
			out.push_back(char((val >> valb) & 0xFF));
			valb -= 8;
		}
	}
	return out;
}
