/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 16:19:02 by ssawa             #+#    #+#             */
/*   Updated: 2026/01/31 16:32:31 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name)
	: _name(name), _weapon(NULL)
{}

void	HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}

void	HumanB::attack()
{
	if (_weapon == NULL)
	{
		std::cout << _name << " attacks with their " << std::endl;
	}
	else
	{
		std::cout << _name << " attacks with their " \
			<< _weapon->getType() << std::endl;
	}
}
