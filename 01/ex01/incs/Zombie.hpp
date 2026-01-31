/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 11:00:45 by ssawa             #+#    #+#             */
/*   Updated: 2026/01/31 16:35:21 by ssawa            ###   ########.fr       */
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
		Zombie( void );
		~Zombie(void);
		void	announce( void ) const;
		void	setname( std::string name );
};

Zombie	*zombieHorde(int N, std::string name );

#endif
