#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
		return (std::cerr << ARGS << std::endl, 1);
	try
	{
    	BitcoinExchange bt(argv[1]);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
