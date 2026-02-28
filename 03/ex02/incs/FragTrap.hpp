/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 00:53:55 by ssawa             #+#    #+#             */
/*   Updated: 2026/02/23 01:35:08 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	public:
		// コンストラクタ
		FragTrap();
		FragTrap(const std::string &name);
		FragTrap(const FragTrap &other);
		FragTrap &operator=(const FragTrap &other);

		// デストラクタ
		~FragTrap();

		// メンバ関数
		void	highFivesGuys(void);
	private:
};

#endif
