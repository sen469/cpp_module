/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 22:58:39 by ssawa             #+#    #+#             */
/*   Updated: 2026/03/11 17:06:13 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"
#include <iostream>

// Constructors
Dog::Dog()
{
	std::cout << "Dog: Constructor called." << std::endl;
	this->type = "Dog";
	this->_brain = new Brain;
}

Dog::Dog(const Dog &other): Animal(other)
{
	std::cout << "Dog: Copy Constructor called." << std::endl;
	this->_brain = new Brain(*other._brain);
}

// Destructors
Dog::~Dog()
{
	std::cout << "Dog: Destructor called." << std::endl;
	delete this->_brain;
}

// Overloaded Operators
Dog	&Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		*(this->_brain) = *(other._brain);
	}
	return (*this);
}

// Other Functions
void	Dog::makeSound() const
{
	std::cout << "Dog: Bark Bark" << std::endl;
}

Brain	*Dog::getBrain() const
{
	return (this->_brain);
}
