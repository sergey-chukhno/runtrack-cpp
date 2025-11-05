#include <iostream>
#include "Character.hpp"
#include "Weapon.hpp"
#include "Bow.hpp"
#include "Spear.hpp"
#include "Sword.hpp"

using namespace std;

/**
 * Test program for Weapon system
 * 
 * Demonstrates:
 * - Weapon interface (abstract class)
 * - Concrete weapon implementations (Bow, Spear, Sword)
 * - Strategy Pattern (different attack strategies)
 * - Polymorphism (Weapon pointers to different types)
 * - Integration with Character class
 * - Game balance (range vs power tradeoff)
 */
int main() {
    cout << "========================================" << endl;
    cout << "  Weapon System Test - Campus Quest    " << endl;
    cout << "========================================" << endl;
    cout << endl;
    
    
    // ========== TEST 1: Creating Weapons ==========
    cout << "TEST 1: Creating Weapons" << endl;
    cout << "------------------------" << endl;
    
    Bow bow;
    Spear spear;
    Sword sword;
    
    cout << "Created " << bow.getName() << ": Range=" << bow.getRange() 
         << ", Power=" << bow.getPower() << endl;
    cout << "Created " << spear.getName() << ": Range=" << spear.getRange() 
         << ", Power=" << spear.getPower() << endl;
    cout << "Created " << sword.getName() << ": Range=" << sword.getRange() 
         << ", Power=" << sword.getPower() << endl;
    cout << endl;
    
    
    // ========== TEST 2: Weapon Stats (Game Balance) ==========
    cout << "TEST 2: Weapon Stats & Game Balance" << endl;
    cout << "------------------------------------" << endl;
    cout << "Notice the Range × Power tradeoff:" << endl;
    cout << "  Bow:   4 × 1 = 4 (long range, low damage)" << endl;
    cout << "  Spear: 2 × 2 = 4 (balanced)" << endl;
    cout << "  Sword: 1 × 4 = 4 (melee, high damage)" << endl;
    cout << endl;
    cout << "All weapons have the same 'threat budget' - balanced!" << endl;
    cout << "Players choose based on playstyle, not power." << endl;
    cout << endl;
    
    
    // ========== TEST 3: Basic Attack Tests ==========
    cout << "TEST 3: Basic Attack Tests" << endl;
    cout << "---------------------------" << endl;
    
    Character enemy1(10.0, 10.0, "Goblin", 10);
    cout << "Target: ";
    enemy1.draw();
    cout << endl;
    
    cout << "Testing Bow attack:" << endl;
    bow.attack(enemy1);
    enemy1.draw();
    cout << endl;
    
    Character enemy2(20.0, 20.0, "Orc", 10);
    cout << "Target: ";
    enemy2.draw();
    cout << endl;
    
    cout << "Testing Spear attack:" << endl;
    spear.attack(enemy2);
    enemy2.draw();
    cout << endl;
    
    Character enemy3(30.0, 30.0, "Troll", 10);
    cout << "Target: ";
    enemy3.draw();
    cout << endl;
    
    cout << "Testing Sword attack:" << endl;
    sword.attack(enemy3);
    enemy3.draw();
    cout << endl;
    
    
    // ========== TEST 4: Defeating Enemies ==========
    cout << "TEST 4: Defeating Enemies" << endl;
    cout << "--------------------------" << endl;
    
    Character weakEnemy(0.0, 0.0, "Slime", 4);
    cout << "Target: ";
    weakEnemy.draw();
    cout << endl;
    
    cout << "One sword strike (4 damage) should defeat it:" << endl;
    sword.attack(weakEnemy);
    weakEnemy.draw();
    cout << "Enemy defeated: " << (weakEnemy.isAlive() ? "No" : "Yes") << endl;
    cout << endl;
    
    cout << "Trying to attack already dead enemy:" << endl;
    sword.attack(weakEnemy);
    cout << endl;
    
    
    // ========== TEST 5: Comparison of Weapons ==========
    cout << "TEST 5: Weapon Efficiency Comparison" << endl;
    cout << "-------------------------------------" << endl;
    cout << "Three enemies, each with 12 HP" << endl;
    cout << endl;
    
    Character target1(0.0, 0.0, "Enemy A", 12);
    Character target2(0.0, 0.0, "Enemy B", 12);
    Character target3(0.0, 0.0, "Enemy C", 12);
    
    cout << "Bow vs Enemy A (1 damage per hit):" << endl;
    int bowHits = 0;
    while (target1.isAlive()) {
        bow.attack(target1);
        bowHits++;
    }
    cout << "Hits needed: " << bowHits << endl;
    cout << endl;
    
    cout << "Spear vs Enemy B (2 damage per hit):" << endl;
    int spearHits = 0;
    while (target2.isAlive()) {
        spear.attack(target2);
        spearHits++;
    }
    cout << "Hits needed: " << spearHits << endl;
    cout << endl;
    
    cout << "Sword vs Enemy C (4 damage per hit):" << endl;
    int swordHits = 0;
    while (target3.isAlive()) {
        sword.attack(target3);
        swordHits++;
    }
    cout << "Hits needed: " << swordHits << endl;
    cout << endl;
    
    cout << "Summary: Higher power = fewer hits needed to defeat" << endl;
    cout << "But remember: Sword has only range=1 (must be close!)" << endl;
    cout << endl;
    
    
    // ========== TEST 6: Polymorphism with Weapon Pointers ==========
    cout << "TEST 6: Polymorphism (Strategy Pattern)" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Array of Weapon pointers can hold any weapon type:" << endl;
    cout << endl;
    
    Weapon* weapons[3];
    weapons[0] = new Bow();
    weapons[1] = new Spear();
    weapons[2] = new Sword();
    
    cout << "Weapon arsenal:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "  [" << i << "] " << weapons[i]->getName() 
             << " (Range: " << weapons[i]->getRange() 
             << ", Power: " << weapons[i]->getPower() << ")" << endl;
    }
    cout << endl;
    
    Character boss(50.0, 50.0, "Dragon", 20);
    cout << "Attacking boss with all weapons polymorphically:" << endl;
    boss.draw();
    cout << endl;
    
    for (int i = 0; i < 3; i++) {
        cout << "Using " << weapons[i]->getName() << ": ";
        weapons[i]->attack(boss);
    }
    cout << endl;
    
    boss.draw();
    cout << endl;
    
    
    // ========== TEST 7: Weapon Switching (Strategy Pattern) ==========
    cout << "TEST 7: Weapon Switching (Strategy Pattern)" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "A character can switch weapons dynamically!" << endl;
    cout << endl;
    
    Character hero(0.0, 0.0, "Hero", 100);
    Character monster(10.0, 10.0, "Monster", 15);
    
    cout << "Hero: ";
    hero.draw();
    cout << "Monster: ";
    monster.draw();
    cout << endl;
    
    cout << "Hero equips Bow (long-range strategy):" << endl;
    Weapon* currentWeapon = new Bow();
    cout << "  Equipped: " << currentWeapon->getName() << endl;
    currentWeapon->attack(monster);
    cout << endl;
    
    cout << "Monster gets closer! Hero switches to Spear:" << endl;
    delete currentWeapon;
    currentWeapon = new Spear();
    cout << "  Equipped: " << currentWeapon->getName() << endl;
    currentWeapon->attack(monster);
    cout << endl;
    
    cout << "Monster very close! Hero switches to Sword (high damage):" << endl;
    delete currentWeapon;
    currentWeapon = new Sword();
    cout << "  Equipped: " << currentWeapon->getName() << endl;
    currentWeapon->attack(monster);
    cout << endl;
    
    monster.draw();
    delete currentWeapon;
    cout << endl;
    
    
    // ========== TEST 8: Interface Verification ==========
    cout << "TEST 8: Interface Verification" << endl;
    cout << "-------------------------------" << endl;
    cout << "Weapon is an abstract class - cannot be instantiated:" << endl;
    cout << "Uncommenting this would cause COMPILATION ERROR:" << endl;
    cout << "  // Weapon weapon(3, 3);  // ERROR: cannot instantiate abstract class" << endl;
    cout << endl;
    cout << "But we CAN use Weapon pointers for polymorphism:" << endl;
    Weapon* genericWeapon = new Sword();
    cout << "  Weapon* genericWeapon = new Sword();  // ✓ Valid!" << endl;
    cout << "  genericWeapon->getName() = " << genericWeapon->getName() << endl;
    cout << "  Polymorphism works!" << endl;
    delete genericWeapon;
    cout << endl;
    
    
    // ========== Cleanup ==========
    cout << "Cleaning up polymorphic weapon array..." << endl;
    for (int i = 0; i < 3; i++) {
        delete weapons[i];
    }
    cout << "All weapons deleted (virtual destructor ensures proper cleanup)" << endl;
    cout << endl;
    
    
    // ========== Summary ==========
    cout << "========================================" << endl;
    cout << "   All tests completed successfully!    " << endl;
    cout << "========================================" << endl;
    cout << endl;
    
    cout << "Class Hierarchy:" << endl;
    cout << "  Weapon (interface/abstract)" << endl;
    cout << "      ├─ Bow    (Range=4, Power=1)" << endl;
    cout << "      ├─ Spear  (Range=2, Power=2)" << endl;
    cout << "      └─ Sword  (Range=1, Power=4)" << endl;
    cout << endl;
    
    cout << "Design Patterns Used:" << endl;
    cout << "  ✓ Interface Pattern (Weapon defines contract)" << endl;
    cout << "  ✓ Strategy Pattern (different attack strategies)" << endl;
    cout << "  ✓ Polymorphism (Weapon* can point to any weapon)" << endl;
    cout << endl;
    
    cout << "Key Features Demonstrated:" << endl;
    cout << "  ✓ Abstract class/interface (Weapon cannot be instantiated)" << endl;
    cout << "  ✓ Pure virtual methods (getName, attack)" << endl;
    cout << "  ✓ Virtual destructor (proper polymorphic cleanup)" << endl;
    cout << "  ✓ Attack integration with Character class" << endl;
    cout << "  ✓ Game balance (range/power tradeoff)" << endl;
    cout << "  ✓ Weapon switching at runtime" << endl;
    cout << "  ✓ Death detection (can't attack dead enemies)" << endl;
    
    return 0;
}

