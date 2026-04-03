/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 13:45:20 by ssawa             #+#    #+#             */
/*   Updated: 2026/04/03 15:09:31 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <Bureaucrat.hpp>
#include <iostream>

// Constructors
PresidentialPardonForm::PresidentialPardonForm(): AForm("presidential pardon", 25, 5), _target("defaultP") { }

PresidentialPardonForm::PresidentialPardonForm(const std::string &target): AForm("presidential pardon", 25, 5), _target(target) { }

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other): AForm(other), _target(other._target) { }

// Destructors
PresidentialPardonForm::~PresidentialPardonForm() { }

// Overloaded Operators
PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other.getTarget();
	}
	return (*this);
}

// Getter
std::string	PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

// Other Functions
void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    this->checkRequirements(executor);
    std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
