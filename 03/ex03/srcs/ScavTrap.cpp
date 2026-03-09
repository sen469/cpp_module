/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 20:21:49 by ssawa             #+#    #+#             */
/*   Updated: 2026/03/08 18:31:37 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>
#include <string>

ScavTrap::ScavTrap(): ClapTrap("defaultST"), _guarding_gate(false)
{
	std::cout << "ScavTrap: Constructor(no paramater) called" << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
}

ScavTrap::ScavTrap(const std::string &name): ClapTrap(name), _guarding_gate(false)
{
	std::cout << "ScavTrap: Constructor called" << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other): ClapTrap(other), _guarding_gate(other._guarding_gate)
{
	std::cout << "ScavTrap: Copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap: Destructor called" << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap: Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->_guarding_gate = other._guarding_gate;
	}
	return (*this);
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_hit_points == 0 || this->_energy_points == 0)
	{
		std::cout << "ScavTrap " << this->_name << " attacks failed" << std::endl;
		return;
	}
	this->_energy_points--;
	std::cout << "ScavTrap " << this->_name << " attacks " << target \
		<< ", causing " << this->_attack_damage << " points of damage!" \
		<< std::endl;
}

void	ScavTrap::guardGate()
{
	if (!this->_guarding_gate)
	{
		this->_guarding_gate = true;
		std::cout << "ScavTrap " << this->_name << " is now guarding the gate." << std::endl;
	}
	else
	{
		std::cout << "ScavTrap " << this->_name << " is already guarding the gate." << std::endl;
	}
}
