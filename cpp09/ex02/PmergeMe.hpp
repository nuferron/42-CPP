#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <ctime>
#include <vector>
#include <exception>
#include <climits>

class PmergeMe
{
	public:
		PmergeMe();
		~PmergeMe();
		void	print(char **);
	private:
		std::vector<int>	_vec;
		PmergeMe(const PmergeMe &pm);
		PmergeMe	&operator=(const PmergeMe &pm);
		bool	_isValidNum(char *str);
		void	_parseInput(char **argv);
		void	_mergeSort(std::vector<int> &vec);
		void	_merge(std::vector<int> &lvec, std::vector<int> &rvec, std::vector<int> &vec);

};

#endif
