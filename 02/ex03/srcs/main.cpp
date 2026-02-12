/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:36:35 by ssawa             #+#    #+#             */
/*   Updated: 2026/02/12 17:16:15 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

Fixed	cross(Point const &o, Point const &a, Point const &b)
{
	Point	oa = a - o;
	Point	ob = b - o;
	return (oa.get_x() * ob.get_y() - oa.get_y() * ob.get_x());
}

bool	bsp(Point const a, Point const b, Point const c, Point const p)
{
	Fixed	ab = cross(a, b, p);
	Fixed	bc = cross(b, c, p);
	Fixed	ca = cross(c, a, p);

	if (ab == Fixed(0) || bc == Fixed(0) || ca == Fixed(0))
		return (false);
	return ((ab > Fixed(0) && bc > Fixed(0) && ca > Fixed(0)) || \
		(ab < Fixed(0) && bc < Fixed(0) && ca < Fixed(0)));
}

void	test(Point a, Point b, Point c, Point p, const std::string& label)
{
	std::cout << label << ": ";
	if (bsp(a, b, c, p))
		std::cout << "Yes";
	else
		std::cout << "No";
	std::cout << std::endl;
}

int	main()
{
	Point	a(0,0);
	Point	b(4,0);
	Point	c(0,4);

	std::cout << "--- Basic inside ---" << std::endl;
	test(a,b,c,Point(1,1)," (1,1)");
	test(a,b,c,Point(0.5f,0.5f)," (0.5,0.5)");
	test(a,b,c,Point(1.5f,0.5f)," (1.5,0.5)");

	std::cout << "\n--- Outside ---" << std::endl;
	test(a,b,c,Point(5,5)," (5,5)");
	test(a,b,c,Point(-1,1)," (-1,1)");
	test(a,b,c,Point(1,-1)," (1,-1)");
	test(a,b,c,Point(3,3)," (3,3)");

	std::cout << "\n--- On edges ---" << std::endl;
	test(a,b,c,Point(2,0)," (2,0)");
	test(a,b,c,Point(0,2)," (0,2)");
	test(a,b,c,Point(2,2)," (2,2)");

	std::cout << "\n--- On vertices ---" << std::endl;
	test(a,b,c,Point(0,0)," (0,0)");
	test(a,b,c,Point(4,0)," (4,0)");
	test(a,b,c,Point(0,4)," (0,4)");
	return (0);
}
