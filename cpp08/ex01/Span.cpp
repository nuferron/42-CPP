#include "Span.hpp"

Span::Span(): _size(0), _max_size(5) {}

Span::Span(unsigned int n): _size(0), _max_size(n) {}

Span::~Span() {}

Span    &Span::operator=(const Span &s)
{
	this->_size = s._size;
	this->_max_size = s._max_size;
	this->_span = s._span;
	return (*this);
}

void    Span::addNumber(int num)
{
	if (this->_size == this->_max_size)
		throw SpanOverflowException();
	this->_span.insert(num);
	this->_size++;
}

unsigned int	Span::shortestSpan(void)
{
	if (this->_size < 2)
		throw TooFewDataException();

	std::multiset<int>::iterator it = this->_span.begin();
	std::multiset<int>::iterator end = this->_span.end();
	std::multiset<int>::iterator next = it;
	next++;
	unsigned int span = *next - *it;
	unsigned int tmp;

	while (++next != end)
	{
		it++;
		tmp = *next - *it;
		if (tmp < span)
			span = tmp;
	}
	return (span);
}

unsigned int Span::longestSpan(void)
{
	if (this->_size < 2)
		throw TooFewDataException();
	return (*(--this->_span.end()) - *(this->_span.begin()));
}

void	Span::addRange(std::vector<int> vec)
{
	if (this->_size + vec.size() > this->_max_size)
		throw SpanOverflowException();

	std::vector<int>::iterator end = vec.end();

	for (std::vector<int>::iterator it = vec.begin(); it != end; it++)
	{
		this->_span.insert(*it);
		this->_size++;
	}
}

void	Span::addRange(std::vector<int>::iterator it, std::vector<int>::iterator end)
{
	while (it != end)
	{
		if (this->_size == this->_max_size)
			throw SpanOverflowException();
		this->_span.insert(*it);
		this->_size++;
		it++;
	}
}

const char	*Span::SpanOverflowException::what(void) const throw ()
{
	return ("Span is full");
}

const char	*Span::TooFewDataException::what(void) const throw ()
{
	return ("Data is not enough to find a span");
}

void	Span::print(void) const
{
	
	std::multiset<int>::iterator it = this->_span.begin();
	std::multiset<int>::iterator end = this->_span.end();
	while (it != end)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}
