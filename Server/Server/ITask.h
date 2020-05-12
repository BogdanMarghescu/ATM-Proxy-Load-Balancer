#pragma once
#include <string>

class ITask
{
public:
	static ITask* generate(int numarTask, int op1, int op2);
	virtual std::string solve() = 0;
};

