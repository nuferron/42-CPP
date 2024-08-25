#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <ctime>
#include <vector>
#include <deque>
#include <exception>
#include <climits>

class PmergeMe
{
	public:
		PmergeMe(char **arr);
		~PmergeMe();
		void	print(void);
	private:
		std::vector<int>	_vec;
		std::deque<int>		_deq;
		char**				_arr;

		PmergeMe();
		PmergeMe(const PmergeMe &pm);
		PmergeMe	&operator=(const PmergeMe &pm);
		bool	_isValidNum(char *str);
		void	_parseInput(char **argv);
		void	_mergeSort(std::vector<int> &vec);
		void	_mergeSort(std::deque<int> &deq);
		void	_merge(std::deque<int> &ldeq, std::deque<int> &rdeq, std::deque<int> &deq);
		void	_merge(std::vector<int> &lvec, std::vector<int> &rvec, std::vector<int> &vec);
		template <typename T>
		void	_printVar(T &var, clock_t parseTime, const std::string type);

};

#endif
