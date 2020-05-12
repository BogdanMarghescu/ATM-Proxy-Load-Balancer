#include "Task3.h"

double nthRoot(long long A, long long N)
{
	// intially guessing a random number between 
	// 0 and 9 
	double xPre = rand() % 10;

	//  smaller eps, denotes more accuracy 
	double eps = 1e-3;

	// initializing difference between two 
	// roots by INT_MAX 
	double delX = INT_MAX;

	//  xK denotes current value of x 
	double xK;

	//  loop untill we reach desired accuracy 
	while (delX > eps)
	{
		//  calculating current value from previous 
		// value by newton's method 
		xK = ((N - 1.0) * xPre +
			(double)A / pow(xPre, N - 1)) / (double)N;
		delX = abs(xK - xPre);
		xPre = xK;
	}

	return xK;
}

std::string Task3::solve()
{
	std::cout << "TASK Radical of order " << m_op2 << " from " << m_op1 << std::endl;

	double res = nthRoot(m_op1, m_op2);
	std::string result = "The result of radical of order  ";
	result = result + std::to_string(m_op2) + "  from  " + std::to_string(m_op1) + "  is  " + std::to_string(res) + "\n";
	
	std::random_device device;
	std::mt19937 generator(device());
	std::uniform_int_distribution<int> distribution(5000, 7000);

	Sleep(distribution(generator));
	return result;
}
