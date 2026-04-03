/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 10:38:14 by ssawa             #+#    #+#             */
/*   Updated: 2026/04/03 13:48:00 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <exception>
# include <string>
# include <ostream>

class Bureaucrat;

class AForm
{
	public:
		// Constructors
		AForm(const std::string &name, const int signGrade, const int execGrade);
		AForm(const AForm &other);

		// Destructors
		~AForm();

		// Overloaded Operators
		AForm	&operator=(const AForm &other);

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

		class NotSignedException: public std::exception
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
		void			beSigned(const Bureaucrat &b);
		void			checkRequirements(const Bureaucrat &executor) const;
		virtual void	execute(const Bureaucrat &executor) const = 0;

	private:
		AForm();
		const std::string	_name;
		const int			_signGrade;
		const int			_execGrade;
		bool				_signed;
};

std::ostream	&operator<<(std::ostream &os, const AForm &f);

#endif
