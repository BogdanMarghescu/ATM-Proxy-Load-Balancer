#include "Task1.h"

std::string Task1::solve()
{
	std::cout << "TASK Factorial " << m_op1 << "!" << std::endl;

	Dodecahedron::Bigint a = Dodecahedron::factorial(m_op1);
	std::string result = "The result of the operation ";
	result = result + std::to_string(m_op1) + "! is " + Dodecahedron::to_string(a) + "\n";

	std::random_device device;
	std::mt19937 generator(device());
	std::uniform_int_distribution<int> distribution(10000, 13000);

	Sleep(distribution(generator));
	return result;
}
