/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 22:37:16 by ssawa             #+#    #+#             */
/*   Updated: 2026/03/11 15:32:30 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>

class WrongAnimal
{
	public:
		// Constructors
		WrongAnimal();
		WrongAnimal(const WrongAnimal &other);

		// Destructors
		~WrongAnimal();

		// Overloaded Oerators
		WrongAnimal &operator=(const WrongAnimal &other);

		// Other functions
		std::string			getType() const;
		void		makeSound() const;

	protected:
		std::string	type;
};

#endif
