/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 21:14:25 by ssawa             #+#    #+#             */
/*   Updated: 2026/02/02 22:55:20 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main()
{
	Harl	test;

	std::cout << "==================== DEBUG ====================" << std::endl;
	test.complain("DEBUG");

	std::cout << "==================== INFO ====================" << std::endl;
	test.complain("INFO");

	std::cout << "==================== WARNING ====================" << std::endl;
	test.complain("WARNING");

	std::cout << "==================== ERROR ====================" << std::endl;
	test.complain("ERROR");

	return (0);
}
