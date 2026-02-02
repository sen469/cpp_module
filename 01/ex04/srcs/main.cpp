/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 23:38:25 by ssawa             #+#    #+#             */
/*   Updated: 2026/02/02 21:12:33 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>

int	main(int argc, char *argv[])
{
	if (argc != 4)
		return (1);

	std::string		i_name = argv[1];
	std::string		s1 = argv[2];
	std::string		s2 = argv[3];

	std::ifstream	ifs(i_name.c_str(), std::ios::in);
	if (!ifs)
	{
		std::cerr << "can't open " << i_name << std::endl;
		return (1);
	}

	std::ofstream	ofs((i_name + ".replace").c_str(), std::ios::trunc | std::ios::out);
	if (!ofs)
	{
		std::cerr << "can't open " << (i_name + ".replace") << std::endl;
		return (1);
	}

	std::string	line;
	while (std::getline(ifs, line))
	{
		std::string	out_line = "";
		size_t		pos = 0;
		while (true)
		{
			size_t	new_pos = line.find(s1, pos);
			if (new_pos != std::string::npos)
			{
				out_line += (line.substr(pos, new_pos - pos) + s2);
				pos = new_pos + s1.size();
			}
			else
			{
				out_line += line.substr(pos);
				break;
			}
		}
		ofs << out_line << std::endl;
	}
	return (0);
}
