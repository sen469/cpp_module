/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 22:37:16 by ssawa             #+#    #+#             */
/*   Updated: 2026/03/11 15:20:23 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal
{
	public:
		// Constructors
		Animal();
		Animal(const std::string &type);
		Animal(const Animal &other);

		// Destructors
		virtual ~Animal();

		// Overloaded Oerators
		Animal	&operator=(const Animal &other);

		// Other functions
		std::string		getType() const;
		virtual void	makeSound() const = 0;

	protected:
		void			setType(const std::string &type);

	private:
		std::string	type;
};

#endif
