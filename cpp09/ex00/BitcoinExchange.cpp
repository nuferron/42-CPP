#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &bt)
{
    this->_data = bt._data;
}

BitcoinExchange::BitcoinExchange(const std::string file)
{
    std::ifstream input(file);

    if (!input.is_open())
		std::runtime_error(OPEN + file);
	this->_initData();
    if (this->_parseInput(input))
        return ;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &bt)
{
    this->_data = bt._data;
    return (*this);
}

void	BitcoinExchange::_initData()
{
	std::string::size_type	found;
	std::ifstream	csv("data.csv");
	std::string		line;
	std::string		date;

	if (!csv.is_open())
		std::runtime_error(OPEN);
	if (!getline(csv, line))
		return (void)(std::cerr << EMPTY << "data.csv" << std::endl);
	if (line != CSV_H)
	{
		found = line.find(",");
		if (found == std::string::npos)
			return (void)(std::cerr << FORMAT << line << std::endl);
		date = line.substr(0, found);
		if (!this->_isValidDate(date))
			return (void)(std::cerr << DATE << line << std::endl);
		this->_data[this->_dateConverter(date)] = std::atof(line.substr(found + 1).c_str());
	}
	while (getline(csv, line))
	{
		found = line.find(",");
		if (found == std::string::npos)
			return (void)(std::cerr << FORMAT << line << std::endl);
		found = line.find(",");
		if (found == std::string::npos)
			return (void)(std::cerr << FORMAT << line << std::endl);
		date = line.substr(0, found);
		if (!this->_isValidDate(date))
			return (void)(std::cerr << DATE << line << std::endl);
		this->_data[this->_dateConverter(date)] = std::atof(line.substr(found + 1).c_str());
	}
}

time_t	BitcoinExchange::_dateConverter(const std::string &date) const
{
	struct tm	time;

	time.tm_year = std::atoi(date.substr(0, 4).c_str()) - 1900; // Number of years since 1900
	time.tm_mon = std::atoi(date.substr(5, 2).c_str()) - 1; // Number of months since January
	time.tm_mday = std::atoi(date.substr(8, 2).c_str());
	time.tm_hour = 12;
	time.tm_min = 0;
	time.tm_sec = 0;
	time.tm_isdst = 0;
	return (std::mktime(&time));
}

bool    BitcoinExchange::_parseInput(std::ifstream &input)
{
	std::string line;
	std::string::size_type found;
	
	if (!std::getline(input, line))
		throw std::runtime_error(EMPTY);
	line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());
	for (std::string::size_type i = 0; i < line.size(); i++)
		line[i] = std::tolower(line[i]);
	if ((found = line.find("|")) == std::string::npos)
		return (std::cerr << FORMAT << line << std::endl, false);
	if (line.substr(0, found) != "date" && line.substr(found + 1) != "value")
		this->_parseLine(line.substr(0, found), line.substr(found + 1));
	while (std::getline(input, line))
	{
		if ((found = line.find("|")) == std::string::npos)
		{
			std::cerr << FORMAT << line << std::endl;
			continue ;
		}
		if (!this->_isValidDate(line.substr(0, found)))
		{
			std::cerr << DATE << line.substr(0, found) << std::endl;
			continue ;
		}
		this->_parseLine(line.substr(0, found), line.substr(found + 1));
	}
	return (0);
}

void    BitcoinExchange::_parseLine(std::string date, std::string value)
{
    double nval = std::atof(value.c_str());

    if (!nval && value.find_first_not_of("0", 1) != std::string::npos)
		return (void)(std::cerr << NAN << value << std::endl);
    if (nval < 0)
		return (void)(std::cerr << NPN << value << std::endl);
    if (nval > 1000)
		return (void)(std::cerr << LARGE << value << std::endl);
    this->_findDate(date, nval);
}

bool BitcoinExchange::_isValidDate(const std::string &date) const
{
    int year, month, day;
    char dash1, dash2;
    std::istringstream ss(date);
    ss >> year >> dash1 >> month >> dash2 >> day;

    if (ss.fail() || dash1 != '-' || dash2 != '-' || month < 1 || month > 12 || day < 1 || day > 31)
        return (false);
    if (month == 2)
    {
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if ((!isLeap && day > 28) || (isLeap && day > 29))
            return (false);
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day > 30)
            return (false);
    }
    return (true);
}

void	BitcoinExchange::_findDate(const std::string &date, double value)
{
	std::map<time_t, double>::iterator	it;
	time_t	timestamp = this->_dateConverter(date);

	it = this->_data.find(timestamp);
	if (it != this->_data.end())
	{
		return (void)(std::cout << date << " => " << value << " = " << value * it->second << std::endl);
	}
	for (it = this->_data.begin(); it != this->_data.end(); it++)
	{
		if (timestamp <= it->first)
			break ;
	}
	if (it == this->_data.begin())
		return (void)(std::cerr << "Error: No data found => " + date << std::endl);
	if (it->first == timestamp)
		std::cout << date << " => " << value << " = " << value * it->second << std::endl;
	else
		std::cout << date << " => " << value << " = " << value * (--it)->second << std::endl;
}
