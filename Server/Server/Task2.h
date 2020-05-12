#pragma once
#include "Task.h"
class Task2 :
	public Task
{
public:
	Task2(long long op1, long long op2) :Task(op1, op2) {};

	std::string solve() override;
};

