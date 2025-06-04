#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default FragTrap"), fragPoints(100) {
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap " << getName() << " created with default constructor." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name), fragPoints(100) {
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap " << getName() << " created with parameterized constructor." << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other), fragPoints(other.fragPoints) {
	std::cout << "FragTrap " << getName() << " created with copy constructor." << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << getName() << " destroyed." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
	if (this != &other) {
		ClapTrap::operator=(other);
		fragPoints = other.fragPoints;
		std::cout << "FragTrap " << getName() << " assigned." << std::endl;
	}
	return *this;
}

void FragTrap::attack(const std::string &target) {
	if (energyPoints > 0 && hitPoints > 0) {
		std::cout << "FragTrap " << getName() << " attacks " << target 
		          << ", causing " << attackDamage << " points of damage!" << std::endl;
		energyPoints--;
	} else {
		std::cout << "FragTrap " << getName() << " cannot attack!" << std::endl;
	}
}

void FragTrap::highFivesGuys() {
	if (hitPoints > 0) {
		std::cout << "FragTrap " << getName() << " requests a high five!" << std::endl;
	} else {
		std::cout << "FragTrap " << getName() << " is too damaged to request a high five!" << std::endl;
	}
}

void FragTrap::takeDamage(unsigned int amount) {
	if (hitPoints > amount) {
		hitPoints -= amount;
		std::cout << "FragTrap " << getName() << " takes " << amount 
		          << " points of damage! Remaining hit points: " << hitPoints << std::endl;
	} else {
		hitPoints = 0;
		std::cout << "FragTrap " << getName() << " has been destroyed!" << std::endl;
	}
}

void FragTrap::beRepaired(unsigned int amount) {
	if (energyPoints > 0 && hitPoints > 0) {
		hitPoints += amount;
		energyPoints--;
		std::cout << "FragTrap " << getName() << " repairs itself for " << amount 
		          << " points! Current hit points: " << hitPoints << std::endl;
	} else {
		std::cout << "FragTrap " << getName() << " cannot be repaired!" << std::endl;
	}
}

unsigned int FragTrap::getFragPoints() const {
	return fragPoints;
}

std::ostream &operator<<(std::ostream &os, const FragTrap &fragTrap) {
	os << "FragTrap " << fragTrap.getName() 
	   << " [Hit Points: " << fragTrap.getHitPoints() 
	   << ", Energy Points: " << fragTrap.getEnergyPoints() 
	   << ", Attack Damage: " << fragTrap.getAttackDamage() 
	   << ", Frag Points: " << fragTrap.getFragPoints() << "]";
	return os;
}