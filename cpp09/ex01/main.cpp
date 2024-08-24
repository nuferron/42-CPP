#include "Rpn.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cerr << "Error: Bad number of arguments" << std::endl, 1);
    Rpn rpn;

    try
    {
        int result = rpn.calculator(argv[1]);
        std::cout << "Result: " << result << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}

