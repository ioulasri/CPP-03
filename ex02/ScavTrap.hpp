#ifndef SCAVTR_HPP
#define SCAVTR_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : public ClapTrap
{
private:
	bool guardMode;
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &other);
	~ScavTrap();

	ScavTrap &operator=(const ScavTrap &other);

	void attack(const std::string &target);
	void guardGate();
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	bool isGuardMode() const;
};

std::ostream &operator<<(std::ostream &os, const ScavTrap &scavTrap);


#endif // SCAVTR_HPP