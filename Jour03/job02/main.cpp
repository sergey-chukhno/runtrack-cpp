#include <iostream>
#include "GameObject.hpp"
#include "Player.hpp"
#include "Enemy.hpp"

using namespace std;

/**
 * Test program for GameObject inheritance hierarchy
 * 
 * Demonstrates:
 * - Abstract class (GameObject)
 * - Inheritance (Player, Enemy inherit from GameObject)
 * - Polymorphism (GameObject pointers to different types)
 * - Virtual methods (draw, update)
 * - Virtual destructor
 */
int main() {
    cout << "========================================" << endl;
    cout << "  GameObject Inheritance Test - Campus Quest  " << endl;
    cout << "========================================" << endl;
    cout << endl;
    
    
    // ========== TEST 1: Abstract Class Verification ==========
    cout << "TEST 1: Abstract Class Verification" << endl;
    cout << "------------------------------------" << endl;
    cout << "GameObject is abstract - cannot be instantiated directly." << endl;
    cout << "Uncommenting this line would cause COMPILATION ERROR:" << endl;
    cout << "  // GameObject obj;  // ERROR: cannot instantiate abstract class" << endl;
    cout << endl;
    
    
    // ========== TEST 2: Creating Concrete Objects ==========
    cout << "TEST 2: Creating Concrete Objects" << endl;
    cout << "----------------------------------" << endl;
    
    Player player1(10.0, 20.0, "Hero", 100);
    cout << "Created Player: " << player1.getName() << endl;
    cout << "  Position: (" << player1.getX() << ", " << player1.getY() << ")" << endl;
    cout << "  Health: " << player1.getHealth() << endl;
    cout << endl;
    
    Enemy enemy1(50.0, 60.0, "Goblin", 15);
    cout << "Created Enemy: " << enemy1.getName() << endl;
    cout << "  Position: (" << enemy1.getX() << ", " << enemy1.getY() << ")" << endl;
    cout << "  Damage: " << enemy1.getDamage() << endl;
    cout << endl;
    
    
    // ========== TEST 3: Inherited Vector2d Functionality ==========
    cout << "TEST 3: Inherited Vector2d Functionality" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "GameObject inherits all Vector2d methods!" << endl;
    cout << endl;
    
    // Test distance calculation (inherited from Vector2d)
    double dist = player1.distance(enemy1);
    cout << "Distance from " << player1.getName() << " to " << enemy1.getName() << ": " << dist << endl;
    cout << endl;
    
    // Test vector operations (inherited from Vector2d)
    cout << "Moving player towards enemy..." << endl;
    Vector2d movement(5.0, 5.0);
    // Note: We need to use setters because operator+ returns Vector2d, not Player
    Vector2d newPos = Vector2d(player1.getX(), player1.getY()) + movement;
    player1.setX(newPos.getX());
    player1.setY(newPos.getY());
    cout << "Player new position: (" << player1.getX() << ", " << player1.getY() << ")" << endl;
    cout << "New distance: " << player1.distance(enemy1) << endl;
    cout << endl;
    
    
    // ========== TEST 4: Virtual Methods (draw and update) ==========
    cout << "TEST 4: Virtual Methods - draw() and update()" << endl;
    cout << "----------------------------------------------" << endl;
    
    cout << "Drawing objects:" << endl;
    player1.draw();
    enemy1.draw();
    cout << endl;
    
    cout << "Updating objects:" << endl;
    player1.update();
    enemy1.update();
    cout << endl;
    
    
    // ========== TEST 5: Polymorphism ==========
    cout << "TEST 5: Polymorphism (GameObject pointers)" << endl;
    cout << "------------------------------------------" << endl;
    cout << "Creating array of GameObject pointers pointing to different types:" << endl;
    cout << endl;
    
    // Array of GameObject pointers
    // Can point to ANY class that inherits from GameObject!
    GameObject* objects[4];
    
    objects[0] = new Player(0.0, 0.0, "Alice", 80);
    objects[1] = new Enemy(10.0, 10.0, "Orc", 20);
    objects[2] = new Player(5.0, 5.0, "Bob", 90);
    objects[3] = new Enemy(15.0, 15.0, "Troll", 25);
    
    cout << "Drawing all objects polymorphically:" << endl;
    for (int i = 0; i < 4; i++) {
        objects[i]->draw();  // Calls correct draw() based on actual type!
    }
    cout << endl;
    
    cout << "Updating all objects polymorphically:" << endl;
    for (int i = 0; i < 4; i++) {
        objects[i]->update();  // Calls correct update() based on actual type!
    }
    cout << endl;
    
    
    // ========== TEST 6: Demonstrating Player Actions ==========
    cout << "TEST 6: Player-Specific Features" << endl;
    cout << "---------------------------------" << endl;
    
    Player hero(0.0, 0.0, "Warrior", 100);
    cout << "Hero created:" << endl;
    hero.draw();
    cout << endl;
    
    cout << "Hero takes 30 damage..." << endl;
    hero.takeDamage(30);
    hero.draw();
    cout << endl;
    
    cout << "Hero heals 20 points..." << endl;
    hero.heal(20);
    hero.draw();
    cout << endl;
    
    
    // ========== TEST 7: Demonstrating Enemy Actions ==========
    cout << "TEST 7: Enemy-Specific Features" << endl;
    cout << "--------------------------------" << endl;
    
    Enemy monster(100.0, 100.0, "Dragon", 50);
    cout << "Monster created:" << endl;
    monster.draw();
    monster.update();
    cout << endl;
    
    cout << "Monster is defeated..." << endl;
    monster.defeat();
    monster.draw();
    monster.update();
    cout << endl;
    
    
    // ========== TEST 8: Virtual Destructor ==========
    cout << "TEST 8: Virtual Destructor (cleanup)" << endl;
    cout << "-------------------------------------" << endl;
    cout << "Deleting polymorphic objects..." << endl;
    cout << "Thanks to virtual destructor, proper cleanup happens!" << endl;
    
    for (int i = 0; i < 4; i++) {
        delete objects[i];  // Calls correct destructor chain!
    }
    cout << "All objects deleted successfully." << endl;
    cout << endl;
    
    
    // ========== Summary ==========
    cout << "========================================" << endl;
    cout << "   All tests completed successfully!    " << endl;
    cout << "========================================" << endl;
    cout << endl;
    
    cout << "Key Concepts Demonstrated:" << endl;
    cout << "  ✓ Abstract class (GameObject cannot be instantiated)" << endl;
    cout << "  ✓ Inheritance (Player, Enemy inherit from GameObject)" << endl;
    cout << "  ✓ Pure virtual methods (draw, update must be implemented)" << endl;
    cout << "  ✓ Virtual destructor (proper cleanup in inheritance)" << endl;
    cout << "  ✓ Polymorphism (GameObject* can point to any child)" << endl;
    cout << "  ✓ Inherited functionality (Vector2d methods work!)" << endl;
    
    return 0;
}

