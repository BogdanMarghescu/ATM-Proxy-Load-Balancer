#pragma once
#include "Task.h"

class Task2 : public Task
{
public:
	Task2(int op1, int op2) : Task(op1, op2) { createInfo(); };
	void createInfo();
};