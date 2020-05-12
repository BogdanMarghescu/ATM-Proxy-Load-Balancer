#include "Task2.h"


std::string Task2::solve()
{
	std::cout << "TASK Power " << m_op1 << "^" << m_op2 << std::endl;

	Dodecahedron::Bigint a = m_op1;
	a = a.pow(m_op2);
	std::string result = "The result of the operation ";
	result = result + std::to_string(m_op1) + "^" + std::to_string(m_op2) + " is " + Dodecahedron::to_string(a) + "\n";
	
	std::random_device device;
	std::mt19937 generator(device());
	std::uniform_int_distribution<int> distribution(7000, 10000);

	Sleep(distribution(generator));
	return result;
}
