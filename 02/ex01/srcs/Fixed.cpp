/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 13:38:07 by ssawa             #+#    #+#             */
/*   Updated: 2026/02/09 15:45:33 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(): _rawbits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int n)
{
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(n << _fractional_bits);
}

Fixed::Fixed(float f)
{
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits(static_cast<int>(roundf(f * (1 << _fractional_bits))));
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed	&Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->setRawBits(other.getRawBits());
	}
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	return (_rawbits);
}

void	Fixed::setRawBits(const int raw)
{
	this->_rawbits = raw;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->_rawbits) / (1 << _fractional_bits));
}

int		Fixed::toInt(void) const
{
	return (this->_rawbits >> _fractional_bits);
}

std::ostream	&operator<<(std::ostream &os, const Fixed &other)
{
	os << other.toFloat();
	return (os);
}
