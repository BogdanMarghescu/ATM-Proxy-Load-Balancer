#pragma once
#include "Task.h"

class Task3 : public Task
{
public:
	Task3(int op1, int op2) : Task(op1, op2) { createInfo(); };
	void createInfo();
};