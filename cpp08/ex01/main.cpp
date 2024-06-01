#include "Span.hpp"


void	test_range2(void)
{
	Span	span(20);
	std::vector<int>	vec;
	std::vector<int>::iterator it;

	vec.push_back(-3);
	vec.push_back(-20);
	vec.push_back(3);
	vec.push_back(20);
	it = vec.begin();
	it += 2;

	span.addNumber(100);
	span.addNumber(105);
	span.addNumber(110);
	span.addNumber(115);
	span.print();
	std::cout << "long " << span.longestSpan() << std::endl;
	std::cout << "short " << span.shortestSpan() << std::endl;
	span.addRange(it, vec.end());
	span.print();
	std::cout << "long " << span.longestSpan() << std::endl;
	std::cout << "short " << span.shortestSpan() << std::endl;
}

void	test_range(void)
{
	Span	span(5);
	std::vector<int>	vec;

	vec.push_back(-3);
	vec.push_back(-20);
	vec.push_back(3);
	vec.push_back(20);

	span.addNumber(100);
	span.addNumber(105);
	span.addNumber(110);
	span.addNumber(115);
	span.print();
	std::cout << "long " << span.longestSpan() << std::endl;
	std::cout << "short " << span.shortestSpan() << std::endl;
	span.addRange(vec);
	span.print();
	std::cout << "long " << span.longestSpan() << std::endl;
	std::cout << "short " << span.shortestSpan() << std::endl;
}

void	test_add2(void)
{
	Span	span(5);

	span.addNumber(INT_MAX);
	span.addNumber(0);
	span.addNumber(INT_MIN);
	span.addNumber(INT_MIN);
	span.print();
	std::cout << "long " << span.longestSpan() << std::endl;
	std::cout << "short " << span.shortestSpan() << std::endl;
}

void	test_add(void)
{
	Span	span(5);

	span.addNumber(30);
	span.addNumber(40);
	span.addNumber(55);
	span.addNumber(0);
	span.print();
	std::cout << "long " << span.longestSpan() << std::endl;
	std::cout << "short " << span.shortestSpan() << std::endl;
}

int main()
{
	try
	{
		std::cout << " --------------" << std::endl;
		std::cout << "|   TEST ADD   |" << std::endl;
		std::cout << " --------------" << std::endl;
		test_add();
	}
	catch (std::exception &ex)
	{
		std::cerr << ex.what() << std::endl;
	}
	try
	{
		std::cout << " ------------- " << std::endl;
		std::cout << "|  TEST ADD2  |" << std::endl;
		std::cout << " ------------- " << std::endl;
		test_add2();
	}
	catch (std::exception &ex)
	{
		std::cerr << ex.what() << std::endl;
	}
	try
	{
		std::cout << " ------------- " << std::endl;
		std::cout << "| TEST RANGE  |" << std::endl;
		std::cout << " ------------- " << std::endl;
		test_range();
	}
	catch (std::exception &ex)
	{
		std::cerr << ex.what() << std::endl;
	}
	try
	{
		std::cout << " ------------- " << std::endl;
		std::cout << "| TEST RANGE2 |" << std::endl;
		std::cout << " ------------- " << std::endl;
		test_range2();
	}
	catch (std::exception &ex)
	{
		std::cerr << ex.what() << std::endl;
	}
}
