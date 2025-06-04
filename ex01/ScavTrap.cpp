#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default ScavTrap"), guardMode(false) {
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap " << getName() << " created with default constructor." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), guardMode(false) {
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap " << getName() << " created with parameterized constructor." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other), guardMode(other.guardMode) {
	std::cout << "ScavTrap " << getName() << " created with copy constructor." << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << getName() << " destroyed." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	if (this != &other) {
		ClapTrap::operator=(other);
		guardMode = other.guardMode;
		std::cout << "ScavTrap " << getName() << " assigned." << std::endl;
	}
	return *this;
}

void ScavTrap::attack(const std::string &target) {
	if (energyPoints > 0 && hitPoints > 0) {
		std::cout << "ScavTrap " << getName() << " attacks " << target 
		          << ", causing " << attackDamage << " points of damage!" << std::endl;
		energyPoints--;
	} else {
		std::cout << "ScavTrap " << getName() << " cannot attack!" << std::endl;
	}
}

void ScavTrap::guardGate() {
	guardMode = true;
	std::cout << "ScavTrap " << getName() << " is now in guard mode!" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount) {
	if (hitPoints > amount) {
		hitPoints -= amount;
		std::cout << "ScavTrap " << getName() << " takes " << amount 
		          << " points of damage! Remaining hit points: " << hitPoints << std::endl;
	} else {
		hitPoints = 0;
		std::cout << "ScavTrap " << getName() << " has been destroyed!" << std::endl;
	}
}

void ScavTrap::beRepaired(unsigned int amount) {
	if (energyPoints > 0 && hitPoints > 0) {
		hitPoints += amount;
		energyPoints--;
		std::cout << "ScavTrap " << getName() << " repairs itself for " << amount 
		          << " points! Current hit points: " << hitPoints << std::endl;
	} else {
		std::cout << "ScavTrap " << getName() << " cannot be repaired!" << std::endl;
	}
}

bool ScavTrap::isGuardMode() const {
	return guardMode;
}

std::ostream &operator<<(std::ostream &os, const ScavTrap &scavTrap) {
	os << "ScavTrap " << scavTrap.getName() 
	   << " | Hit Points: " << scavTrap.getHitPoints() 
	   << ", Energy Points: " << scavTrap.getEnergyPoints() 
	   << ", Attack Damage: " << scavTrap.getAttackDamage() 
	   << ", Guard Mode: " << (scavTrap.isGuardMode() ? "ON" : "OFF");
	return os;
}