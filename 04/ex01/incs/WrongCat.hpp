/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 13:50:00 by ssawa             #+#    #+#             */
/*   Updated: 2026/03/11 15:38:05 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	public:
		// Constructors
		WrongCat();
		WrongCat(const WrongCat &other);

		// Destructors
		~WrongCat();

		// Overloaded Oerators
		WrongCat	&operator=(const WrongCat &other);

		// Other Functions
		void	makeSound() const;

	private:
};

#endif
