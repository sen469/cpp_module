#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
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

	std::cout << "\n===== FragTrap basic test =====\n";
	FragTrap f1("Fragger");
	f1.attack("dummy");
	f1.highFivesGuys();
	f1.takeDamage(50);
	f1.beRepaired(20);

	std::cout << "\n===== Copy constructor test (FragTrap) =====\n";
	FragTrap f2 = f1;
	f2.attack("copy_target");

	std::cout << "\n===== Polymorphism test (FragTrap) =====\n";
	ClapTrap* ptr = new FragTrap("PolyFrag");
	ptr->attack("polymorphic_target");
	delete ptr;

	std::cout << "\n===== End of program =====\n";
	return 0;
}
