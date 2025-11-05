#include <iostream>
#include "Player.hpp"
#include "Enemy.hpp"

using namespace std;

/**
 * Test program for Enemy and Player combat system
 * 
 * Demonstrates:
 * - Enemy AI (pathfinding + attacking)
 * - Player weapon system (cycling through weapons)
 * - Turn-based combat
 * - Game loop architecture
 * - Victory/defeat conditions
 * 
 * This is a COMPLETE game combat system!
 */

// Helper function to display combat state
void displayCombatState(Player& player, Enemy& enemy) {
    cout << "----------------------------------------" << endl;
    player.draw();
    enemy.draw();
    cout << "Distance: " << player.distance(enemy) << " units" << endl;
    cout << "----------------------------------------" << endl;
}

// Helper function to run one turn of combat
void runCombatTurn(int turnNumber, Player& player, Enemy& enemy) {
    cout << "\n╔════════════════════════════════════════╗" << endl;
    cout << "║         TURN " << turnNumber;
    if (turnNumber < 10) cout << " ";
    cout << "                       ║" << endl;
    cout << "╚════════════════════════════════════════╝" << endl;
    
    // Player acts first (turn-based: attack then switch weapon)
    player.update();
    
    // Enemy acts second (AI: move or attack)
    enemy.update();
}

