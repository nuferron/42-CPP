#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <climits>

class	Rpn
{
	public:
		Rpn();
		~Rpn();
		double	calculator(const std::string expression);
	private:
		std::stack<double>	_stack;

		Rpn(const Rpn &r);
		Rpn	&operator=(const Rpn &r);
		bool	_isOperator(const std::string &op) const;
		bool	_isNumber(const std::string &num) const;
		double	_doMath(double f, double s, const char op);
};

#endif
