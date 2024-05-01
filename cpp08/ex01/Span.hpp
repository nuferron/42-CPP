#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <exception>

class   Span
{
    public:
        Span();
        Span(unsigned int n);
        Span(const Span &s);
        ~Span();
        Span    &operator=(const Span &s);
        void    addNumber(int num);
        int     shortestSpan();
        int     longestSpan();
        class   SpanOverflow: public std::exception {
            const char *what() const throw () {
                return ("Error: Span overflow");
            };
        }
    private:
        int             *_span;
        unsigned int    _total;
        unsigned int    _max;
};

#endif