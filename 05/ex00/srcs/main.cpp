/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 18:41:27 by ssawa             #+#    #+#             */
/*   Updated: 2026/03/24 18:47:02 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

void	test_creation(const std::string &name, int grade)
{
	std::cout << "--- Testing creation of " << name << " with grade " << grade << " ---" << std::endl;
	try
	{
		Bureaucrat b(name, grade);
		std::cout << b;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	test_increment(const std::string &name, int grade)
{
	std::cout << "--- Testing increment for " << name << " with grade " << grade << " ---" << std::endl;
	try
	{
		Bureaucrat b(name, grade);
		std::cout << "Before: " << b;
		b.incrementGrade();
		std::cout << "After increment: " << b;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	test_decrement(const std::string &name, int grade)
{
	std::cout << "--- Testing decrement for " << name << " with grade " << grade << " ---" << std::endl;
	try
	{
		Bureaucrat b(name, grade);
		std::cout << "Before: " << b;
		b.decrementGrade();
		std::cout << "After decrement: " << b;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

int	main()
{
	// Test valid creations
	test_creation("Alice", 1);
	test_creation("Bob", 150);
	test_creation("Charlie", 75);

	// Test invalid creations
	test_creation("TooHigh", 0);
	test_creation("TooLow", 151);

	// Test increment
	test_increment("Dave", 2);
	test_increment("Eve", 1); // Should throw

	// Test decrement
	test_decrement("Frank", 149);
	test_decrement("Grace", 150); // Should throw

	// Test copy constructor and assignment operator
	std::cout << "--- Testing copy and assignment ---" << std::endl;
	Bureaucrat original("Original", 42);
	Bureaucrat copy(original);
	Bureaucrat assigned("Assigned", 100);
	assigned = original;

	std::cout << "Original: " << original;
	std::cout << "Copy:     " << copy;
	std::cout << "Assigned: " << assigned;

	return (0);
}
