/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 18:34:04 by ssawa             #+#    #+#             */
/*   Updated: 2026/02/13 19:58:08 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <string>

class ScavTrap: public ClapTrap
{
	public:
		// コンストラクタ
		ScavTrap();
		ScavTrap(const std::string &ame);
		ScavTrap(const ScavTrap &other);

		// デストラクタ
		~ScavTrap(void);

		// 演算子オーバーロード
		ScavTrap &operator=(const ScavTrap &other);

		// メンバ変数
		void	guardGate();
		void	attack(const std::string &target);
	private:
		bool	_guarding_gate;
};

#endif
