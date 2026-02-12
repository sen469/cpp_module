/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 13:38:02 by ssawa             #+#    #+#             */
/*   Updated: 2026/02/09 15:51:08 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
return 0;
}

// int main()
// {
//     Fixed a(5);
//     Fixed b(2);
//
//     std::cout << "a = " << a << std::endl;
//     std::cout << "b = " << b << std::endl;
//     std::cout << std::endl;
//
//     std::cout << "a + b = " << a + b << std::endl;
//     std::cout << "a - b = " << a - b << std::endl;
//     std::cout << "a * b = " << a * b << std::endl;
//     std::cout << "a / b = " << a / b << std::endl;
//     std::cout << std::endl;
//
//     Fixed c(1.5f);
//     Fixed d(2);
//
//     std::cout << "c = " << c << std::endl;
//     std::cout << "d = " << d << std::endl;
//     std::cout << std::endl;
//
//     std::cout << "c * d = " << c * d << std::endl;
//     std::cout << "c / d = " << c / d << std::endl;
//     std::cout << std::endl;
//
//     std::cout << "Comparisons:" << std::endl;
//     std::cout << "a > b : " << (a > b) << std::endl;
//     std::cout << "a < b : " << (a < b) << std::endl;
//     std::cout << "a == b : " << (a == b) << std::endl;
//     std::cout << "a != b : " << (a != b) << std::endl;
//     std::cout << std::endl;
//
//     std::cout << "Increment tests:" << std::endl;
//     Fixed x(3);
//     std::cout << "x = " << x << std::endl;
//     std::cout << "++x = " << ++x << std::endl;
//     std::cout << "x after ++ = " << x << std::endl;
//     std::cout << "x++ = " << x++ << std::endl;
//     std::cout << "x after x++ = " << x << std::endl;
//
//     return 0;
// }
