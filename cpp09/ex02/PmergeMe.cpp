#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(char **arr): _arr(arr) {}

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
		if (num > INT_MAX)
			throw std::out_of_range("Input exceeds integer bounds");
		this->_vec.push_back(num);
		this->_deq.push_back(num);
	}
}

void	PmergeMe::_mergeSort(std::deque<int> &deq)
{
	size_t	length = deq.size();
	if (length <= 1)
		return ;
	size_t half = length / 2;
	std::deque<int>	ldeq;
	std::deque<int>	rdeq;
	for (size_t i = 0; i < half; i++)
		ldeq.push_back(deq.at(i));
	for (size_t i = half; i < length; i++)
		rdeq.push_back(deq.at(i));
	this->_mergeSort(ldeq);
	this->_mergeSort(rdeq);
	this->_merge(ldeq, rdeq, deq);
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

void	PmergeMe::_merge(std::deque<int> &ldeq, std::deque<int> &rdeq, std::deque<int> &deq)
{
	size_t	lsize = ldeq.size(), rsize = rdeq.size();
	size_t	lit = 0, rit = 0;

	deq.clear();
	while (lit < lsize && rit < rsize)
	{
		if (ldeq.at(lit) < rdeq.at(rit))
			deq.push_back(ldeq.at(lit++));
		else
			deq.push_back(rdeq.at(rit++));
	}
	while (lit < lsize)
		deq.push_back(ldeq.at(lit++));
	while (rit < rsize)
		deq.push_back(rdeq.at(rit++));
}

void	PmergeMe::_merge(std::vector<int> &lvec, std::vector<int> &rvec, std::vector<int> &vec)
{
	size_t	lsize = lvec.size(), rsize = rvec.size();
	size_t	lit = 0, rit = 0;

	vec.clear();
	while (lit < lsize && rit < rsize)
	{
		if (lvec.at(lit) < rvec.at(rit))
			vec.push_back(lvec.at(lit++));
		else
			vec.push_back(rvec.at(rit++));
	}
	while (lit < lsize)
		vec.push_back(lvec.at(lit++));
	while (rit < rsize)
		vec.push_back(rvec.at(rit++));
}

void	PmergeMe::print(void)// us = microsecond -> ns = nanoseconds
{
	clock_t	parseTime = clock();

	this->_parseInput(this->_arr);
	parseTime = clock() - parseTime;
	this->_printVar(this->_vec, parseTime, "vector");
	std::cout << std::endl;
	this->_printVar(this->_deq, parseTime, "deque");
}

template	<typename T>
void	PmergeMe::_printVar(T &var, clock_t parseTime, const std::string type)
{
	clock_t	start = clock();
	size_t	length = var.size();

	std::cout << "Before: ";
	for (size_t i = 0; i < length; i++)
		std::cout << var.at(i) << " ";
	std::cout << std::endl << std::endl;
	this->_mergeSort(var);
	std::cout << "After: ";
	for (size_t i = 0; i < length; i++)
		std::cout << var.at(i) << " ";
	std::cout << std::endl << std::endl;

	std::cout << "\033[1;33mTime to process a range of " << var.size()
		<< " elements with std::" << type << ": "
		<< 1000 * double(clock() - start + parseTime) / double(CLOCKS_PER_SEC)
		<< " ns\033[0m"<< std::endl;

}
