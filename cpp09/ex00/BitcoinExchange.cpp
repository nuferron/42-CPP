#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &bt)
{
    this->_values = bt._values;
}

BitcoinExchange::BitcoinExchange(const char* file)
{
    std::ifstream input(file);

    if (!input.is_open())
    {
        std::cerr << OPEN << std::endl;
        return ;
    }
    if (this->_parseInput(input))
        return ;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &bt)
{
    this->_values = bt._values;
    return (*this);
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
		return (std::cerr << FORMAT << " => " << line << std::endl, false);
	//std::cout << "\033[1;31mparseInput: date " << line.substr(0, found);
	//std::cout << " value " << line.substr(found + 1) << "\033[0m" << std::endl;
	if (line.substr(0, found) != "date" && line.substr(found + 1) != "value")
	{
		std::cout << "if first line is not a header line" << std::endl;
		this->_parseLine(line.substr(0, found), line.substr(found + 1));
	}
	while (std::getline(input, line))
	{
		if ((found = line.find("|")) == std::string::npos)
			return (std::cerr << FORMAT << " => " << line << std::endl, false);
		//std::cout << "\033[1;32mparseInput: date " << line.substr(0, found);
		//std::cout << " value " << line.substr(found + 1) << "\033[0m" << std::endl;
		this->_parseLine(line.substr(0, found), line.substr(found + 1));
	}
	return (0);
}

void    BitcoinExchange::_parseLine(std::string date, std::string value) const
{
    int nval = std::atoi(value.c_str());

    if (!nval && value.find_first_not_of("0", 1) != std::string::npos)
    {
        std::cout << "Error: Not a number (" + value + ")." << std::endl;
        return ;
    }
    if (nval < 0)
    {
        std::cout << "Error: Not a positive number (" + value + ")." << std::endl;
        return ;
    }
    if (nval > 1000)
    {
        std::cout << "Error: Number too large (" + value + ")." << std::endl;
        return ;
    }
	//std::cout << "parseLine date " << date << " value " << value << std::endl;
    this->_findClosestDate(date, nval);
}

bool BitcoinExchange::_isValidDate(const std::string &date) const
{
    int year, month, day;
    char dash1, dash2;
    std::istringstream ss(date);
    ss >> year >> dash1 >> month >> dash2 >> day;

    if (ss.fail() || dash1 != '-' || dash2 != '-' || month < 1 || month > 12 || day < 1 || day > 31)
        return false;
    if (month == 2)
    {
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if ((!isLeap && day > 28) || (isLeap && day > 29))
            return false;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day > 30)
            return false;
    }
    return true;
}

bool BitcoinExchange::_findClosestDate(const std::string &inputDate, int value) const
{
    std::ifstream file("data.csv");
    if (!file.is_open())
    {
        std::cerr << OPEN << std::endl;
        return (1);
    }
    std::string line;
    std::string closestDate;
    float closestValue = 0.0f;
	bool	firstLine = true;

    while (std::getline(file, line))
    {
        std::istringstream lineStream(line);
        std::string date, valueStr;
        if (std::getline(lineStream, date, ',') && std::getline(lineStream, valueStr))
        {
			//std::cout << "findClosestDate lineStream " << lineStream.str() << " date " << date << std::endl;
            if (!this->_isValidDate(date) && firstLine)
				continue ;
            if (!this->_isValidDate(date) && !firstLine)
				throw std::runtime_error("Error: Invalid date in CSV");

            int comparison = date.compare(inputDate);
            if (comparison > 0)
                break;
            closestDate = date;
            closestValue = std::atof(valueStr.c_str());
        }
    }
    file.close();
    if (closestDate.empty())
        std::cerr << "Error: No date found before or equal to " << inputDate << "." << std::endl;
    std::cout << inputDate << " => " << value << " = " << closestValue * value << std::endl;
    return (0);
}
