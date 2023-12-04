#include "Account.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>
#include <locale>

// static first
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp( void )
{
	std::time_t time;
	std::tm *tm;

	time = std::time(NULL);
	tm = std::localtime(&time);
	std::cout << '['
		<< std::setw(2) << std::setfill('0') << tm->tm_year + 1900
		<< std::setw(2) << std::setfill('0') << tm->tm_mday
		<< std::setw(2) << std::setfill('0') << tm->tm_mon + 1
		<< '_'
		<< std::setw(2) << std::setfill('0') << tm->tm_hour
		<< std::setw(2) << std::setfill('0') << tm->tm_min
		<< std::setw(2) << std::setfill('0') << tm->tm_sec
		<< "] ";
	// std::cout << "[19920104_091532] ";
}

int		Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int		Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int		Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int		Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

Account::Account( int initial_deposit )
{
	// this instance
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	// general static info
	Account::_totalAmount += this->_amount;
	Account::_nbAccounts++;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "amount:" << this->checkAmount() << ";"
		<< "created" << std::endl;
}

Account::~Account( void )
{
	// lust logs
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';'
		<< "amount:" << this->checkAmount() << ';'
		<< "closed" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	// confiramtion
	this->_amount += deposit;
	this->_nbDeposits++;

	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';'
		<< "p_amount:" << this->checkAmount() - deposit << ';'
		<< "deposit:" << deposit << ';'
		<< "amount:" << this->checkAmount() << ';'
		<< "nb_deposits:" << this->_nbDeposits << std::endl;

}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (_amount - withdrawal < 0)
	{
		// declain
		Account::_displayTimestamp();
		std::cout << "index:" << this->_accountIndex << ';'
			<< "p_amount:" << this->checkAmount() << ';'
			<< "withdrawal:" << "refused" << std::endl;

		return (false);
	}
	else
	{
		// confirmation
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;

		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;

		Account::_displayTimestamp();
		std::cout << "index:" << this->_accountIndex << ';'
			<< "p_amount:" << this->checkAmount() + withdrawal << ';'
			<< "withdrawal:" << withdrawal << ';'
			<< "amount:" << this->checkAmount() << ';'
			<< "nb_withdrawals:" << this->_nbWithdrawals << std::endl;

		return (true);
	}
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::displayStatus( void ) const
{
	// just logs
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "amount:" << this->checkAmount() << ";"
		<< "deposits:" << this->_nbDeposits << ";"
		<< "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::displayAccountsInfos( void )
{
	// just logs
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";"
		<< "total:" << Account::getTotalAmount() << ";"
		<< "deposits:" << Account::getNbDeposits() << ";"
		<< "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}
