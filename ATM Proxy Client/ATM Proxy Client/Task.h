#pragma once
#include "ITask.h"

class Task :
	public ITask
{
protected:
	int		m_op1;
	int		m_op2;
	string	info;

public:
	Task(int op1, int op2) : m_op1(op1), m_op2(op2), info() {};
	string getInfo() { return info; }
};