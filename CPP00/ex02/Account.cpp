#include "Account.hpp"
#include <iostream>	// std::cout
#include <iomanip>	// std::setw, std::setfill
#include <ctime>	// std::time, std::localtime

// Le variabili static appartengono alla classe, non ai singoli oggetti:
// esistono in una sola copia condivisa e vanno definite una volta in un .cpp
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// ---------- Funzioni static: si chiamano come Account::getNbAccounts() ----------

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

// Formato del log: [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts()
		<< ";total:" << getTotalAmount()
		<< ";deposits:" << getNbDeposits()
		<< ";withdrawals:" << getNbWithdrawals() << std::endl;
}

// Stampa "[AAAAMMGG_HHMMSS] ". setfill('0') + setw(2) produce 04 invece di 4
void	Account::_displayTimestamp(void)
{
	std::time_t	now = std::time(NULL);
	std::tm		*t = std::localtime(&now);

	std::cout << "[" << (t->tm_year + 1900)
		<< std::setfill('0')
		<< std::setw(2) << (t->tm_mon + 1)
		<< std::setw(2) << t->tm_mday << "_"
		<< std::setw(2) << t->tm_hour
		<< std::setw(2) << t->tm_min
		<< std::setw(2) << t->tm_sec << "] "
		<< std::setfill(' ');
}

// ---------- Costruttore e distruttore ----------

// L'indice del nuovo conto è il numero di conti creati finora (0, 1, 2...)
Account::Account(int initial_deposit)
	: _accountIndex(_nbAccounts), _amount(initial_deposit),
	  _nbDeposits(0), _nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account(void)
{
	_nbAccounts--;
	_totalAmount -= _amount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";amount:" << _amount << ";closed" << std::endl;
}

// ---------- Funzioni membro ----------

// Formato: index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
void	Account::makeDeposit(int deposit)
{
	int	previous = _amount;

	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";p_amount:" << previous
		<< ";deposit:" << deposit
		<< ";amount:" << _amount
		<< ";nb_deposits:" << _nbDeposits << std::endl;
}

// Formato se va a buon fine: index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
// Formato se rifiutato:      index:0;p_amount:47;withdrawal:refused
bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
	if (withdrawal > checkAmount())
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	std::cout << ";withdrawal:" << withdrawal
		<< ";amount:" << _amount
		<< ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}

int	Account::checkAmount(void) const
{
	return (_amount);
}

// Formato: index:0;amount:42;deposits:0;withdrawals:0
void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";deposits:" << _nbDeposits
		<< ";withdrawals:" << _nbWithdrawals << std::endl;
}
