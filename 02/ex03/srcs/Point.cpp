/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:58:35 by ssawa             #+#    #+#             */
/*   Updated: 2026/02/12 17:08:44 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): _x(0), _y(0) { }

Point::Point(float x, float y): _x(x), _y(y) { }

Point::Point(const Point &other)
{
	*this = other;
}

Point	&Point::operator=(const Point &other)
{
	if (this != &other)
	{
		this->_x.setRawBits(other._x.getRawBits());
		this->_y.setRawBits(other._y.getRawBits());
	}
	return (*this);
}

Point	Point::operator-(const Point &other) const
{
	Point	ret;

	ret._x = this->_x - other._x;
	ret._y = this->_y - other._y;
	return (ret);
}

Fixed	Point::get_x() const
{
	return (_x);
}

Fixed	Point::get_y() const
{
	return (_y);
}

Point::~Point() { }
