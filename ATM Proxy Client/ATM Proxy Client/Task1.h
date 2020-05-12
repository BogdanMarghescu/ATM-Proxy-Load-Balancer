#pragma once
#include "Task.h"

class Task1 : public Task
{
public:
	Task1(int op1) : Task(op1, 0) { createInfo(); };
	void createInfo();
};