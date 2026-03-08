/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 10:26:08 by ssawa             #+#    #+#             */
/*   Updated: 2026/03/08 18:37:15 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"
# include <string>

class DiamondTrap: public ScavTrap, public FragTrap
{
	public:
		// コンストラクタ引数なし
		DiamondTrap();
		// コンストラクタ引数あり
		DiamondTrap(std::string name);
		// コピーコンストラクタ
		DiamondTrap(const DiamondTrap &other);
		// 代入演算子オーバーロード
		DiamondTrap &operator=(const DiamondTrap &other);
		// デストラクタ
		~DiamondTrap();
		// メンバ関数
		void		attack(const std::string &target);
		void		whoAmI();

		void		show_name();
		void		show_hp();
		void		show_dmg();
		void		show_energy();
	private:
		std::string	_name;

};

#endif
