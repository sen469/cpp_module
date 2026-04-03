/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 22:34:48 by ssawa             #+#    #+#             */
/*   Updated: 2026/04/03 23:03:09 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
class Intern
{
	public:
		// Constructors
		Intern();
		Intern(const Intern &other);

		// Destructors
		~Intern();

		// Overloaded Operator
		Intern	&operator=(const Intern &other);

		// Other Functions
		AForm	*makeForm(const std::string &name, const std::string &target);

	private:
		AForm	*createShrubbery(const std::string &target);
		AForm	*createRobotomy(const std::string &target);
		AForm	*createPresidential(const std::string &target);
};

#endif
