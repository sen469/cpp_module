/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 22:32:16 by ssawa             #+#    #+#             */
/*   Updated: 2026/04/03 23:30:00 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

void testForm(const std::string &name, const std::string &target)
{
	std::cout << "-----------------------------------------------------" << std::endl;
	std::cout << "Testing: " << name << " for target: " << target << std::endl;

	Intern someRandomIntern;
	Bureaucrat boss("The Boss", 1);
	AForm* form;

	form = someRandomIntern.makeForm(name, target);

	if (form)
	{
		std::cout << *form << std::endl;
		boss.signForm(*form);
		boss.executeForm(*form);
		delete form;
	}
	else
	{
		std::cout << "Intern failed to create form: " << name << std::endl;
	}
}

int main()
{
	// 正常系: すべての有効なフォームタイプ
	testForm("shrubbery creation", "Home");
	testForm("robotomy request", "Bender");
	testForm("presidential pardon", "Ford Prefect");

	// 異常系: 無効なフォームタイプ
	testForm("unknown request", "Nobody");

	std::cout << "-----------------------------------------------------" << std::endl;
	std::cout << "Tests completed." << std::endl;

	return 0;
}
