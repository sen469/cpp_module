/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 18:26:24 by ssawa             #+#    #+#             */
/*   Updated: 2026/03/11 18:52:47 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <string>

class ICharacter;

class AMateria
{
	protected:
		std::string	_type;

	public:
		AMateria(std::string const &type);

		std::string const &getType() const;

		virtual AMateria	*clone() const = 0;
		virtual void		use(ICharacter &target);
};

#endif
