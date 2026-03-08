/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 17:32:10 by ssawa             #+#    #+#             */
/*   Updated: 2026/02/28 18:40:47 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

// コンストラクタ（引数なし）
DiamondTrap::DiamondTrap(): ClapTrap("default" "_clap_name"), \
								_name("default")
{
	std::cout << "DiamondTrap: Constructor(no paramater) called" << std::endl;
}

// コンストラクタ（引数あり）
DiamondTrap::DiamondTrap(const std::string name): ClapTrap(name + "_clap_name"), \
													  _name(name)
{
	std::cout << "DiamondTrap: Constructor called" << std::endl;
}

// コピーコンストラクタ
DiamondTrap::DiamondTrap(const DiamondTrap &other): ClapTrap(other),  \
													ScavTrap(other), \
													FragTrap(other)
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
}
