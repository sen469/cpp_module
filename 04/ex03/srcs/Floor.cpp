/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 17:49:13 by ssawa             #+#    #+#             */
/*   Updated: 2026/03/16 18:28:10 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Floor.hpp"

Floor::Floor(): _head(NULL) { }

Floor::~Floor()
{
	t_floor_node	*tmp;

	while (_head != NULL)
	{
		tmp = this->_head->nxt;
		delete this->_head->m;
		delete _head;
		this->_head = tmp;
	}
}

void	Floor::add_front(AMateria *m)
{
	if (m == NULL)
	{
		return;
	}
	t_floor_node	*new_node = new t_floor_node;
	new_node->m = m;
	new_node->nxt = this->_head;
	this->_head = new_node;
}
