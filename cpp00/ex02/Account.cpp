#include "Account.hpp"
#include <iostream>

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
    std::cout << _nbAccounts << std::endl;
    std::cout << _totalAmount << std::endl;
    std::cout << _totalNbDeposits << std::endl;
    std::cout << _totalNbWithdrawals << std::endl;
}

Account::Account(int initial_deposit)
{
    _amount = initial_deposit;
}

Account::Account() {}

Account::~Account() {}

void	Account::makeDeposit( int deposit )
{
    _totalNbDeposits++;
    this->_amount += deposit;
    this->_nbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    if (this->_amount - withdrawal < 0)
        return (false);
    _totalNbWithdrawals++;
    this->_amount -= withdrawal;
    this->_nbWithdrawals++;
}

int		Account::checkAmount( void ) const
{
    return (this->_amount);
}

void	Account::displayStatus( void ) const
{
    if (this->_amount > 0)
        std::cout << "OK" << std::endl;
}