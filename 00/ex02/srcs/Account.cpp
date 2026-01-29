/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 15:36:49 by ssawa             #+#    #+#             */
/*   Updated: 2026/01/28 15:45:38 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits= 0;
int	Account::_totalNbWithdrawals = 0;

// コンストラクタ
Account::Account( int initial_deposit)
{
	_accountIndex = getNbAccounts();
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex \
		<< ";amount:" << checkAmount() \
		<< ";created" << std::endl;
}

// デストラクタ
Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex \
		<< ";amount:" << checkAmount() \
		<< ";closed" << std::endl;
}

// getter (start)
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

int		Account::checkAmount( void ) const
{
	return(_amount);
}
// getter (end)


// display (start)
void	Account::_displayTimestamp( void )
{
	std::cout << "[19920104_091532] ";
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex \
		<< ";amount:" << checkAmount() \
		<< ";deposits:" << _nbDeposits \
		<< ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() \
		<< ";total:" << getTotalAmount() \
		<< ";deposits:" << getNbDeposits() \
		<< ";withdrawals:" << getNbWithdrawals() << std::endl;
}

// display (end)

// Deposit & Withdrawal
void	Account::makeDeposit( int deposit )
{
	int	p_amount = checkAmount();

	_amount += deposit;
	_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex \
		<< ";p_amount:" << p_amount \
		<< ";deposit:" << deposit \
		<< ";amount:" << checkAmount() \
		<< ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	int	p_amount = checkAmount();

	_displayTimestamp();
	std::cout << "index:" << _accountIndex \
		<< ";p_amount:" << p_amount \
		<< ";withdrawal:";
	if (checkAmount() >= withdrawal)
	{
		_amount -= withdrawal;
		_nbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;
		std::cout << withdrawal \
			<< ";amount:" << checkAmount() \
			<< ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		return (true);
	}
	else
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
}
