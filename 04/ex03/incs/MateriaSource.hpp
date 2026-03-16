/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 18:09:21 by ssawa             #+#    #+#             */
/*   Updated: 2026/03/16 18:51:43 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "constants.hpp"

class MateriaSource: public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &other);

		~MateriaSource();

		MateriaSource	&operator=(const MateriaSource &other);

		void		learnMateria(AMateria *);
		AMateria	*createMateria(const std::string &type);
	private:
		AMateria	*_inventory[INVENTORY_SIZE];
};

#endif
