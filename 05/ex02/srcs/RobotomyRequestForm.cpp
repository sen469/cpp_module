/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 14:54:58 by ssawa             #+#    #+#             */
/*   Updated: 2026/04/03 14:57:04 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

// COnstructors
RobotomyRequestForm::RobotomyRequestForm(): AForm("presidential pardon", 72, 45), _target("defaultR") { }
RobotomyRequestForm::RobotomyRequestForm(const std::string &target): AForm("presidential pardon", 72, 45), _target(target) { }

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm(other), _target(other._target) { }

// Destructors
RobotomyRequestForm::~RobotomyRequestForm() { }

// Overloaded Operators
RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other.getTarget();
	}
	return (*this);
}

// Getter
std::string	RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	this->checkRequirements(executor);
	std::cout << "* drilling noises: BZZZZZZZZZT! *" << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << this->getTarget() << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "The robotomy on " << this->getTarget() << " failed." << std::endl;
}
