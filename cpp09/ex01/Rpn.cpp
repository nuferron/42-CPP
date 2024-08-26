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
	std::string	tmp;
	std::istringstream	line;
	line.str(exp);

	lim[0] = INT_MIN;
	lim[1] = INT_MAX;
	while (std::getline(line, tmp, ' '))
	{
		if (tmp == "")
			continue ;
		if (this->_isOperator(tmp))
		{
			if (this->_stack.size() < 2)
				throw std::invalid_argument("Not enough operands");
			double second = this->_stack.top();
			this->_stack.pop();
			double first = this->_stack.top();
			this->_stack.pop();
			this->_stack.push(this->_doMath(first, second, tmp[0]));
			if (this->_stack.top() > lim[1] || this->_stack.top() < lim[0])
				throw std::out_of_range("The result exceeds integer limits");
		}
		else
		{
			int num = std::atoi(tmp.c_str());
			if ((num == 0 && this->_isNumber(tmp)) || (num > 9 || num < -9))
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

bool	Rpn::_isNumber(const std::string &num) const
{
	int i = 0;

	if (num == "")
		return (false);
	if (num[i] == '-' || num[i] == '+')
		i++;
	if (std::atoi(&num.c_str()[i]) == 0 && num[i] != 0)
		return (false);
	return (true);
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
