/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 10:38:14 by ssawa             #+#    #+#             */
/*   Updated: 2026/03/25 13:24:35 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <exception>
#include <string>
#include <ostream>

class Bureaucrat;

class Form
{
	public:
		// Constructors
		Form(const std::string &name, const int signGrade, const int execGrade);
		Form(const Form &other);

		// Destructors
		~Form();

		// Overloaded Operators
		Form	&operator=(const Form &other);

		// Exception
		class GradeToolHighException: public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		// Getter
		const std::string	getName() const;
		int					getSignGrade() const;
		int					getExecGrade() const;
		bool				getSigned() const;

		// Other Functions
		void	beSigned(const Bureaucrat &b);


	private:
		Form();
		const std::string	_name;
		const int			_signGrade;
		const int			_execGrade;
		bool				_signed;
};

std::ostream	&operator<<(std::ostream &os, const Form &f);

#endif
