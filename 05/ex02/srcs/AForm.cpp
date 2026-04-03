/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 10:38:59 by ssawa             #+#    #+#             */
/*   Updated: 2026/04/02 23:00:30 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <iostream>
#include <ostream>
#include <string>
#include "Bureaucrat.hpp"

// COnstructors
AForm::AForm(const std::string &name, const int signGrade, const int execGrade): _name(name), _signGrade(signGrade), _execGrade(execGrade), _signed(false)
{
	if (this->_signGrade < 1 || this->_execGrade < 1)
		throw AForm::GradeToolHighException();
	else if (this->_signGrade > 150 || this->_execGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other): _name(other._name), _signGrade(other._signGrade), _execGrade(other._execGrade), _signed(other._signed) { }

// Destructors
AForm::~AForm()
{
	std::cout << "Form: Destructor called" << std::endl;
}

// OVerloaded Operators
AForm	&AForm::operator=(const AForm &other)
{
	if (this != &other)
		this->_signed = other.getSigned();
	return (*this);
}

// Exception
const char	*AForm::GradeToolHighException::what() const throw()
{
	return ("Form: Grade is too High");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("Form: Grade is too Low");
}

const char	*AForm::NotSignedException::what() const throw()
{
	return ("Form: Not Signed");
}

// Getter
const std::string	AForm::getName() const
{
	return (this->_name);
}

int	AForm::getExecGrade() const
{
	return (this->_execGrade);
}

int	AForm::getSignGrade() const
{
	return (this->_signGrade);
}

bool	AForm::getSigned() const
{
	return (this->_signed);
}

// Other Functions
void	AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->getSignGrade())
	{
		throw AForm::GradeTooLowException();
	}
	this->_signed = true;
}

void	AForm::checkRequirements(const Bureaucrat &executor) const
{
	if (!this->getSigned())
		throw AForm::NotSignedException();
	if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
}

std::ostream	&operator<<(std::ostream &os, const AForm &f)
{
	os << f.getName() << ", Form ExecGrade " << f.getExecGrade() << ", Form SignGrade " << f.getSignGrade() << (f.getSigned() ? " Signed." : " Not Signed.") << std::endl;
	return (os);
}
