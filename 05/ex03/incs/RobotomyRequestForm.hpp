/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 13:31:26 by ssawa             #+#    #+#             */
/*   Updated: 2026/04/03 14:56:29 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_hpp
# define ROBOTOMYREQUESTFORM_hpp

# include "AForm.hpp"
# include <string>
# include <sys/wait.h>

class RobotomyRequestForm: public AForm
{
	public:
		// Constructors
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &other);

		// Desturctors
		~RobotomyRequestForm();

		// Overloaded Operators
		RobotomyRequestForm	&operator=(const RobotomyRequestForm &other);

		// Getter
		std::string	getTarget() const;

		// Other Functions
		void		execute(const Bureaucrat &executor) const;

	private:
		std::string	_target;
};

#endif
