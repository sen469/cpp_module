/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 22:58:39 by ssawa             #+#    #+#             */
/*   Updated: 2026/03/11 15:24:18 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

// Constructors
Dog::Dog()
{
	std::cout << "Dog: Constructor called." << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog &other): Animal(other)
{
	std::cout << "Dog: Copy Constructor called." << std::endl;
}

// Destructors
Dog::~Dog()
{
	std::cout << "Dog: Destructor called." << std::endl;
}

// Overloaded Operators
Dog	&Dog::operator=(const Dog &other)
{
	Animal::operator=(other);
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Dog: Bark Bark" << std::endl;
}
