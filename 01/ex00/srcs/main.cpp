/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 23:11:50 by ssawa             #+#    #+#             */
/*   Updated: 2026/01/29 23:47:21 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>

int	main()
{
	randomChump("StackZombie");
	Zombie *z = newZombie("HeapZombie");
	z->announce();
	delete z;
	return (0);
}
