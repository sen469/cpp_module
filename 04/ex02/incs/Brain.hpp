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

#define SIZE 100
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
		Brain	&operator=(const Brain &other);

		// Other Functions
		std::string	getIdea(int index) const;
		void		setIdea(int index, const std::string &idea);

	private:
		std::string	ideas[SIZE];
};
#endif
