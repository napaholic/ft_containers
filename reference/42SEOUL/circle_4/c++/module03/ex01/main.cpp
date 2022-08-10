#include "ScavTrap.hpp"

int main(void) {
	ScavTrap a("A");
	ScavTrap b = a;

	b.setName("B");
	a.printStatus();
	b.printStatus();
	std::cout << std::endl;

	a.attack("B");
	b.takeDamage(a.getAttackDamage());
	a.printStatus();
	b.printStatus();
	std::cout << std::endl;

	a.guardGate();
}