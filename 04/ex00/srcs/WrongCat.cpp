/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 22:58:39 by ssawa             #+#    #+#             */
/*   Updated: 2026/03/11 16:15:28 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

// Constructors
WrongCat::WrongCat()
{
	std::cout << "WrongCat: Constructor called." << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &other): WrongAnimal(other)
{
	std::cout << "WrongCat: Copy Constructor called." << std::endl;
}

// Destructors
WrongCat::~WrongCat()
{
	std::cout << "WrongCat: Destructor called." << std::endl;
}

// Overloaded Operators
WrongCat	&WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
	{
		WrongAnimal::operator=(other);
	}
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "WrongCat: Meow Meow" << std::endl;
}
