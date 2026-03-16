/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 18:30:37 by ssawa             #+#    #+#             */
/*   Updated: 2026/03/16 19:01:47 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice: public AMateria
{
	public:
		// Constructors
		Ice();
		Ice(const Ice &other);

		// Desturctors
		~Ice();

		// Overloaded Operators
		Ice &operator=(const Ice &other);

		// Other Functions
		AMateria	*clone() const;
		void		use(ICharacter &target);
};

#endif
