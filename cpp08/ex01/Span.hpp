#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <exception>
#include <set>
#include <vector>

class   Span
{
    public:
        Span();
        Span(unsigned int n);
        Span(const Span &s);
        ~Span();
        Span    &operator=(const Span &s);
        void    addNumber(int num);
		void	addRange(std::vector<int> vec);
		void	addRange(std::vector<int>::iterator it, std::vector<int>::iterator end);
		void	print(void) const;
        unsigned int     shortestSpan();
        unsigned int     longestSpan();

        class   SpanOverflowException;
        class   TooFewDataException;

    private:
        std::multiset<int>	_span;
        unsigned int    _size;
        unsigned int    _max_size;
};

class   Span::SpanOverflowException: public std::exception {
    const char *what() const throw ();
};

class   Span::TooFewDataException: public std::exception {
    const char *what() const throw ();
};

#endif
