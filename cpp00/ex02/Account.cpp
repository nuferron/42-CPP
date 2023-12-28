#include "Account.hpp"
#include <iostream>
#include <ctime>

/*static variables are initialized only once and are shared
by all objects of a class; thus, they must be initialized 
outside the class, using the scope resolution operator (::)*/
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
    return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
    return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
    return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
    return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";";
    std::cout << "total:" << _totalAmount << ";";
    std::cout << "deposits:" << _totalNbDeposits << ";";
    std::cout << "withdrawals:" << _totalNbWithdrawals << ";";
    std::cout << std::endl;
}

Account::Account(int initial_deposit)
{
    _displayTimestamp();
    _accountIndex = _nbAccounts++;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    _totalAmount += initial_deposit;
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "created" << std::endl;
}

Account::Account()
{
    _displayTimestamp();
    _accountIndex = _nbAccounts++;
    this->_amount = 0;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "created" << std::endl;
}

Account::~Account()
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "closed" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
    _displayTimestamp();
    _totalNbDeposits++;
    this->_amount += deposit;
    this->_nbDeposits++;
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << this->_amount - deposit << ";";
    std::cout << "deposit:" << deposit << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "nb_deposits:" << this->_nbDeposits << ";";
    std::cout << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << this->_amount << ";";
    if (this->_amount - withdrawal < 0)
    {
        std::cout << "withdrawal:refused" << std::endl;
        return (false);
    }
    _totalNbWithdrawals++;
    this->_amount -= withdrawal;
    this->_nbWithdrawals++;
    std::cout << "withdrawal:" << withdrawal << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "nb_withdrawals:" << this->_nbWithdrawals << ";";
    std::cout << std::endl;
    return (true);
}

int		Account::checkAmount( void ) const
{
    return (this->_amount);
}

void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "deposits:" << this->_nbDeposits << ";";
    std::cout << "withdrawals:" << this->_nbWithdrawals << ";";
    std::cout << std::endl;
}

void    Account::_displayTimestamp()
{
   time_t now = time(0);
   tm *ltm = localtime(&now);
   std::cout << "[" << 1900 + ltm->tm_year;
   std::cout << ltm->tm_mon + 1;
   if (ltm->tm_mday < 10)
    std::cout << "0";
   std::cout << ltm->tm_mday;
   std::cout << "_"<< ltm->tm_hour + 1;
   std::cout << ltm->tm_min;
   std::cout << ltm->tm_sec << "] ";
}