/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 13:38:10 by ssawa             #+#    #+#             */
/*   Updated: 2026/02/09 16:51:00 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <ostream>

class Fixed
{
	public:
		Fixed();
		Fixed(int n);
		Fixed(float f);
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);
		Fixed &operator++(void);
		Fixed operator++(int);
		Fixed operator*(const Fixed &other) const;
		~Fixed(void);
		int					getRawBits(void) const;
		void				setRawBits(const int raw);
		float				toFloat(void) const;
		int					toInt(void) const;
		static Fixed	&max(Fixed &a, Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);
	private:
		int					_rawbits;
		static const int	_fractional_bits = 8;
};

std::ostream &operator<<(std::ostream &os, const Fixed &other);

#endif
