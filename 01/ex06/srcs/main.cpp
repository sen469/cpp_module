/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 21:14:25 by ssawa             #+#    #+#             */
/*   Updated: 2026/02/03 13:37:30 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "./harlFilter <level>" << std::endl;
		return (1);
	}
	Harl		test;
	std::string	lv = argv[1];

	test.complain(lv);
	return (0);
}
