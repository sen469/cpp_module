/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 11:31:21 by ssawa             #+#    #+#             */
/*   Updated: 2026/03/11 17:07:22 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	const int n = 6;
	const Animal* animals[n];

	std::cout << "\n--- Create Animals ---\n" << std::endl;

	for (int i = 0; i < n / 2; i++)
		animals[i] = new Dog();

	for (int i = n / 2; i < n; i++)
		animals[i] = new Cat();

	std::cout << "\n--- Make Sounds ---\n" << std::endl;

	for (int i = 0; i < n; i++)
		animals[i]->makeSound();

	std::cout << "\n--- Delete Animals ---\n" << std::endl;

	for (int i = 0; i < n; i++)
		delete animals[i];

	std::cout << "\n--- Deep Copy Test ---\n" << std::endl;

	Dog original;
	Dog copy = original;   // copy constructor

	std::cout << "Original brain address: " << original.getBrain() << std::endl;
	std::cout << "Copy brain address:     " << copy.getBrain() << std::endl;

	std::cout << "\n--- Assignment Test ---\n" << std::endl;

	Dog a;
	Dog b;

	b = a;  // operator=

	std::cout << "a brain address: " << a.getBrain() << std::endl;
	std::cout << "b brain address: " << b.getBrain() << std::endl;

	std::cout << "\n--- Subject Test ---\n" << std::endl;

	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;
	delete i;

	return 0;
}
