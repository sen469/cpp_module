/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 13:32:10 by ssawa             #+#    #+#             */
/*   Updated: 2026/04/03 13:58:04 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include <string>

class PresidentialPardonForm: public AForm
{
	public:
		// Constructors
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &other);

		// Destructors
		~PresidentialPardonForm();

		// Overloaded Operators
		PresidentialPardonForm	&operator=(const PresidentialPardonForm &other);

		// Getter
		std::string	getTarget() const;

		// Other Functions
		void		execute(const Bureaucrat &executor) const;

	private:
		std::string	_target;
};

#endif
