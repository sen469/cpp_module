/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 21:05:22 by ssawa             #+#    #+#             */
/*   Updated: 2026/01/28 15:30:43 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
#include <iostream>
#include <cstdlib>

static bool safe_getline(std::string &s)
{
	if (!std::getline(std::cin, s))
		return false;
	return true;
}

static void	do_add(Contact &c, PhoneBook &pb)
{
	std::string f_name;
	std::string l_name;
	std::string n_name;
	std::string p_number;
	std::string d_secret;

	std::cout << "Enter First Name:";
	if (!safe_getline(f_name))
		std::exit(0);
	std::cout << "Enter Last Name:";
	if (!safe_getline(l_name))
		std::exit(0);
	std::cout << "Enter Nick Name:";
	if (!safe_getline(n_name))
		std::exit(0);
	std::cout << "Enter PhoneNumber:";
	if (!safe_getline(p_number))
		std::exit(0);
	std::cout << "Enter Darkest Secret:";
	if (!safe_getline(d_secret))
		std::exit(0);
	if (f_name.empty() || l_name.empty() || n_name.empty() \
		|| p_number.empty() || d_secret.empty())
	{
		std::cout << "No empty field" << std::endl;
		return;
	}
	c.set_information(f_name, l_name, n_name, p_number, d_secret);
	pb.addContact(c);
}

static void	do_search(PhoneBook &pb)
{
	std::string	s_idx;

	pb.show_all();
	if (pb.get_count() == 0)
	{
		std::cout << "PhoneBook is empty" << std::endl;
		return;
	}
	while (std::cout << "Please Enter Index..." && safe_getline(s_idx))
	{
		if (is_nbr(s_idx))
		{
			if (s_idx.size() >= 4)
				continue;
			if (!pb.show_person(ft_atoi(s_idx)))
				break;
		}
	}
	if (std::cin.eof())
		std::exit(0);
}

int	main(void)
{
	std::string	cmd;
	Contact		c;
	PhoneBook	pb;

	while (true)
	{
		std::cout << "Enter Command..." << std::endl;
		if (!safe_getline(cmd))
			break;
		if (cmd == "ADD")
			do_add(c, pb);
		else if (cmd == "SEARCH")
			do_search(pb);
		else if (cmd == "EXIT")
			break;
		else
			std::cout << "Command is {ADD, SEARCH, EXIT}" << std::endl;
	}
	return (0);
}
