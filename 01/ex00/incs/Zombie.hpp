/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 22:26:28 by ssawa             #+#    #+#             */
/*   Updated: 2026/01/31 16:35:05 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie
{
	private:
		std::string	_name;
	public:
		Zombie( std::string name );
		~Zombie(void);
		void	announce ( void ) const;
};

void	randomChump(std::string name);
Zombie	*newZombie(std::string name);

#endif
