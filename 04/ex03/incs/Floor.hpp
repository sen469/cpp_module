/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 17:46:03 by ssawa             #+#    #+#             */
/*   Updated: 2026/03/16 18:28:10 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOOR_HPP
# define FLOOR_HPP

#include "AMateria.hpp"
typedef struct s_floor_node
{
	AMateria	*m;
	struct s_floor_node	*nxt;
}	t_floor_node;

class Floor
{
	public:
		Floor();
		~Floor();
		void	add_front(AMateria *m);

	private:
		t_floor_node	*_head;
};

#endif
