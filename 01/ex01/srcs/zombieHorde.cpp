/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 11:05:57 by ssawa             #+#    #+#             */
/*   Updated: 2026/01/30 11:31:18 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>

void	Zombie::setname(std::string name)
{
	this->name = name;
}

Zombie	*zombieHorde(int N, std::string name )
{
	if (N <= 0)
		return (NULL);

	Zombie	*z = new Zombie[N];
	for (int i = 0; i < N; i++)
		z[i].setname(name);
	return (z);
}
