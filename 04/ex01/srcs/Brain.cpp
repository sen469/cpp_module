/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:54:24 by ssawa             #+#    #+#             */
/*   Updated: 2026/03/11 17:04:19 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

// Constructors
Brain::Brain()
{
	std::cout << "Brain: Constructor called." << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain: Copy Constructor called." << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
}

// Destructors
Brain::~Brain()
{
	std::cout << "Brain: Destructors called." << std::endl;
}

// Overloaded Operators
Brain &Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
	}
	return (*this);
}
