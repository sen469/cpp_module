/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:44:47 by ssawa             #+#    #+#             */
/*   Updated: 2026/03/11 17:05:25 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>
class Brain
{
	public:
		// Constructors
		Brain();
		Brain(const Brain &other);

		// Destructors
		~Brain();

		// Overloaded Operators
		Brain &operator=(const Brain &other);

	private:
		std::string	ideas[100];
};
#endif
