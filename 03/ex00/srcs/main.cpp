/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 17:52:11 by ssawa             #+#    #+#             */
/*   Updated: 2026/02/12 19:12:19 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "===== Constructor Test =====" << std::endl;
	ClapTrap a("Alpha");

	std::cout << "\n===== Basic Attack Test =====" << std::endl;
	a.attack("Target1");

	std::cout << "\n===== Take Damage Test =====" << std::endl;
	a.takeDamage(3);

	std::cout << "\n===== Repair Test =====" << std::endl;
	a.beRepaired(5);

	std::cout << "\n===== Overkill Damage Test =====" << std::endl;
	a.takeDamage(100);  // HP should not go negative

	std::cout << "\n===== Action When HP is 0 =====" << std::endl;
	a.attack("Target2");
	a.beRepaired(10);

	std::cout << "\n===== Energy Exhaustion Test =====" << std::endl;
	ClapTrap b("Beta");
	for (int i = 0; i < 11; ++i)
		b.attack("Dummy");  // 11th should fail

	std::cout << "\n===== Repair Until Energy 0 =====" << std::endl;
	ClapTrap c("Gamma");
	for (int i = 0; i < 11; ++i)
		c.beRepaired(1);    // 11th should fail

	std::cout << "\n===== Copy Constructor Test =====" << std::endl;
	ClapTrap d("Delta");
	d.takeDamage(5);
	ClapTrap e(d);
	e.attack("CopiedTarget");

	std::cout << "\n===== Assignment Operator Test =====" << std::endl;
	ClapTrap f("Foxtrot");
	f = d;
	f.attack("AssignedTarget");

	std::cout << "\n===== End of main =====" << std::endl;
	return (0);
}
