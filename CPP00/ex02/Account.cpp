#include "Account.hpp"
#include <iostream>


int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	_displayTimestamp( void )
{

}

int Account::getNbAccounts()
{
    return _nbAccounts;
}

int Account::getTotalAmount()
{
    return _totalAmount;
}

int Account::getNbDeposits()
{
    return _totalNbDeposits;
}

int Account::getNbWithdrawals()
{
    return _totalNbWithdrawals;
}

Account::Account(int initial_deposit)
{
    this->_amount = initial_deposit;
    std::cout << "index:" << _accountIndex << ";amount:" << 42 << ";created";
    this->_accountIndex = getNbAccounts() + 1;
    _nbAccounts++;
}

Account::~Account()
{
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

void Account::displayAccountsInfos()
{
    std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount()  << ";deposits:" << getNbDeposits() << ";withdrawals:" <<getNbWithdrawals() << std::endl;
}

void Account::makeDeposit(int deposit)
{
    std::cout << "index:" << this->_accountIndex << ";p_amount" << this->_amount << ";depoist:" << deposit << ";amount:" << this->_amount + deposit << ";" << "nb_deposits:" <<  _nbDeposits;
    _amount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal)
{

}