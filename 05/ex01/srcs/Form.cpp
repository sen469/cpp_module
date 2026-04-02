/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 10:38:59 by ssawa             #+#    #+#             */
/*   Updated: 2026/03/25 13:25:42 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>
#include <ostream>
#include <string>
#include "Bureaucrat.hpp"

// COnstructors
Form::Form(const std::string &name, const int signGrade, const int execGrade): _name(name), _signGrade(signGrade), _execGrade(execGrade), _signed(false)
{
	if (this->_signGrade < 1 || this->_execGrade < 1)
		throw Form::GradeToolHighException();
	else if (this->_signGrade > 150 || this->_execGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &other): _name(other._name), _signGrade(other._signGrade), _execGrade(other._execGrade), _signed(other._signed) { }

// Destructors
Form::~Form()
{
	std::cout << "Form: Destructor called" << std::endl;
}

// OVerloaded Operators
Form	&Form::operator=(const Form &other)
{
	if (this != &other)
		this->_signed = other.getSigned();
	return (*this);
}

// Exception
const char	*Form::GradeToolHighException::what() const throw()
{
	return ("Form: Grade is too High");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Form: Grade is too Low");
}

// Getter
const std::string	Form::getName() const
{
	return (this->_name);
}

int	Form::getExecGrade() const
{
	return (this->_execGrade);
}

int	Form::getSignGrade() const
{
	return (this->_signGrade);
}

bool	Form::getSigned() const
{
	return (this->_signed);
}

void	Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->getSignGrade())
	{
		throw Form::GradeTooLowException();
	}
	this->_signed = true;
}

std::ostream	&operator<<(std::ostream &os, const Form &f)
{
	os << f.getName() << ", Form ExecGrade " << f.getExecGrade() << ", Form SignGrade " << f.getSignGrade() << (f.getSigned() ? " Signed." : " Not Signed.") << std::endl;
	return (os);
}
