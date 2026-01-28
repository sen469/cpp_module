/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 18:46:20 by ssawa             #+#    #+#             */
/*   Updated: 2026/01/28 15:22:33 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <string>

void Contact::print_format(int id)
{
    std::cout << std::setw(MAX_LENGTH) << id;
}

void	Contact::print_format(std::string str)
{
	int	sz = str.size();
	if (sz > MAX_LENGTH)
		std::cout << str.substr(0, MAX_LENGTH - 1) << '.';
	else
		std::cout << std::string(MAX_LENGTH - sz, ' ') << str;
}

void	Contact::print_person(void)
{
	std::cout << "Fisrt Name\t:" << _first_name << std::endl;
	std::cout << "Last Name\t:" << _last_name << std::endl;
	std::cout << "Nick Name\t:" << _nick_name << std::endl;
	std::cout << "Phone Number\t:" << _phone_number << std::endl;
	std::cout << "Darkest Secret\t:" << _darkest_secret << std::endl;
}

void	Contact::set_information(std::string f_name, \
						std::string l_name, \
						std::string n_name, \
						std::string p_number, \
						std::string d_secret)
{
	_first_name = f_name;
	_last_name = l_name;
	_nick_name = n_name;
	_phone_number = p_number;
	_darkest_secret = d_secret;
}

void	Contact::print_row(int id)
{
	std::cout << '|';
	print_format(id);
	std::cout << '|';
	print_format(_first_name);
	std::cout << '|';
	print_format(_last_name);
	std::cout << '|';
	print_format(_nick_name);
	std::cout << '|';
	std::cout << std::endl;
}
