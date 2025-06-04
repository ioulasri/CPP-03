#include "ScavTrap.hpp"
#include <iostream>
#include <unistd.h> // For sleep function

// Helper function to print battle dividers
void printDivider() {
    std::cout << "\n--------------------------------------------------\n" << std::endl;
}

int main() {
    printDivider();
    std::cout << "🤖 WELCOME TO THE EXPANDED CLAPTRAP ARENA! 🤖" << std::endl;
    std::cout << "💪 FEATURING: SCAVTRAP SPECIAL EDITION 💪" << std::endl;
    printDivider();
    
    // Create our contestants
    ScavTrap hero("Hero-TP");
    ScavTrap villain("Villain-TP");
    ClapTrap sidekick("Sidekick-TP");
    
    // Display initial stats to show difference between ScavTrap and ClapTrap
    std::cout << "INITIAL STATUS:" << std::endl;
    std::cout << "SCAVTRAP COMBATANTS:" << std::endl;
    std::cout << hero << std::endl;
    std::cout << villain << std::endl;
    std::cout << "CLAPTRAP COMBATANT:" << std::endl;
    std::cout << sidekick << std::endl;
    
    printDivider();
    std::cout << "ROUND 1: SCAVTRAP SPECIAL ABILITIES" << std::endl;
    sleep(1);
    
    // Demonstrate guardGate special ability
    hero.guardGate();
    villain.guardGate();
    
    printDivider();
    std::cout << "ROUND 2: COMBAT DEMONSTRATION" << std::endl;
    sleep(1);
    
    // Show ScavTrap's stronger attack
    std::cout << "SCAVTRAP VS CLAPTRAP DAMAGE COMPARISON:" << std::endl;
    hero.attack(sidekick.getName());
    sidekick.takeDamage(20);  // ScavTrap likely has higher attack
    std::cout << sidekick << std::endl;
    
    sidekick.attack(villain.getName());
    villain.takeDamage(5);    // ClapTrap has lower damage output
    std::cout << villain << std::endl;
    
    // Healing
    hero.beRepaired(10);
    std::cout << hero << std::endl;
    
    printDivider();
    std::cout << "ROUND 3: ENDURANCE TEST" << std::endl;
    sleep(1);
    
    // Multiple attacks to demonstrate energy capacity
    std::cout << "SCAVTRAP ENERGY RESERVES:" << std::endl;
    for (int i = 0; i < 6; i++) {
        hero.attack("training dummy");
    }
    std::cout << hero << std::endl;
    
    std::cout << "\nCLAPTRAP ENERGY RESERVES:" << std::endl;
    for (int i = 0; i < 6; i++) {
        sidekick.attack("training dummy");
    }
    std::cout << sidekick << std::endl;
    
    printDivider();
    std::cout << "ROUND 4: SCAVTRAP SHOWDOWN" << std::endl;
    sleep(1);
    
    // Final battle between ScavTraps
    villain.attack(hero.getName());
    hero.takeDamage(15);
    std::cout << hero << std::endl;
    
    hero.attack(villain.getName());
    villain.takeDamage(25);
    std::cout << villain << std::endl;
    
    // Last attempt from villain
    villain.guardGate();  // Show we can use special ability even when damaged
    villain.attack(hero.getName());
    villain.beRepaired(10);
    
    // Finish villain
    hero.attack(villain.getName());
    villain.takeDamage(30); // Ensure destruction
    std::cout << villain << std::endl;
    
    printDivider();
    std::cout << "BATTLE RESULTS:" << std::endl;
    std::cout << hero << std::endl;
    std::cout << villain << std::endl;
    std::cout << sidekick << std::endl;
    
    printDivider();
    std::cout << "🏆 HERO-TP WINS THE SCAVTRAP CHAMPIONSHIP! 🏆" << std::endl;
    printDivider();
    
    return 0;
}