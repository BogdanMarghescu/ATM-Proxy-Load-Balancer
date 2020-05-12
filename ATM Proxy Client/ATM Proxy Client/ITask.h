#pragma once
#include"TaskException.h"

class ITask
{
public:
	static ITask* generate(int numarTask,int op1,int op2);
	virtual void createInfo() = 0;
};