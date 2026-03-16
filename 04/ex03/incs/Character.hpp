/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 19:15:27 by ssawa             #+#    #+#             */
/*   Updated: 2026/03/16 18:14:14 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "Floor.hpp"
# include "ICharacter.hpp"
# include "constants.hpp"
#include "AMateria.hpp"
# include <string>


class Character: public ICharacter
{
	public:
		// Constructors
		Character();
		Character(const std::string &name);
		Character(const Character &other);

		// Destructors
		~Character();

		// Overloaded Opeartors
		Character &operator=(const Character &other);

		// Getter
		const std::string &getName() const;

		// Other Functions
		void	equip(AMateria *m);
		void	unequip(int idx);
		void	use(int idx, ICharacter &target);

	private:
		std::string	_name;
		AMateria	*_inventory[INVENTORY_SIZE];
		Floor		_floor;
};

#endif
