/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 18:52:20 by ssawa             #+#    #+#             */
/*   Updated: 2026/03/16 19:15:44 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "constants.hpp"
#include <iostream>

// Constructors
MateriaSource::MateriaSource()
{
	for (int i = 0; i < INVENTORY_SIZE; i++)
		this->_inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	MateriaSource::operator=(other);
}

// Destructors
MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource: Destructor called" << std::endl;
	for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
	}
}

// Overloaded Operators TODO
MateriaSource	&MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
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

// Other Functions
void	MateriaSource::learnMateria(AMateria *m)
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
	delete m;
}

AMateria	*MateriaSource::createMateria(const std::string &type)
{
	for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		if (this->_inventory[i] != NULL && this->_inventory[i]->getType() == type)
			return (this->_inventory[i]->clone());
	}
	return (NULL);
}
