/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 18:52:07 by ssawa             #+#    #+#             */
/*   Updated: 2026/03/16 19:20:47 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "ICharacter.hpp"
#include "constants.hpp"
#include "Floor.hpp"
#include <string>
#include <iostream>

// Constructors
Character::Character(): _name("defaultC"), _floor()
{
	for (int i = 0; i < INVENTORY_SIZE; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const std::string &name): _name(name), _floor()
{
	for (int i = 0; i < INVENTORY_SIZE; i++)
		this->_inventory[i] = NULL;
}
Character::Character(const Character &other): _name(other._name), _floor()
{
	for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		if (other._inventory[i] != NULL)
			this->_inventory[i] = other._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
}

// Destructors
Character::~Character()
{
	for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
	}
	std::cout << "Character: Destructor called" << std::endl;
}

// Overloaded Operators
Character	&Character::operator=(const Character &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		for (int i = 0; i < INVENTORY_SIZE; i++)
		{
			if (this->_inventory[i] != NULL)
			{
				delete this->_inventory[i];
				this->_inventory[i] = NULL;
			}
			if (other._inventory[i] != NULL)
			{
				this->_inventory[i] = other._inventory[i]->clone();
			}
		}
	}
	return (*this);
}

// Getter
const std::string	&Character::getName() const
{
	return (this->_name);
}

// Other Functions
void	Character::equip(AMateria *m)
{
	if (m == NULL)
	{
		return;
	}
	for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			return;
		}
	}
	this->_floor.add_front(m);
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx >= INVENTORY_SIZE || this->_inventory[idx] == NULL)
	{
		return;
	}
	this->_floor.add_front(this->_inventory[idx]);
	this->_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= INVENTORY_SIZE || this->_inventory[idx] == NULL)
	{
		return;
	}
	this->_inventory[idx]->use(target);
}
