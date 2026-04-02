/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 22:58:39 by ssawa             #+#    #+#             */
/*   Updated: 2026/03/11 17:06:23 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

// Constructors
Cat::Cat(): Animal("Cat"), _brain(new Brain)
{
	std::cout << "Cat: Constructor called." << std::endl;
}

Cat::Cat(const Cat &other): Animal(other), _brain(new Brain (*other._brain))
{
	std::cout << "Cat: Copy Constructor called." << std::endl;
}

// Destructors
Cat::~Cat()
{
	std::cout << "Cat: Destructor called." << std::endl;
	delete this->_brain;
}

// Overloaded Operators
Cat	&Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		*(this->_brain) = *(other.getBrain());
	}
	return (*this);
}

// Other Functions
void	Cat::makeSound() const
{
	std::cout << "Cat: Meow Meow" << std::endl;
}

Brain	*Cat::getBrain() const
{
	return (this->_brain);
}
