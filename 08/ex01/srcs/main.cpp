/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 18:29:06 by ssawa             #+#    #+#             */
/*   Updated: 2026/04/10 15:00:00 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <exception>

int main()
{
	std::cout << "--- Subject Basic Test ---" << std::endl;
	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Shortest Span: " << sp.shortestSpan() << " (Expected: 2)" << std::endl;
		std::cout << "Longest Span:  " << sp.longestSpan() << " (Expected: 14)" << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n--- Edge Case: Empty/Single Element ---" << std::endl;
	try {
		Span sp = Span(5);
		sp.addNumber(42);
		std::cout << sp.shortestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Expected Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Large Data Test (15,000 numbers) ---" << std::endl;
	try {
		unsigned int n = 15000;
		Span sp = Span(n);
		std::vector<int> v;
		for (unsigned int i = 0; i < n; ++i)
			v.push_back(i * 3); // 0, 3, 6, ..., 44997
		
		// 現状の実装（ループで1つずつ追加）
		for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
			sp.addNumber(*it);

		std::cout << "Shortest Span: " << sp.shortestSpan() << " (Expected: 3)" << std::endl;
		std::cout << "Longest Span:  " << sp.longestSpan() << " (Expected: 44997)" << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}
