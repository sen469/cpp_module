/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 18:29:48 by ssawa             #+#    #+#             */
/*   Updated: 2026/04/06 18:30:44 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <cstddef>
#include <stdexcept>

Span::Span(unsigned int n): _max_size(n) { }

Span::Span(const Span &other): _max_size(other._max_size), _v(other._v) { }

Span::~Span() { }

Span	&Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->_max_size = other.get_maxsize();
		this->_v = other._v;
	}
	return (*this);
}

unsigned int	Span::size() const
{
	return (_v.size());
}

unsigned int	Span::get_maxsize() const
{
	return (this->_max_size);
}

void	Span::addNumber(int n)
{
	if (_v.size() >= _max_size)
		throw std::out_of_range("Span is already full");
	_v.push_back(n);
}

unsigned int	Span::longestSpan() const
{
	if (this->size() < 2)
		throw std::logic_error("Span error: Not enough elements to calculate a span (minimum 2 required).");
	std::pair<std::vector<int>::iterator, std::vector<int>::iterator> p = std::minmax_element(this->_v.begin(), this->_v.end());
	return (*p.second - *p.first);
}

unsigned int	Span::shortestSpan() const
{
	if (this->size() < 2)
		throw std::logic_error("Span error: Not enough elements to calculate a span (minimum 2 required).");
	std::vector<int>	sorted = this->_v;
	unsigned int		ret = 0;
	unsigned int		dif;

	std::sort(sorted.begin(), sorted.end());
	for (size_t i = 0; i < sorted.size() - 1; i++)
	{
		dif = static_cast<unsigned int>(sorted[i + 1]) - static_cast<unsigned int>(sorted[i]);
		ret = std::min(ret, dif);
	}
	return (ret);
}
