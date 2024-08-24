#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <cctype>
#include <algorithm>
#include <sstream>
#include <ctime>

# define ARGS	"Error: Wrong number of arguments"
# define OPEN	"Error: Couldn't open file: "
# define FORMAT	"Error: Wrong format found => "
# define EMPTY	"Error: Empty file: "
# define DATE	"Error: Bad date => "
# define NAN	"Error: Not a number => "
# define NPN	"Error: Not a positive number => "
# define LARGE	"Error: Number too large => "
# define NODATE	"Error: No date found before ot equal to => "
# define CSV_H	"date,exchange_rate"

class   BitcoinExchange
{
    public:
        BitcoinExchange(const std::string file);
        ~BitcoinExchange();
        BitcoinExchange &operator=(const BitcoinExchange &bt);
    private:
        std::map<time_t, double>  _data;

        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &bt);
		void	_initData(void);
		time_t	_dateConverter(const std::string &date) const;
        bool    _parseInput(std::ifstream &input);
        void    _parseLine(std::string date, std::string value);
        bool    _isValidDate(const std::string &date) const;
        void    _findDate(const std::string &date, double value);
};

#endif
