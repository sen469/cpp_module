/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 13:38:07 by ssawa             #+#    #+#             */
/*   Updated: 2026/02/12 16:10:08 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(): _rawbits(0) { }

Fixed::Fixed(int n)
{
	this->setRawBits(n << _fractional_bits);
}

Fixed::Fixed(float f)
{
	this->setRawBits(static_cast<int>(roundf(f * (1 << _fractional_bits))));
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}
bool	Fixed::operator<(const Fixed &other) const
{
	return (this->getRawBits() < other.getRawBits());
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return (this->getRawBits() <= other.getRawBits());
}

bool	Fixed::operator>(const Fixed &other) const
{
	return (this->getRawBits() > other.getRawBits());
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return (this->getRawBits() >= other.getRawBits());
}

Fixed	&Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->setRawBits(other.getRawBits());
	return (*this);
}

bool	Fixed::operator==(const Fixed &other) const
{
	return (this->getRawBits() == other.getRawBits());
}
bool Fixed::operator!=(const Fixed &other) const
{
	return (this->getRawBits() != other.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &other) const
{
	Fixed	ret;

	ret.setRawBits(this->getRawBits() + other.getRawBits());
	return (ret);
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	Fixed	ret;

	ret.setRawBits(this->getRawBits() - other.getRawBits());
	return (ret);
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	Fixed		ret;
	long long	tmp;

	tmp = (static_cast<long long>(this->_rawbits) << _fractional_bits) / other.getRawBits();
	ret.setRawBits(tmp);
	return (ret);
}

Fixed	&Fixed::operator++(void)
{
	this->_rawbits++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);

	this->_rawbits++;
	return (tmp);
}

Fixed	&Fixed::operator--(void)
{
	this->_rawbits--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);

	this->_rawbits--;
	return (tmp);
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	Fixed	ret;
	long	tmp = static_cast<long>(this->_rawbits) * other._rawbits;

	ret.setRawBits(tmp >> _fractional_bits);
	return (ret);
}

Fixed::~Fixed(void) { }

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

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() >= b.getRawBits())
		return (a);
	else
		return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() >= b.getRawBits())
		return (a);
	else
		return (b);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() >= b.getRawBits())
		return (b);
	else
		return (a);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() >= b.getRawBits())
		return (b);
	else
		return (a);
}
