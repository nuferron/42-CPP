#include "Rpn.hpp"

Rpn::Rpn() {}

Rpn::Rpn(const Rpn &r)
{
	this->_stack = r._stack;
}

Rpn::~Rpn() {}

Rpn	&Rpn::operator=(const Rpn &r)
{
	this->_stack = r._stack;
	return (*this);
}

double	Rpn::calculator(const std::string exp)
{
	double	lim[2];

	lim[0] = INT_MIN;
	lim[1] = INT_MAX;
	for (std::string::size_type i = 0; i < exp.size(); i++)
	{
		if (exp[i] == ' ')
			continue ;
		if (this->_isOperator(exp[i]))
		{
			if (this->_stack.size() < 2)
				throw std::invalid_argument("Not enough operands");
			double second = this->_stack.top();
			this->_stack.pop();
			double first = this->_stack.top();
			this->_stack.pop();
			this->_stack.push(this->_doMath(first, second, exp[i]));
			if (this->_stack.top() > lim[1] || this->_stack.top() < lim[0])
				throw std::out_of_range("The result exceeds integer limits");
		}
		else
		{
			int num = std::atoi(&exp[i]);
			if ((exp[i] != '0' && num == 0) || (num > 9 || num < -9))
				throw std::invalid_argument("Unexpected input");
			this->_stack.push(num);
		}
	}
	if (this->_stack.size() != 1)
		throw std::length_error("Too many operands");
	return (this->_stack.top());
}

bool	Rpn::_isOperator(const char op)
{
	if (op == '+' || op == '-' || op == '*' || op == '/')
		return (true);
	return (false);
}

double	Rpn::_doMath(double f, double s, const char op)
{
	switch (op)
	{
		case '+':
			return (f + s);
		case '-':
			return (f - s);
		case '*':
			return (f * s);
		case '/':
		{
			if (s == 0)
				throw std::out_of_range("Zero in the denominator => Undefined result");
			return (f / s);
		}
		default:
			throw std::invalid_argument("Unknown operator");
	}
}
