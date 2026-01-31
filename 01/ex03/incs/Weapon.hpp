/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 21:44:57 by ssawa             #+#    #+#             */
/*   Updated: 2026/01/31 16:35:42 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>
class Weapon
{
	private:
		std::string	_type;
	public:
		Weapon(std::string);
		void		setType(std::string type);
		std::string	getType(void) const;
};

#endif
