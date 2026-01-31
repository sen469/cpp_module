/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 12:11:47 by ssawa             #+#    #+#             */
/*   Updated: 2026/01/31 16:18:45 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon)
	: _name(name), _weapon(weapon)
{}

void	HumanA::attack()
{
	std::cout << _name << " attacks with their " \
		<< _weapon.getType() << std::endl;
}
