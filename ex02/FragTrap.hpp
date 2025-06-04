#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public ClapTrap
{
private:
	unsigned int fragPoints;
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap &other);
	~FragTrap();

	FragTrap &operator=(const FragTrap &other);

	void attack(const std::string &target);
	void highFivesGuys();
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	unsigned int getFragPoints() const;
};

std::ostream &operator<<(std::ostream &os, const FragTrap &fragTrap);

#endif // FRAGTRAP_HPP