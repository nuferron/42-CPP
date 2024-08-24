#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc <= 2)
		return (std::cerr << "Error: Invalid nuber of arguments" << std::endl, 1);
	try
	{
		PmergeMe	pm;

		pm.print(&argv[1]);
	}
	catch (std::exception &ex)
	{
		std::cerr << ex.what() << std::endl;
	}
	return (0);
}
