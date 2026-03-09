/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 17:32:10 by ssawa             #+#    #+#             */
/*   Updated: 2026/03/08 20:59:23 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

// コンストラクタ（引数なし）
DiamondTrap::DiamondTrap(): ClapTrap("defaultDT_clap_name"), \
								_name("defaultDT")
{
	std::cout << "DiamondTrap: Constructor(no paramater) called" << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 30;
}

// コンストラクタ（引数あり）
DiamondTrap::DiamondTrap(const std::string name): ClapTrap(name + "_clap_name"), \
													  _name(name)
{
	std::cout << "DiamondTrap: Constructor called" << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 30;
}

// コピーコンストラクタ
DiamondTrap::DiamondTrap(const DiamondTrap &other): ClapTrap(other),  \
													ScavTrap(other), \
													FragTrap(other), \
													_name(other._name)
{
	std::cout << "DiamondTrap: Copy constructor called" << std::endl;
}

// 代入演算子オーバーライド
DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << "DiamondTrap: Copy assignment operator called" << std::endl;
	if (this  != &other)
	{
		ClapTrap::operator=(other);
		ScavTrap::operator=(other);
		FragTrap::operator=(other);
		this->_name = other._name;
	}
	return (*this);
}

// デストラクタ
DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap: Destructor called" << std::endl;
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name is = " << _name << ", ClapTrap name is = " << ClapTrap::_name << std::endl;
}

void	DiamondTrap::show_name()
{
	std::cout << "show_name called: ";
	std::cout << this->_name << std::endl;
}

void	DiamondTrap::show_dmg()
{
	std::cout << "show_dmg called: ";
	std::cout << this->_attack_damage << std::endl;
}

void	DiamondTrap::show_hp()
{
	std::cout << "show_hp called: ";
	std::cout << this->_hit_points << std::endl;
}
void	DiamondTrap::show_energy()
{
	std::cout << "show_energy called: ";
	std::cout << this->_energy_points << std::endl;
}
