#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <cctype>
#include <algorithm>
#include <sstream>
#include <ctime>

# define ARGS "\033[1;31mError: Wrong number of arguments\033[0m"
# define OPEN "\033[1;31mError: Couldn't open file\033[0m"
# define FORMAT "\033[1;31mError: Wrong format found\033[0m"
# define EMPTY "\033[1;31mError: Empty file\033[0m"

class   BitcoinExchange
{
    public:
        BitcoinExchange(const char* file);
        ~BitcoinExchange();
        BitcoinExchange &operator=(const BitcoinExchange &bt);
    private:
        std::multimap<std::string, int>  _values;
        bool    _parseInput(std::ifstream &input);
        void    _parseLine(std::string date, std::string value) const;
        bool    _isValidDate(const std::string &date) const;
        bool    _findClosestDate(const std::string &inputDate, int val) const;
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &bt);
};

#endif
