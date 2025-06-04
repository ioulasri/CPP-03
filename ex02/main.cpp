#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>
#include <unistd.h> // For sleep function

// Helper function to print battle dividers
void printDivider() {
    std::cout << "\n--------------------------------------------------\n" << std::endl;
}

int main() {
    printDivider();
    std::cout << "🤖 WELCOME TO THE ULTIMATE TRAP ARENA! 🤖" << std::endl;
    std::cout << "💪 FEATURING: SCAVTRAP AND FRAGTRAP SPECIAL EDITION 💪" << std::endl;
    printDivider();
    
    // Create our contestants
    ScavTrap defender("Defender-TP");
    FragTrap attacker("Attacker-TP");
    ClapTrap support("Support-TP");
    
    // Display initial stats to show differences between trap types
    std::cout << "INITIAL STATUS:" << std::endl;
    std::cout << "FRAGTRAP COMBATANT:" << std::endl;
    std::cout << attacker << std::endl;
    std::cout << "SCAVTRAP COMBATANT:" << std::endl;
    std::cout << defender << std::endl;
    std::cout << "CLAPTRAP COMBATANT:" << std::endl;
    std::cout << support << std::endl;
    
    printDivider();
    std::cout << "ROUND 1: SPECIAL ABILITIES SHOWCASE" << std::endl;
    sleep(1);
    
    // Demonstrate special abilities
    defender.guardGate();
    attacker.highFivesGuys();
    
    printDivider();
    std::cout << "ROUND 2: COMBAT CAPABILITIES" << std::endl;
    sleep(1);
    
    // Show FragTrap's attack power
    std::cout << "FRAGTRAP VS SCAVTRAP DAMAGE COMPARISON:" << std::endl;
    attacker.attack(defender.getName());
    defender.takeDamage(30);  // FragTrap has high attack damage
    std::cout << defender << std::endl;
    
    defender.attack(attacker.getName());
    attacker.takeDamage(20);  // ScavTrap has medium attack damage
    std::cout << attacker << std::endl;
    
    // ClapTrap tries to help
    support.attack(attacker.getName());
    attacker.takeDamage(5);   // ClapTrap has low damage
    std::cout << attacker << std::endl;
    
    // Everyone repairs
    std::cout << "\nREPAIR SEQUENCE:" << std::endl;
    attacker.beRepaired(20);
    defender.beRepaired(15);
    support.beRepaired(5);
    
    printDivider();
    std::cout << "ROUND 3: ENDURANCE TEST" << std::endl;
    sleep(1);
    
    // Demonstrate FragTrap's high hit points
    std::cout << "SUSTAINED DAMAGE TEST:" << std::endl;
    for (int i = 0; i < 3; i++) {
        defender.attack(attacker.getName());
        attacker.takeDamage(10);
        std::cout << attacker << std::endl;
    }
    
    // Show energy consumption
    std::cout << "\nENERGY CONSUMPTION TEST:" << std::endl;
    for (int i = 0; i < 5; i++) {
        attacker.attack("training dummy");
    }
    std::cout << attacker << std::endl;
    
    printDivider();
    std::cout << "FINAL ROUND: ULTIMATE SHOWDOWN" << std::endl;
    sleep(1);
    
    // FragTrap special attack sequence
    attacker.highFivesGuys();
    std::cout << "FragTrap " << attacker.getName() << " channels the power of friendship!" << std::endl;
    attacker.attack(defender.getName());
    defender.takeDamage(50);
    std::cout << defender << std::endl;
    
    // ScavTrap's last stand
    if (defender.getHitPoints() > 0) {
        defender.guardGate();
        defender.attack(attacker.getName());
        attacker.takeDamage(15);
        std::cout << attacker << std::endl;
    }
    
    printDivider();
    std::cout << "BATTLE RESULTS:" << std::endl;
    std::cout << attacker << std::endl;
    std::cout << defender << std::endl;
    std::cout << support << std::endl;
    
    printDivider();
    std::cout << "🏆 THE POWER OF HIGH FIVES PREVAILS! 🏆" << std::endl;
    printDivider();
    
    return 0;
}