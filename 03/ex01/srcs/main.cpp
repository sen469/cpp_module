#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "===== ClapTrap basic test =====\n";
	ClapTrap a("Alpha");
	a.attack("enemy");
	a.takeDamage(3);
	a.beRepaired(5);

	std::cout << "\n===== ScavTrap basic test =====\n";
	ScavTrap s1("Guardian");
	s1.attack("intruder");
	s1.guardGate();
	s1.takeDamage(30);
	s1.beRepaired(10);

	std::cout << "\n===== Copy constructor test =====\n";
	ScavTrap s2 = s1;   // copy ctor
	s2.attack("copy_target");

	std::cout << "\n===== Copy assignment test =====\n";
	ScavTrap s3("Temp");
	s3 = s1;            // operator=
	s3.attack("assigned_target");

	std::cout << "\n===== Polymorphism test =====\n";
	ClapTrap* ptr = new ScavTrap("Poly");
	ptr->attack("polymorphic_target");
	delete ptr;  // destructor chain確認

	std::cout << "\n===== End of program =====\n";
	return 0;
}
