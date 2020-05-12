#include "TaskGenerator.h"
ITask* ITask::generate(int numarTask, int op1, int op2)
{
	switch (numarTask)
	{
		case 1:
			return new Task1(op1, op2);
			break;
		case 2:
			return new Task2(op1, op2);
			break;
		case 3:
			return new Task3(op1, op2);
			break;
	}
}