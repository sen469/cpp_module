/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 18:52:13 by ssawa             #+#    #+#             */
/*   Updated: 2026/03/16 19:10:29 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "AMateria.hpp"
#include <iostream>

// Constructors
Ice::Ice(): AMateria("ice")
{

}

Ice::Ice(const Ice &other): AMateria(other)
{
	Ice::operator=(other);
}

// Destructors
Ice::~Ice()
{
	std::cout << "Ice: Destructors called" << std::endl;
}

// Overloaded Operators
Ice	&Ice::operator=(const Ice &other)
{
	if (this != &other)
	{
		if (other._type == "ice")
		{
			this->_type = other._type;
		}
	}
	return (*this);
}

AMateria	*Ice::clone() const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
