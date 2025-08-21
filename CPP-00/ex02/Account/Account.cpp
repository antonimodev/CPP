#include "Account_copy.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// Static attributes are global for all instanced classes
Account::Account(int initial_deposit)
	: _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
	_accountIndex = _nbAccounts;
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "created"
		<< std::endl;
	_nbAccounts++;
	_totalAmount += initial_deposit;
}

Account::~Account() {
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "closed"
		<< std::endl;
	_nbAccounts--;
	_totalAmount -= _amount;
}

void	Account::makeDeposit(int deposit) {
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal) {
	if (_amount >= withdrawal) {
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		return true;
	}
	return false;
}

int		Account::checkAmount(void) const {
	return (_amount);
}

void	Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "deposits:" << _nbDeposits << ";"
		<< "withdrawals:" << _nbWithdrawals
		<< std::endl;
}

int	Account::getNbAccounts(void) {
	return _nbAccounts;
}

int	Account::getTotalAmount(void) {
	return _totalAmount;
}

int	Account::getNbDeposits(void) {
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals(void) {
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout
	<< "accounts:" << _nbAccounts << ";"
	<< "total:" << _totalAmount << ";"
	<< "deposits:" << _totalNbDeposits << ";"
	<< "withdrawals:" << _totalNbWithdrawals
	<< std::endl;
}

void	Account::_displayTimestamp(void) {
	std::time_t now = std::time(nullptr);	// Get actual time
	char		buf[20];	// Safe buffer to contain complete time format

	std::strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S] ", std::localtime(&now));
	std::cout << buf;
}
