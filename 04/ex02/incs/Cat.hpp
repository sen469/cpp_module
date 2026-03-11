/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 13:50:00 by ssawa             #+#    #+#             */
/*   Updated: 2026/03/11 17:04:29 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal
{
	public:
		// Constructors
		Cat();
		Cat(const Cat &other);

		// Destructors
		~Cat();

		// Overloaded Oerators
		Cat	&operator=(const Cat &other);

		// Other Functions
		void	makeSound() const;
		Brain	*getBrain() const;
	private:
		Brain	*_brain;
};

#endif
