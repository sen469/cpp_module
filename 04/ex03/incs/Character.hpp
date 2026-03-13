/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 19:15:27 by ssawa             #+#    #+#             */
/*   Updated: 2026/03/11 19:19:08 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "AMateria.hpp"
# include "ICharacter.hpp"
#include <string>
class Character: public ICharacter
{
	public:
		// Constructors
		Character();
		Character(const std::string &name);

		// Destructors
		~Character();

		// Other Functions
		void	equip(AMateria *m);
		void	usequip(int idx);
		void	use(int idx, ICharacter &target);

	private:
		std::string	_name;
};

#endif
