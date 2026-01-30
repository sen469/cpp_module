/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 11:04:08 by ssawa             #+#    #+#             */
/*   Updated: 2026/01/30 11:32:03 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int	main(void)
{
	int	N = 10;
	Zombie	*z;

	z = zombieHorde(N, "HeapZ");
	if (z == NULL)
		return (1);
	for (int i = 0; i < N; i++)
		z[i].announce();
	if (z != NULL)
		delete[] z;
	return (0);
}
