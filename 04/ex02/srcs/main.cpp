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
	std::cout << "\n=== Test 1: Abstract class instantiation ===\n" << std::endl;

	// これはコンパイルエラー
	// Animal a;

	// これもエラー
	// Animal* a = new Animal();

	std::cout << "Animal cannot be instantiated (compile-time check)." << std::endl;



	std::cout << "\n=== Test 2: Polymorphism ===\n" << std::endl;

	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << dog->getType() << " sound: ";
	dog->makeSound();

	std::cout << cat->getType() << " sound: ";
	cat->makeSound();



	std::cout << "\n=== Test 3: Delete via Animal pointer ===\n" << std::endl;

	delete dog;
	delete cat;



	std::cout << "\n=== Test 4: Array of Animals ===\n" << std::endl;

	const int N = 6;
	const Animal* animals[N];

	for (int i = 0; i < N / 2; i++)
		animals[i] = new Dog();

	for (int i = N / 2; i < N; i++)
		animals[i] = new Cat();

	for (int i = 0; i < N; i++)
		animals[i]->makeSound();

	for (int i = 0; i < N; i++)
		delete animals[i];



	std::cout << "\n=== Test 5: Copy Constructor ===\n" << std::endl;

	Dog original;
	Dog copy(original);

	std::cout << "Original brain: " << original.getBrain() << std::endl;
	std::cout << "Copy brain:     " << copy.getBrain() << std::endl;



	std::cout << "\n=== Test 6: Assignment Operator ===\n" << std::endl;

	Dog a;
	Dog b;

	b = a;

	std::cout << "a brain: " << a.getBrain() << std::endl;
	std::cout << "b brain: " << b.getBrain() << std::endl;



	std::cout << "\n=== Test 7: Subject test ===\n" << std::endl;

	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;
	delete i;



	std::cout << "\n=== Program End ===\n" << std::endl;

	return 0;
}
