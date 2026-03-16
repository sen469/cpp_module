/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 18:52:04 by ssawa             #+#    #+#             */
/*   Updated: 2026/03/16 19:13:18 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(const std::string &type): _type(type) { }

AMateria::AMateria(const AMateria &other): _type(other._type) { }

AMateria::~AMateria() { }

const std::string &AMateria::getType() const
{
	return (this->_type);
}

void	AMateria::use(ICharacter &target)
{
	(void)target;
}
