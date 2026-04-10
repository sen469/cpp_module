/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 17:30:39 by ssawa             #+#    #+#             */
/*   Updated: 2026/04/05 17:31:09 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Array.hpp"

#define MAX_VAL 750

int	main()
{
	std::cout << "--- Empty Array Test ---" << std::endl;
	Array<int> empty;
	std::cout << "Size of empty: " << empty.size() << std::endl;

	std::cout << "\n--- Size Array Test ---" << std::endl;
	unsigned int n = 5;
	Array<int> a(n);
	std::cout << "Size of a: " << a.size() << std::endl;
	for (unsigned int i = 0; i < a.size(); i++)
	{
		a[i] = i * 2;
		std::cout << "a[" << i << "] = " << a[i] << std::endl;
	}

	std::cout << "\n--- Copy Constructor Test (Deep Copy) ---" << std::endl;
	Array<int> b(a);
	std::cout << "Size of b: " << b.size() << std::endl;
	std::cout << "Modifying a[0]..." << std::endl;
	a[0] = 100;
	std::cout << "a[0] = " << a[0] << std::endl;
	std::cout << "b[0] = " << b[0] << " (should be 0)" << std::endl;

	std::cout << "\n--- Assignment Operator Test (Deep Copy) ---" << std::endl;
	Array<int> c;
	c = a;
	std::cout << "Size of c: " << c.size() << std::endl;
	std::cout << "Modifying a[1]..." << std::endl;
	a[1] = 200;
	std::cout << "a[1] = " << a[1] << std::endl;
	std::cout << "c[1] = " << c[1] << " (should be 2)" << std::endl;

	std::cout << "\n--- Out of Bounds Test ---" << std::endl;
	try
	{
		std::cout << "Trying to access a[-1]..." << std::endl;
		a[-1] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Caught exception: " << e.what() << '\n';
	}

	try
	{
		std::cout << "Trying to access a[size]..." << std::endl;
		a[a.size()] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Caught exception: " << e.what() << '\n';
	}

	std::cout << "\n--- String Array Test ---" << std::endl;
	Array<std::string> s(2);
	s[0] = "Hello";
	s[1] = "World";
	std::cout << "s[0]: " << s[0] << std::endl;
	std::cout << "s[1]: " << s[1] << std::endl;

	return (0);
}
