/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 22:58:39 by ssawa             #+#    #+#             */
/*   Updated: 2026/03/11 16:45:15 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

// Constructors
Animal::Animal()
{
	std::cout << "Animal: Constructor called." << std::endl;
}

Animal::Animal(const Animal &other): type(other.type)
{
	std::cout << "Animal: Copy Constructor called." << std::endl;
}

// Destructors
Animal::~Animal()
{
	std::cout << "Animal: Destructor called." << std::endl;
}

// Overloaded Operators
Animal	&Animal::operator=(const Animal &other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

// Other functions
std::string	Animal::getType()const
{
	return (this->type);
}

void	Animal::makeSound() const
{
	std::cout << "Animal: makeSound() called." << std::endl;
}
