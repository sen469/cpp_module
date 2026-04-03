/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 01:14:12 by ssawa             #+#    #+#             */
/*   Updated: 2026/03/08 21:06:56 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

// コンストラクタ
FragTrap::FragTrap(): ClapTrap("defaultFT")
{
	std::cout << "FragTrap: Constructor(no paramater) called" << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
}

FragTrap::FragTrap(const std::string &name): ClapTrap(name)
{
	std::cout << "FragTrap: Constructor called" << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap &other): ClapTrap(other)
{
	std::cout << "FragTrap: Copy constructor called" << std::endl;
}

// 演算子オーバーロード
FragTrap	&FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap: Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return (*this);
}

// デストラクタ
FragTrap::~FragTrap()
{
	std::cout << "FragTrap: Destructor called" << std::endl;
}

// メンバ関数
void	FragTrap::highFivesGuys(void)
{
	std::cout << "High five guys! ✋" << std::endl;
}
