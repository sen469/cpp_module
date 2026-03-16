/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 18:52:10 by ssawa             #+#    #+#             */
/*   Updated: 2026/03/16 15:12:43 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>

// Constructors
Cure::Cure(): AMateria("cure")
{

}

Cure::Cure(const Cure &other): AMateria(other)
{
	Cure::operator=(other);
}

// Destructors
Cure::~Cure()
{
	std::cout << "Cure: Destructors called" << std::endl;
}

// Overloaded Operators
Cure	&Cure::operator=(const Cure &other)
{
	if (this != &other)
	{
		if (other._type == "cure")
		{
			this->_type = other._type;
		}
	}
	return (*this);
}

// Other Functions
AMateria	*Cure::clone() const
{
	return (new Cure(*this));
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
