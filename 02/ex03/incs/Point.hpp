/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:52:44 by ssawa             #+#    #+#             */
/*   Updated: 2026/02/12 17:09:06 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	public:
		// コンストラクタ
		Point();
		Point(float x, float y);
		Point(const Point &other);

		// 演算子オーバーロード
		Point	&operator=(const Point &other);
		Point	operator-(const Point &other) const;

		// デストラクタ
		~Point();

		// メンバ関数
		Fixed	get_x() const;
		Fixed	get_y() const;
	private:
		Fixed	_x;
		Fixed	_y;
};


#endif
