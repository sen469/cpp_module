/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 18:44:09 by ssawa             #+#    #+#             */
/*   Updated: 2026/03/24 18:46:26 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <ostream>
#include <string>
#include <iostream>

// Constructors
Bureaucrat::Bureaucrat(): _name("defaultB"), _grade(150) { }

Bureaucrat::Bureaucrat(const std::string &name, int grade): _name(name), _grade(grade)
{
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name), _grade(other._grade) { }

// Desturctors
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat: Destructor called" << std::endl;
}


// Overloaded Operators
Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		this->_grade = other.getGrade();
	return (*this);
}

// Getter
const std::string	&Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

// Other Functions
void	Bureaucrat::incrementGrade()
{

	if (this->getGrade() - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (this->getGrade() + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

// Exception
const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too High");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too Low");
}

void	Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << this->getName() << " couldn't sign " << form.getName() 
				  << " because " << e.what() << std::endl;
	}
}
std::ostream	&operator<<(std::ostream &os, const Bureaucrat &b)
{
	os << b.getName() << ", Bureaucrat grade " << b.getGrade() << "." << std::endl;
	return (os);
}
