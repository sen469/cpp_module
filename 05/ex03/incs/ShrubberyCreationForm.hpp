/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 13:28:57 by ssawa             #+#    #+#             */
/*   Updated: 2026/04/03 14:58:26 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <string>

class ShrubberyCreationForm: public AForm
{
	public:
		// COnstructors
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);

		// Destructors
		~ShrubberyCreationForm();

		// Overloaded Operators
		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &other);

		// Getter
		std::string	getTarget() const;

		// Other Functions
		void		execute(const Bureaucrat &executor) const;

	private:
		std::string	_target;
};

#endif
