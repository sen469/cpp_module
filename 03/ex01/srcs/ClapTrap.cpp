/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 17:51:49 by ssawa             #+#    #+#             */
/*   Updated: 2026/02/15 20:23:44 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <string>
#include <iostream>
#include <climits>

ClapTrap::ClapTrap() : _name("default"), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "Constructor(no paramater) called" << std::endl;

}

ClapTrap::ClapTrap(std::string name): _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "ClapTrap: Constructor called" << std::endl;
}


ClapTrap::ClapTrap(const ClapTrap &other): _name(other._name), \
											_hit_points(other._hit_points), \
											_energy_points(other._energy_points), \
											_attack_damage(other._attack_damage)
{
	std::cout << "ClapTrap: Copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap: Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hit_points = other._hit_points;
		this->_energy_points = other._energy_points;
		this->_attack_damage = other._attack_damage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap: Destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->_hit_points == 0 || this->_energy_points == 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacks failed" << std::endl;
		return;
	}
	this->_energy_points--;
	std::cout << "ClapTrap " << this->_name << " attacks " << target \
		<< ", causing " << this->_attack_damage << " points of damage!" \
		<< std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	unsigned int	tmp = this->_hit_points;
	this->_hit_points -= std::min(amount, this->_hit_points);
	std::cout << "ClapTrap " << this->_name << " take damage HP: " \
		<< tmp << " -> " << this->_hit_points << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	unsigned int	tmp = this->_hit_points;
	if (this->_hit_points == 0 || this->_energy_points == 0)
	{
		std::cout << "ClapTrap " << this->_name << " beRepaired failed" << std::endl;
		return;
	}
	this->_energy_points--;
	this->_hit_points = this->_hit_points + std::min(amount, UINT_MAX - this->_hit_points);
	std::cout << "ClapTrap " << this->_name << " be repaired HP: " \
		<< tmp << " -> " << this->_hit_points << std::endl;
}
