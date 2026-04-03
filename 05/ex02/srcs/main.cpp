/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 16:06:53 by ssawa             #+#    #+#             */
/*   Updated: 2026/04/03 16:06:54 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

void printTitle(std::string title)
{
	std::cout << "\n========================================" << std::endl;
	std::cout << "  " << title << std::endl;
	std::cout << "========================================" << std::endl;
}

int main()
{
	std::srand(std::time(NULL));

	try
	{
		printTitle("1. Bureaucrats Creation");
		Bureaucrat president("President", 1);
		Bureaucrat midManager("MidManager", 40);
		Bureaucrat intern("Intern", 150);

		std::cout << president;
		std::cout << midManager;
		std::cout << intern;

		printTitle("2. ShrubberyCreationForm Test (Target: Home)");
		ShrubberyCreationForm shrub("home");
		std::cout << shrub;
		
		intern.executeForm(shrub);
		intern.signForm(shrub);
		midManager.signForm(shrub);
		intern.executeForm(shrub);
		midManager.executeForm(shrub);

		printTitle("3. RobotomyRequestForm Test (Target: Bender)");
		RobotomyRequestForm robot("Bender");
		president.signForm(robot);
		for (int i = 0; i < 4; i++) {
			std::cout << "[" << i + 1 << "/4] ";
			president.executeForm(robot);
		}

		printTitle("4. PresidentialPardonForm Test (Target: Arthur Dent)");
		PresidentialPardonForm pardon("Arthur Dent");
		president.executeForm(pardon);
		
		president.signForm(pardon);
		midManager.executeForm(pardon);
		president.executeForm(pardon);

		printTitle("5. Polymorphism & Memory Safety");
		AForm* formPtr = new RobotomyRequestForm("Target_X");
		president.signForm(*formPtr);
		president.executeForm(*formPtr);
		delete formPtr;

	} catch (std::exception &e) {
		std::cerr << "CRITICAL ERROR: " << e.what() << std::endl;
	}

	printTitle("End of Tests");
	return 0;
}
