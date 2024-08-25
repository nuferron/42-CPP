#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc <= 2)
		return (std::cerr << "Error: Invalid number of arguments" << std::endl, 1);
	try
	{
		PmergeMe	pm(&argv[1]);

		pm.print();
	}
	catch (std::exception &ex)
	{
		std::cerr << ex.what() << std::endl;
	}
	return (0);
}
