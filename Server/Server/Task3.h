#pragma once
#include "Task.h"
class Task3 :
	public Task
{
public:
	Task3(long long op1, long long op2) :Task(op1, op2) {};

	std::string solve() override;
};

