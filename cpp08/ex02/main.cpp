/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 20:15:38 by nuferron          #+#    #+#             */
/*   Updated: 2024/06/01 20:47:20 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

/*int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return (0);
}*/

void	test_ms_char()
{
	MutantStack<char>	ms;

	ms.push('a');
	ms.push('b');
	ms.push('c');
	ms.push('d');
	std::cout << "Top: " << ms.top() << std::endl;
	std::cout << "We pop the last element ('d')" << std::endl;
	ms.pop();
	std::cout << "Ms's size is " << ms.size() << std::endl;
	ms.push('e');
	ms.push('f');
	MutantStack<char>::iterator it = ms.begin();
	MutantStack<char>::iterator end = ms.end();
	while (it != end)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

void	test_ms()
{
	MutantStack<int>	ms;

	ms.push(1);
	ms.push(2);
	ms.push(3);
	ms.push(4);
	std::cout << "Top: " << ms.top() << std::endl;
	std::cout << "We pop the last element (4)" << std::endl;
	ms.pop();
	std::cout << "Ms's size is " << ms.size() << std::endl;
	ms.push(5);
	ms.push(6);
	MutantStack<int>::iterator it = ms.begin();
	MutantStack<int>::iterator end = ms.end();
	while (it != end)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

void	test_list()
{
	std::list<int>	ms;

	ms.push_back(1);
	ms.push_back(2);
	ms.push_back(3);
	ms.push_back(4);
	std::cout << "Top: " << ms.back() << std::endl;
	std::cout << "We pop_back the last element (4)" << std::endl;
	ms.pop_back();
	std::cout << "Ms's size is " << ms.size() << std::endl;
	ms.push_back(5);
	ms.push_back(6);
	std::list<int>::iterator it = ms.begin();
	std::list<int>::iterator end = ms.end();
	while (it != end)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

int main()
{
	std::cout << "TESTING MUTANT STACK CHAR" << std::endl;
	test_ms_char();
	std::cout << "TESTING MUTANT STACK" << std::endl;
	test_ms();
	std::cout << "TESTING LIST" << std::endl;
	test_list();
}
