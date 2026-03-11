/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 22:58:39 by ssawa             #+#    #+#             */
/*   Updated: 2026/03/11 16:02:24 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

// Constructors
Cat::Cat()
{
	std::cout << "Cat: Constructor called." << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat &other): Animal(other)
{
	std::cout << "Cat: Copy Constructor called." << std::endl;
}

// Destructors
Cat::~Cat()
{
	std::cout << "Cat: Destructor called." << std::endl;
}

// Overloaded Operators
Cat	&Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
	}
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Cat: Meow Meow" << std::endl;
}
