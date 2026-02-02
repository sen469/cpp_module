/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 23:38:25 by ssawa             #+#    #+#             */
/*   Updated: 2026/02/01 23:38:28 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <istream>
#include <string>

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		return (1);
	}

	std::string	i_name = argv[1];
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];
	std::string	o_name = i_name + ".replace";
	std::ofstream	i_stream(i_name);
	if (!i_stream)
	{
		std::cout << "can't open file" << std::endl;
		return (1);
	}

	return (0);
}
