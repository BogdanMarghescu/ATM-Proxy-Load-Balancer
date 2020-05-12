#pragma once
#include "Task.h"
class Task1 :
	public Task
{
public:
	Task1(long long op1, long long op2) :Task(op1, op2) {};

	std::string solve() override;
};

