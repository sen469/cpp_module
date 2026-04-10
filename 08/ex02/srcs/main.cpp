/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 16:08:16 by ssawa             #+#    #+#             */
/*   Updated: 2026/04/10 17:03:26 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include "MutantStack.hpp"

int	main()
{
	std::cout << "--- MutantStack Test ---" << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "Top: " << mstack.top() << std::endl;

	mstack.pop();

	std::cout << "Size: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	std::cout << "Contents:" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "\n--- std::list Test (Compare with MutantStack) ---" << std::endl;
	std::list<int> ltest;
	ltest.push_back(5);
	ltest.push_back(17);
	ltest.pop_back();
	ltest.push_back(3);
	ltest.push_back(5);
	ltest.push_back(737);
	ltest.push_back(0);

	std::list<int>::iterator lit = ltest.begin();
	std::list<int>::iterator lite = ltest.end();
	while (lit != lite)
	{
		std::cout << *lit << std::endl;
		++lit;
	}

	std::cout << "\n--- Const Iterator and Reverse Iterator Test ---" << std::endl;
	const MutantStack<int> const_mstack(mstack);
	MutantStack<int>::const_iterator cit = const_mstack.begin();
	MutantStack<int>::const_iterator cite = const_mstack.end();
	std::cout << "Const contents:" << std::endl;
	while (cit != cite)
	{
		std::cout << *cit << std::endl;
		++cit;
	}

	std::cout << "Reverse contents:" << std::endl;
	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();
	while (rit != rite)
	{
		std::cout << *rit << std::endl;
		++rit;
	}

	return (0);
}
