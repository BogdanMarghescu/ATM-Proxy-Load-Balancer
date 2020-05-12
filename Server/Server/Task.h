#pragma once
#include "ITask.h"
#include <Windows.h>
#include <random>
#include <iostream>
#include "BigInt.h"
class Task :
	public ITask
{
protected:
	long long		m_op1;
	long long		m_op2;
public:
	Task(long long op1, long long op2) :m_op1(op1), m_op2(op2) {};
};

