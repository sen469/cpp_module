/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 18:24:30 by ssawa             #+#    #+#             */
/*   Updated: 2026/04/10 10:00:00 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include <list>
#include <deque>
#include <exception>
#include <string>
#include "easyfind.hpp"

template <typename T>
void test_easyfind(T &container, int target, const std::string& type_name)
{
	std::cout << "Testing " << type_name << " for value: " << target << std::endl;
	try
	{
		typename T::iterator it = easyfind(container, target);
		std::cout << "  Found: " << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "  Caught exception: " << e.what() << std::endl;
	}
}

int	main()
{
	// --- Vectorのテスト ---
	std::cout << "--- Testing std::vector ---" << std::endl;
	std::vector<int> v;
	for (int i = 1; i <= 5; ++i) v.push_back(i * 10); // 10, 20, 30, 40, 50

	test_easyfind(v, 20, "std::vector");
	test_easyfind(v, 42, "std::vector (missing)");

	// --- Listのテスト ---
	std::cout << "\n--- Testing std::list ---" << std::endl;
	std::list<int> l;
	l.push_back(100);
	l.push_back(200);
	l.push_back(300);

	test_easyfind(l, 300, "std::list");
	test_easyfind(l, -1, "std::list (missing)");

	// --- Dequeのテスト ---
	std::cout << "\n--- Testing std::deque ---" << std::endl;
	std::deque<int> d;
	d.push_front(5);
	d.push_back(15);
	
	test_easyfind(d, 5, "std::deque");

	// --- 空のコンテナのテスト ---
	std::cout << "\n--- Testing Empty Container ---" << std::endl;
	std::vector<int> empty_v;
	test_easyfind(empty_v, 1, "empty std::vector");

	// --- 重複する値のテスト ---
	std::cout << "\n--- Testing Duplicates ---" << std::endl;
	std::vector<int> dups;
	dups.push_back(42);
	dups.push_back(7);
	dups.push_back(42);
	dups.push_back(9);

	try
	{
		std::cout << "  Searching for 42 in [42, 7, 42, 9]" << std::endl;
		std::vector<int>::iterator it = easyfind(dups, 42);
		std::cout << "  Found: " << *it << std::endl;
		
		// 最初の42であることを確認
		if (it == dups.begin())
			std::cout << "  Success: It is the first occurrence." << std::endl;
		else
			std::cout << "  Failure: It is NOT the first occurrence." << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "  Caught exception: " << e.what() << std::endl;
	}

	return 0;
}
