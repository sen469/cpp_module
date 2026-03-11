/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 13:50:00 by ssawa             #+#    #+#             */
/*   Updated: 2026/03/11 15:21:38 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog: public Animal
{
	public:
		// Constructors
		Dog();
		Dog(const Dog &other);

		// Destructors
		~Dog();

		// Overloaded Oerators
		Dog &operator=(const Dog &other);

		// Other Functions
		void	makeSound() const;

	private:
};

#endif
