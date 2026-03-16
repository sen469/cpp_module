/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 18:30:37 by ssawa             #+#    #+#             */
/*   Updated: 2026/03/16 14:47:30 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure: public AMateria
{
	public:
		// Constructors
		Cure();
		Cure(const Cure &other);

		// Destructors
		~Cure();

		// Overloaded Operators
		Cure &operator=(const Cure &other);

		// Other Functions
		AMateria	*clone() const;
		void		use(ICharacter &target);
};

#endif
