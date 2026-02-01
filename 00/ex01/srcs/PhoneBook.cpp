/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 21:42:06 by ssawa             #+#    #+#             */
/*   Updated: 2026/01/28 15:30:02 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>

PhoneBook::PhoneBook(void)
{
	_top = 0;
	_count = 0;
}

void	PhoneBook::addContact(const Contact &c)
{
	if (_count == MAX_ID)
	{
		_contact[_top] = c;
		_top = (_top + 1) % MAX_ID;
	}
	else
	{
		_contact[_count] = c;
		_count++;
	}

}

void PhoneBook::print_header(void)
{
    std::cout << '|';
    std::cout << std::setw(MAX_LENGTH) << "Index";
    std::cout << '|';
    std::cout << std::setw(MAX_LENGTH) << "First Name";
    std::cout << '|';
    std::cout << std::setw(MAX_LENGTH) << "Last Name";
    std::cout << '|';
    std::cout << std::setw(MAX_LENGTH) << "Nick Name";
    std::cout << '|' << std::endl;
}

void	PhoneBook::print_separator(void)
{
	std::cout << \
		"+" << std::string(MAX_LENGTH, '-') << \
		'+' << std::string(MAX_LENGTH, '-') << \
		'+' << std::string(MAX_LENGTH, '-') << \
		'+' << std::string(MAX_LENGTH, '-') << \
		'+' << std::endl;
}

void	PhoneBook::show_all(void)
{

	print_separator();
	print_header();
	print_separator();
	for (int i = 0; i < _count; i++)
		_contact[(_top + i) % _count].print_row(i) ;
	print_separator();
	// std::cout << "__top = " << _top << std::endl;
}

int	PhoneBook::show_person(int idx)
{
	if (idx > _count - 1)
		return (1);
	_contact[(_top + idx) % _count].print_person();
	return (0);
}

int	PhoneBook::get_count(void)
{
	return (_count);
}
