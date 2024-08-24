#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &pm)
{
	this->_vec = pm._vec;
}

PmergeMe::~PmergeMe() {}

PmergeMe	&PmergeMe::operator=(const PmergeMe &pm)
{
	this->_vec = pm._vec;
	return (*this);
}

bool	PmergeMe::_isValidNum(char *str)
{
	while (*str && *str > '0' && *str < '9')
		str++;
	if (!*str)
		return (true);
	return (false);
}

void	PmergeMe::_parseInput(char **arr)
{
	for (size_t i = 0; arr[i]; i++)
	{
		double	num = std::atof(arr[i]);
		if (num < 0 || (num == 0 && !this->_isValidNum(arr[i])))
			throw std::invalid_argument("Invalid input");
		if (num > INT_MAX || num < INT_MIN)
			throw std::out_of_range("Input exceeds integer bounds");
		this->_vec.push_back(num);
	}
}

void	PmergeMe::_mergeSort(std::vector<int> &vec)
{
	size_t	length = vec.size();
	if (length <= 1)
		return ;
	size_t half = length / 2;
	std::vector<int>	lvec;
	std::vector<int>	rvec;
	for (size_t i = 0; i < half; i++)
		lvec.push_back(vec.at(i));
	for (size_t i = half; i < length; i++)
		rvec.push_back(vec.at(i));
	this->_mergeSort(lvec);
	this->_mergeSort(rvec);
	this->_merge(lvec, rvec, vec);
}

void	PmergeMe::_merge(std::vector<int> &lvec, std::vector<int> &rvec, std::vector<int> &vec)
{
	size_t	lsize = lvec.size(), rsize = rvec.size();
	size_t	lit = 0, rit = 0;

	vec.clear();
	while (lit < lsize && rit < rsize)
	{
		if (lvec.at(lit) < rvec.at(rit))
		{
			vec.push_back(lvec.at(lit));
			lit++;
		}
		else
		{
			vec.push_back(rvec.at(rit));
			rit++;
		}
	}
	while (lit < lsize)
		vec.push_back(lvec.at(lit++));
	while (rit < rsize)
		vec.push_back(rvec.at(rit++));
}

#include <unistd.h>
void	PmergeMe::print(char **arr)// us = microsecond -> ns = nanoseconds
{
	clock_t	start = clock();
	size_t	length;

	this->_parseInput(arr);
	length = this->_vec.size();
	std::cout << "Before: ";
	for (size_t i = 0; i < length; i++)
		std::cout << this->_vec.at(i) << " ";
	std::cout << std::endl << std::endl;
	this->_mergeSort(this->_vec);
	std::cout << "After: ";
	for (size_t i = 0; i < length; i++)
		std::cout << this->_vec.at(i) << " ";
	std::cout << std::endl << std::endl;
	std::cout << "Time to process a range of " << this->_vec.size()
			<< " with std::vector: " << 1000 * double(clock() - start) / double(CLOCKS_PER_SEC) << " ns"<< std::endl;
}
