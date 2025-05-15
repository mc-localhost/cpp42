/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasiuko <vvasiuko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:02:08 by vvasiuko          #+#    #+#             */
/*   Updated: 2025/04/03 11:34:23 by vvasiuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
	: _accountIndex(_nbAccounts),
	  _amount(initial_deposit),
	  _nbDeposits(0),
	  _nbWithdrawals(0)  {
	_nbAccounts++;
	_totalAmount += initial_deposit;
	// the first account creates and opens a log file? the others just write inside
	// [19920104_091532] index:0;amount:42;created
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
	<< ";amount:" << this->_amount
	<< ";created"
	<< std::endl;
}

Account::~Account() {
	// [19920104_091532] index:0;amount:47;closed
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
	<< ";amount:" << this->_amount
	<< ";closed"
	<< std::endl;
}

int Account::getNbAccounts() {
	return _nbAccounts;
}

int Account::getTotalAmount() {
	return _totalAmount;
}

int Account::getNbDeposits() {
	return _totalNbDeposits;
}

int Account::getNbWithdrawals() {
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos() {
	// [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts
	<< ";total:" << _totalAmount
	<< ";deposits:" << _totalNbDeposits
	<< ";withdrawals:" << _totalNbWithdrawals
	<< std::endl;
}

void Account::makeDeposit(int deposit) {
	this->_nbDeposits++;
	int p_amount = this->_amount;
	this->_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
	// [19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
	<< ";p_amount:" << p_amount
	<< ";deposit:" << deposit
	<< ";amount:" << this->_amount
	<< ";nb_deposits:" << this->_nbDeposits
	<< std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	int p_amount = this->_amount;
	if (p_amount >= withdrawal)
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		// [19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
		std::cout << "index:" << this->_accountIndex
		<< ";p_amount:" << p_amount
		<< ";withdrawal:" << withdrawal
		<< ";amount:" << this->_amount
		<< ";nb_withdrawals:" << this->_nbWithdrawals
		<< std::endl;
		return true;
	}
	else // [19920104_091532] index:0;p_amount:47;withdrawal:refused
	{
		std::cout << "index:" << this->_accountIndex
		<< ";p_amount:" << p_amount
		<< ";withdrawal:refused"
		<< std::endl;
		return false;
	}
}

int Account::checkAmount() const {
	return _amount;
}

void Account::displayStatus() const {
	// [19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
	<< ";amount:" << this->_amount
	<< ";deposits:" << this->_nbDeposits
	<< ";withdrawals:" << this->_nbWithdrawals
	<< std::endl;
}

void Account::_displayTimestamp() {
	time_t timestamp = time(NULL);
	struct tm datetime = *localtime(&timestamp);
	char output[20];

	strftime(output, 20, "[%Y%m%d_%H%M%S] ", &datetime);
	std::cout << output;
}
