/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 21:28:48 by smariapp          #+#    #+#             */
/*   Updated: 2026/06/20 19:11:38 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <stdio.h>
#include <time.h>
#include <string>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void)
{
	return _nbAccounts;
}
int Account::getTotalAmount(void)
{
	return _totalAmount;
}
int Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}
int Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}
void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:";
	std::cout << getNbAccounts();
	std::cout << ";total:";
	std::cout << getTotalAmount();
	std::cout << ";deposits:";
	std::cout << getNbDeposits();
	std::cout << ";withdrawals:";
	std::cout << getNbWithdrawals() << std::endl;
}

Account::Account(int initial_deposit): _accountIndex(getNbAccounts()), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	_nbAccounts += 1;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << initial_deposit << ";created" << std::endl;

}
Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void Account::makeDeposit(int deposit)
{
	int prev = _amount;
	if (deposit > 0)
	{
		_amount += deposit;
		_totalAmount += deposit;
		_nbDeposits += 1;
		_totalNbDeposits += 1;
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";p_amount:" << prev << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
		return;
	}
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << prev << ";deposit:refused" << std::endl;

}
bool Account::makeWithdrawal(int withdrawal)
{
	int prev = _amount;
	if (withdrawal > 0 && withdrawal < _amount)
	{
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals += 1;
		_totalNbWithdrawals += 1;
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";p_amount:" << prev << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		return true;
	}
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << prev << ";withdrawal:refused" << std::endl;
	return false;
}
int Account::checkAmount(void) const
{
	return _amount;
}
void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void)
{
	time_t rawtime;
	struct tm *timeInfo;
	std::string formattedTime;

	time(&rawtime);
	timeInfo = localtime(&rawtime);

	//format: YYYYMMDD_HHMMSS
	std::cout << '[' << (timeInfo->tm_year + 1900);
	if (timeInfo->tm_mon < 10)
		std::cout << '0';
	std::cout << timeInfo->tm_mon;
	if (timeInfo->tm_mday < 10)
		std::cout << '0';	
	std::cout << timeInfo->tm_mday << '_';
	if (timeInfo->tm_hour < 10)
		std::cout << '0';	
	std::cout << timeInfo->tm_hour;
	if (timeInfo->tm_min < 10)
		std::cout << '0';	
	std::cout << timeInfo->tm_min;	
	if (timeInfo->tm_sec < 10)
		std::cout << '0';	
	std::cout << timeInfo->tm_sec << "] ";
}

Account::Account(void)
{}