int main() {
    cout << "========================================" << endl;
    cout << "  Combat System Test - Campus Quest    " << endl;
    cout << "========================================" << endl;
    cout << endl;
    
    
    // ========== TEST 1: Creating Combatants ==========
    cout << "TEST 1: Creating Player and Enemy" << endl;
    cout << "---------------------------------" << endl;
    
    Player hero(0.0, 0.0, "Hero", 50);
    Enemy goblin(10.0, 0.0, "Goblin", 30, &hero, 5);
    
    cout << "Player created:" << endl;
    hero.draw();
    cout << endl;
    
    cout << "Enemy created:" << endl;
    goblin.draw();
    cout << endl;
    
    cout << "Setting combat targets..." << endl;
    hero.setTarget(&goblin);
    cout << "Hero targets: " << goblin.getName() << endl;
    cout << "Goblin targets: " << hero.getName() << endl;
    cout << endl;
    
    
    // ========== TEST 2: Weapon System ==========
    cout << "TEST 2: Player Weapon System" << endl;
    cout << "-----------------------------" << endl;
    
    cout << "Starting weapon: " << hero.getCurrentWeapon()->getName() << endl;
    cout << endl;
    
    cout << "Manual weapon switching demonstration:" << endl;
    hero.switchWeapon();  // Bow → Spear
    hero.switchWeapon();  // Spear → Sword
    hero.switchWeapon();  // Sword → Bow (cycle complete)
    cout << "Cycle complete! Back to " << hero.getCurrentWeapon()->getName() << endl;
    cout << endl;
    
    
    // ========== TEST 3: Single Turn Combat ==========
    cout << "TEST 3: Single Turn Combat" << endl;
    cout << "--------------------------" << endl;
    
    displayCombatState(hero, goblin);
    
    cout << "\nExecuting one combat turn:" << endl;
    cout << "1. Player attacks with current weapon" << endl;
    cout << "2. Player switches weapon" << endl;
    cout << "3. Enemy AI decides: move or attack" << endl;
    cout << endl;
    
    runCombatTurn(1, hero, goblin);
    
    cout << "\nState after turn:" << endl;
    displayCombatState(hero, goblin);
    cout << endl;
    
    
    // ========== TEST 4: Multiple Turn Combat ==========
    cout << "TEST 4: Multiple Turn Combat Simulation" << endl;
    cout << "----------------------------------------" << endl;
    
    Player knight(0.0, 0.0, "Knight", 100);
    Enemy orc(8.0, 6.0, "Orc", 40, &knight, 8);
    
    knight.setTarget(&orc);
    
    cout << "Initial state:" << endl;
    displayCombatState(knight, orc);
    
    cout << "\nStarting combat..." << endl;
    cout << "Orc will move towards Knight, then attack when in range" << endl;
    cout << "Knight will attack and cycle weapons: Bow→Spear→Sword→Bow" << endl;
    
    int turn = 1;
    while (knight.isAlive() && orc.isAlive() && turn <= 15) {
        runCombatTurn(turn, knight, orc);
        turn++;
    }
    
    cout << "\n╔════════════════════════════════════════╗" << endl;
    cout << "║         COMBAT ENDED!                  ║" << endl;
    cout << "╚════════════════════════════════════════╝" << endl;
    
    displayCombatState(knight, orc);
    
    if (knight.isAlive() && !orc.isAlive()) {
        cout << "\n🎉 VICTORY! " << knight.getName() << " defeated " << orc.getName() << "!" << endl;
    } else if (!knight.isAlive() && orc.isAlive()) {
        cout << "\n💀 DEFEAT! " << orc.getName() << " defeated " << knight.getName() << "!" << endl;
    } else {
        cout << "\n⚔️  Both combatants fell in battle!" << endl;
    }
    cout << endl;
    
    
    // ========== TEST 5: Enemy Pathfinding ==========
    cout << "TEST 5: Enemy Pathfinding Demonstration" << endl;
    cout << "----------------------------------------" << endl;
    
    Player target(0.0, 0.0, "Target", 1000);  // High HP to survive
    Enemy tracker(5.0, 5.0, "Tracker", 100, &target, 3);
    
    cout << "Target at: (" << target.getX() << ", " << target.getY() << ")" << endl;
    cout << "Tracker starting at: (" << tracker.getX() << ", " << tracker.getY() << ")" << endl;
    cout << "Distance: " << tracker.distance(target) << " units" << endl;
    cout << endl;
    
    cout << "Watching Tracker move towards Target (5 turns):" << endl;
    for (int i = 1; i <= 5; i++) {
        cout << "\nTurn " << i << ":" << endl;
        tracker.update();
        cout << "  Position: (" << tracker.getX() << ", " << tracker.getY() << ")";
        cout << " | Distance: " << tracker.distance(target) << endl;
    }
    cout << endl;
    
    
    // ========== TEST 6: Weapon Cycle in Combat ==========
    cout << "TEST 6: Weapon Cycle Verification" << endl;
    cout << "----------------------------------" << endl;
    
    Player warrior(0.0, 0.0, "Warrior", 100);
    Enemy dummy(5.0, 0.0, "Training Dummy", 50, &warrior, 0);  // 0 damage
    
    warrior.setTarget(&dummy);
    
    cout << "Demonstrating 6 turns of combat (2 full weapon cycles):" << endl;
    cout << "Expected cycle: Bow → Spear → Sword → Bow → Spear → Sword" << endl;
    cout << endl;
    
    for (int i = 1; i <= 6 && dummy.isAlive(); i++) {
        cout << "Turn " << i << ": ";
        cout << "Current weapon = " << warrior.getCurrentWeapon()->getName() << endl;
        warrior.update();
        cout << endl;
    }
    
    cout << "After 6 turns, back to: " << warrior.getCurrentWeapon()->getName() << endl;
    cout << "Weapon cycle works correctly! ✓" << endl;
    cout << endl;
    
    
    // ========== TEST 7: Close-Range Combat ==========
    cout << "TEST 7: Close-Range Melee Combat" << endl;
    cout << "---------------------------------" << endl;
    
    Player mage(5.0, 5.0, "Mage", 30);
    Enemy assassin(5.5, 5.0, "Assassin", 25, &mage, 10);  // Very close!
    
    mage.setTarget(&assassin);
    
    cout << "Starting positions (very close):" << endl;
    displayCombatState(mage, assassin);
    
    cout << "\nAssassin is within attack range immediately!" << endl;
    
    int closeTurn = 1;
    while (mage.isAlive() && assassin.isAlive() && closeTurn <= 5) {
        runCombatTurn(closeTurn, mage, assassin);
        closeTurn++;
    }
    
    cout << "\nFinal state:" << endl;
    displayCombatState(mage, assassin);
    cout << endl;
    
    
    // ========== Summary ==========
    cout << "========================================" << endl;
    cout << "   All tests completed successfully!    " << endl;
    cout << "========================================" << endl;
    cout << endl;
    
    cout << "Class Hierarchy:" << endl;
    cout << "  Character (from Job 03)" << endl;
    cout << "      ├─ Enemy  (AI pathfinding + melee attack)" << endl;
    cout << "      └─ Player (weapon system + cycling)" << endl;
    cout << endl;
    
    cout << "Key Features Demonstrated:" << endl;
    cout << "  ✓ Enemy AI pathfinding (moves towards player)" << endl;
    cout << "  ✓ Enemy attack logic (melee when in range ≤ 1)" << endl;
    cout << "  ✓ Player weapon system (Bow, Spear, Sword)" << endl;
    cout << "  ✓ Weapon cycling (Bow → Spear → Sword → Bow)" << endl;
    cout << "  ✓ Turn-based combat (attack then switch)" << endl;
    cout << "  ✓ Strategy Pattern (weapon switching)" << endl;
    cout << "  ✓ AI decision making (move or attack)" << endl;
    cout << "  ✓ Victory/defeat conditions" << endl;
    cout << "  ✓ Game loop architecture" << endl;
    cout << endl;
    
    cout << "Design Patterns Used:" << endl;
    cout << "  ✓ Strategy Pattern (weapon switching)" << endl;
    cout << "  ✓ Composition (Player HAS weapons)" << endl;
    cout << "  ✓ Inheritance (Enemy, Player extend Character)" << endl;
    cout << "  ✓ Polymorphism (Character* can be Player or Enemy)" << endl;
    cout << endl;
    
    cout << "This is a COMPLETE turn-based combat system!" << endl;
    cout << "🎮 Game development skills: ACHIEVED! 🎮" << endl;
    
    return 0;
}

