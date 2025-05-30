#include "ClapTrap.hpp"
#include <iostream>
#include <unistd.h> // For sleep function

// Helper function to print battle dividers
void printDivider() {
    std::cout << "\n--------------------------------------------------\n" << std::endl;
}

int main() {
    printDivider();
    std::cout << "🤖 WELCOME TO THE CLAPTRAP ARENA! 🤖" << std::endl;
    printDivider();
    
    // Create our contestants
    ClapTrap hero("Hero-TP");
    ClapTrap villain("Villain-TP");
    ClapTrap medic("Medic-TP");
    
    // Display initial stats
    std::cout << "INITIAL STATUS:" << std::endl;
    std::cout << hero << std::endl;
    std::cout << villain << std::endl;
    std::cout << medic << std::endl;
    
    printDivider();
    std::cout << "ROUND 1: FIRST BLOOD" << std::endl;
    sleep(1);
    
    // First attack
    hero.attack(villain.getName());
    villain.takeDamage(3); // Let's pretend hero has more attack power
    std::cout << villain << std::endl;
    
    // Counterattack
    villain.attack(hero.getName());
    hero.takeDamage(2);
    std::cout << hero << std::endl;
    
    // Healing
    medic.attack("healing station");
    hero.beRepaired(5);
    std::cout << hero << std::endl;
    
    printDivider();
    std::cout << "ROUND 2: THE STRUGGLE" << std::endl;
    sleep(1);
    
    // Multiple attacks to drain energy
    for (int i = 0; i < 5; i++) {
        hero.attack(villain.getName());
        if (i % 2 == 0) {
            villain.takeDamage(1);
        }
    }
    
    std::cout << "\nAfter multiple attacks:" << std::endl;
    std::cout << hero << std::endl;
    std::cout << villain << std::endl;
    
    printDivider();
    std::cout << "ROUND 3: LAST STAND" << std::endl;
    sleep(1);
    
    // Almost destroying villain
    hero.attack(villain.getName());
    villain.takeDamage(6);
    std::cout << villain << std::endl;
    
    // Villain attempts to repair but fails
    if (villain.getHitPoints() == 1) {
        std::cout << "\nVillain-TP is hanging on by a thread!" << std::endl;
    }
    villain.beRepaired(5);
    
    // Medic helps villain
    medic.attack("emergency kit");
    villain.beRepaired(3);
    std::cout << villain << std::endl;
    
    printDivider();
    std::cout << "FINAL ROUND: KNOCKOUT" << std::endl;
    sleep(1);
    
    // Finish villain
    hero.attack(villain.getName());
    villain.takeDamage(10); // Ensure destruction
    std::cout << villain << std::endl;
    
    // Try actions after destruction
    villain.attack(hero.getName());
    villain.beRepaired(10);
    
    printDivider();
    std::cout << "BATTLE RESULTS:" << std::endl;
    std::cout << hero << std::endl;
    std::cout << villain << std::endl;
    std::cout << medic << std::endl;
    
    printDivider();
    std::cout << "🏆 HERO-TP WINS THE BATTLE! 🏆" << std::endl;
    printDivider();
    
    return 0;
}