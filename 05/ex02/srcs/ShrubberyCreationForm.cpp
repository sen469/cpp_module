/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 14:54:58 by ssawa             #+#    #+#             */
/*   Updated: 2026/04/03 14:58:58 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("shrubbery creation", 145, 137), _target("defaultS") { }

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm("shrubbery creation", 145, 137), _target(target) { }

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm(other), _target(other._target) { }

ShrubberyCreationForm::~ShrubberyCreationForm() { }

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other.getTarget();
	}
	return (*this);
}

std::string	ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	this->checkRequirements(executor);
	std::string		filename = this->getTarget() + "_shrubbery";
	std::ofstream	ofs(filename.c_str());

	if (!ofs.is_open())
	{
		std::cerr << "Error: Could not open file " << filename << std::endl;
		return;
	}

	ofs << "        v .   ._, |_  .," << std::endl;
	ofs << "     `-._\\/  .  \\ /    |/_" << std::endl;
	ofs << "         \\  \\, y | \\//" << std::endl;
	ofs << "   _\\_.___\\, \\/-.\\||" << std::endl;
	ofs << "     `7-,--.`._||  / / ," << std::endl;
	ofs << "     /'     `-. `./ / |/_." << std::endl;
	ofs << "               |    |//" << std::endl;
	ofs << "               |_    / " << std::endl;
	ofs << "               |-   |  " << std::endl;
	ofs << "               |   =|  " << std::endl;
	ofs << "               |    |  " << std::endl;
	ofs << "--------------------" << std::endl;

	ofs.close();
	std::cout << "Shrubbery has been created in " << filename << std::endl;
}
