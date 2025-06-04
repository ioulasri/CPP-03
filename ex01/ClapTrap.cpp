#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap " << name << " created with default constructor." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap " << name << " created with parameterized constructor." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : name(other.name), hitPoints(other.hitPoints), 
	energyPoints(other.energyPoints), attackDamage(other.attackDamage) {
	std::cout << "ClapTrap " << name << " created with copy constructor." << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << name << " destroyed." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	if (this != &other) {
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
		std::cout << "ClapTrap " << name << " assigned." << std::endl;
	}
	return *this;
}

void ClapTrap::attack(const std::string &target) {
	if (energyPoints > 0 && hitPoints > 0) {
		std::cout << "ClapTrap " << name << " attacks " << target 
		          << ", causing " << attackDamage << " points of damage!" << std::endl;
		energyPoints--;
	} else {
		std::cout << "ClapTrap " << name << " cannot attack!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (hitPoints > amount) {
		hitPoints -= amount;
		std::cout << "ClapTrap " << name << " takes " << amount 
		          << " points of damage! Remaining hit points: " << hitPoints << std::endl;
	} else {
		hitPoints = 0;
		std::cout << "ClapTrap " << name << " has been destroyed!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (energyPoints > 0 && hitPoints > 0) {
		hitPoints += amount;
		energyPoints--;
		std::cout << "ClapTrap " << name << " repairs itself for " << amount 
		          << " points! Current hit points: " << hitPoints << std::endl;
	} else {
		std::cout << "ClapTrap " << name << " cannot be repaired!" << std::endl;
	}
}

const std::string &ClapTrap::getName() const {
	return name;
}

unsigned int ClapTrap::getHitPoints() const {
	return hitPoints;
}

unsigned int ClapTrap::getEnergyPoints() const {
	return energyPoints;
}

unsigned int ClapTrap::getAttackDamage() const {
	return attackDamage;
}

std::ostream &operator<<(std::ostream &os, const ClapTrap &clapTrap) {
	os << "ClapTrap " << clapTrap.getName() 
	   << " [Hit Points: " << clapTrap.getHitPoints() 
	   << ", Energy Points: " << clapTrap.getEnergyPoints() 
	   << ", Attack Damage: " << clapTrap.getAttackDamage() << "]";
	return os;
}
