/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 10:37:20 by ssawa             #+#    #+#             */
/*   Updated: 2026/03/25 10:37:52 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    // --- Test 1: 正常な署名 ---
    std::cout << "--- Test 1: Successful Sign ---" << std::endl;
    try
    {
        Bureaucrat president("President", 1);
        Form taxForm("Tax Form", 10, 5);

        std::cout << president;
        std::cout << taxForm;

        president.signForm(taxForm);
        std::cout << taxForm;
    }
    catch (std::exception &e)
    {
        std::cerr << "Unexpected Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 2: Grade Too Low to Sign ---" << std::endl;
    try
    {
        Bureaucrat intern("Intern", 150);
        Form topSecret("Top Secret Document", 1, 1);

        std::cout << intern;
        std::cout << topSecret;
        intern.signForm(topSecret);
        std::cout << topSecret;
    }
    catch (std::exception &e)
    {
        std::cerr << "Main caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 3: Form Creation Exception ---" << std::endl;
    try
    {
        Form invalidForm("Illegal Form", 0, 151);
    }
    catch (std::exception &e)
    {
        std::cerr << "Caught expected error: " << e.what() << std::endl;
    }

    return (0);
}
