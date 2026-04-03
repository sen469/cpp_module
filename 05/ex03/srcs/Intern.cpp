/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 22:34:41 by ssawa             #+#    #+#             */
/*   Updated: 2026/04/03 23:01:07 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() { }

Intern::Intern(const Intern &other)
{
	Intern::operator=(other);
}

Intern::~Intern() { }

Intern	&Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

AForm	*Intern::createShrubbery(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::createRobotomy(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::createPresidential(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeForm(const std::string &name, const std::string &target)
{
	std::string formNames[] =
	{
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* (Intern::*formCreators[])(const std::string &target) =
	{
		&Intern::createShrubbery,
		&Intern::createRobotomy,
		&Intern::createPresidential
	};

	for (int i = 0; i < 3; i++)
	{
		if (name == formNames[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			return ((this->*formCreators[i])(target));
		}
	}

	std::cout << "Error: Form name '" << name << "' does not exist." << std::endl;
	return (NULL);
}
