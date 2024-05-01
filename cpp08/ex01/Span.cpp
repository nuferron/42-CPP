#include "Span.hpp"

Span::Span(): _total(0), _max(0)
{
    this->_span = NULL;
}

Span::Span(unsigned int n): _total(0), _max(n)
{
    try {
        this->_span = new int[n];
    }
    catch (std::exception &ex) {
        std::cerr << ex.what() << std::endl;
    }
}

Span::~Span()
{
    delete [] this->_span;
}

Span    &Span::operator=(const Span &s)
{
    if (this->_span)
        delete [] this->_span;
    this->_max = s._max;
    this->_total = s._total;
    for (unsigned int i = 0; i < s._total; i++)
        this->_span[i] = s._span[i];
}

void    Span::addNumber(int num)
{
    if (this->_total == this->_max)
        throw SpanOverflow();
    this->_span[this->_total] = num;
    this->_total++;
}

int Span::shortestSpan()
{
    int min = this->_span[0] - this->_span[1];

    if (min < 0)
        min = -min;
    for (int i = 0; i < this->_total; i++)
    {
        
    }
}