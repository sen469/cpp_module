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

static void	do_ADD(Contact &c, PhoneBook &pb)
{
	std::string f_name;
	std::string l_name;
	std::string n_name;
	std::string p_number;
	std::string d_secret;

	std::cout << "Enter First Name:";
	std::getline(std::cin, f_name);
	std::cout << "Enter Last Name:";
	std::getline(std::cin, l_name);
	std::cout << "Enter Nick Name:";
	std::getline(std::cin, n_name);
	std::cout << "Enter PhoneNumber:";
	std::getline(std::cin, p_number);
	std::cout << "Enter Darkest Secret:";
	std::getline(std::cin, d_secret);
	c.set_information(f_name, l_name, n_name, p_number, d_secret);
	pb.addContact(c);
}

static void	do_search(PhoneBook &pb)
{
	std::string	s_idx;

	pb.show_all();
	while (std::cout << "Please Enter Index..." && std::getline(std::cin, s_idx))
	{
		if (is_nbr(s_idx))
		{
			if (s_idx.size() >= 4)
				continue;
			if (!pb.show_person(ft_atoi(s_idx)))
				break;
		}
	}
}

int	main(void)
{
	std::string	cmd;
	Contact		c;
	PhoneBook	pb;

	std::cout << "Hello PhonBook World" << std::endl;
	while (std::cout << "Enter Command..." << std::endl && \
			std::getline(std::cin, cmd))
	{
		if (cmd == "ADD")
			do_ADD(c, pb);
		else if (cmd == "SEARCH")
			do_search(pb);
		else if (cmd == "EXIT")
			break;
		else
			std::cout << "Enter ADD, SEARCH, EXIT" << std::endl;
	}
	return (0);
}
