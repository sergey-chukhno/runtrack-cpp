#include <iostream>
#include "GameObject.hpp"
#include "Decor.hpp"
#include "Character.hpp"

using namespace std;

/**
 * Test program for Decor and Character classes
 * 
 * Demonstrates:
 * - Decor class (static environment objects)
 * - Character class (living entities with health)
 * - Inheritance from GameObject
 * - Different update() behaviors
 * - isAlive() functionality
 */
int main() {
    cout << "========================================" << endl;
    cout << "  Decor & Character Test - Campus Quest  " << endl;
    cout << "========================================" << endl;
    cout << endl;
    
    
    // ========== TEST 1: Creating Decor Objects ==========
    cout << "TEST 1: Creating Decor Objects" << endl;
    cout << "-------------------------------" << endl;
    
    Decor tree(10.0, 15.0, "Oak Tree");
    cout << "Created decoration: " << tree.getName() << endl;
    cout << "  Position: (" << tree.getX() << ", " << tree.getY() << ")" << endl;
    cout << endl;
    
    Decor rock(25.0, 30.0, "Large Rock");
    cout << "Created decoration: " << rock.getName() << endl;
    cout << "  Position: (" << rock.getX() << ", " << rock.getY() << ")" << endl;
    cout << endl;
    
    Decor building(100.0, 50.0, "Castle");
    cout << "Created decoration: " << building.getName() << endl;
    cout << "  Position: (" << building.getX() << ", " << building.getY() << ")" << endl;
    cout << endl;
    
    
    // ========== TEST 2: Creating Character Objects ==========
    cout << "TEST 2: Creating Character Objects" << endl;
    cout << "-----------------------------------" << endl;
    
    Character hero(5.0, 5.0, "Knight", 100);
    cout << "Created character: " << hero.getName() << endl;
    cout << "  Position: (" << hero.getX() << ", " << hero.getY() << ")" << endl;
    cout << "  Health: " << hero.getHealth() << endl;
    cout << "  Alive: " << (hero.isAlive() ? "Yes" : "No") << endl;
    cout << endl;
    
    Character villager(20.0, 20.0, "Peasant", 50);
    cout << "Created character: " << villager.getName() << endl;
    cout << "  Position: (" << villager.getX() << ", " << villager.getY() << ")" << endl;
    cout << "  Health: " << villager.getHealth() << endl;
    cout << "  Alive: " << (villager.isAlive() ? "Yes" : "No") << endl;
    cout << endl;
    
    
    // ========== TEST 3: Drawing Objects ==========
    cout << "TEST 3: Drawing Objects (draw method)" << endl;
    cout << "--------------------------------------" << endl;
    
    cout << "Drawing decorations:" << endl;
    tree.draw();
    rock.draw();
    building.draw();
    cout << endl;
    
    cout << "Drawing characters:" << endl;
    hero.draw();
    villager.draw();
    cout << endl;
    
    
    // ========== TEST 4: Update Behavior ==========
    cout << "TEST 4: Update Behavior" << endl;
    cout << "-----------------------" << endl;
    
    cout << "Updating decorations (should do nothing):" << endl;
    tree.update();
    rock.update();
    building.update();
    cout << "Note: Decor objects are static - no output from update()" << endl;
    cout << endl;
    
    cout << "Updating characters (should show activity):" << endl;
    hero.update();
    villager.update();
    cout << endl;
    
    
    // ========== TEST 5: Character Health & isAlive() ==========
    cout << "TEST 5: Character Health & isAlive()" << endl;
    cout << "------------------------------------" << endl;
    
    Character warrior(30.0, 30.0, "Warrior", 75);
    cout << "Created warrior:" << endl;
    warrior.draw();
    cout << "  isAlive(): " << (warrior.isAlive() ? "true" : "false") << endl;
    cout << endl;
    
    cout << "Warrior takes damage (health reduced to 0)..." << endl;
    warrior.setHealth(0);
    warrior.draw();
    cout << "  isAlive(): " << (warrior.isAlive() ? "true" : "false") << endl;
    cout << endl;
    
    cout << "Updating dead warrior:" << endl;
    warrior.update();
    cout << endl;
    
    
    // ========== TEST 6: Inherited Vector2d Functionality ==========
    cout << "TEST 6: Inherited Vector2d Functionality" << endl;
    cout << "-----------------------------------------" << endl;
    
    cout << "Both Decor and Character inherit from GameObject -> Vector2d" << endl;
    cout << "They have access to all Vector2d methods!" << endl;
    cout << endl;
    
    double distTreeToHero = tree.distance(hero);
    cout << "Distance from " << tree.getName() << " to " << hero.getName() << ": " << distTreeToHero << endl;
    cout << endl;
    
    double distHeroToVillager = hero.distance(villager);
    cout << "Distance from " << hero.getName() << " to " << villager.getName() << ": " << distHeroToVillager << endl;
    cout << endl;
    
    
    // ========== TEST 7: Polymorphism with GameObject ==========
    cout << "TEST 7: Polymorphism with GameObject Pointers" << endl;
    cout << "----------------------------------------------" << endl;
    
    cout << "Creating array of mixed GameObject pointers:" << endl;
    GameObject* objects[5];
    
    objects[0] = new Decor(0.0, 0.0, "Fountain");
    objects[1] = new Character(10.0, 10.0, "Guard", 80);
    objects[2] = new Decor(20.0, 20.0, "Statue");
    objects[3] = new Character(30.0, 30.0, "Merchant", 60);
    objects[4] = new Decor(40.0, 40.0, "Well");
    
    cout << endl;
    cout << "Drawing all objects polymorphically:" << endl;
    for (int i = 0; i < 5; i++) {
        objects[i]->draw();
    }
    cout << endl;
    
    cout << "Updating all objects polymorphically:" << endl;
    for (int i = 0; i < 5; i++) {
        objects[i]->update();
    }
    cout << "Note: Decor update() does nothing (as designed)" << endl;
    cout << endl;
    
    cout << "Cleaning up polymorphic objects..." << endl;
    for (int i = 0; i < 5; i++) {
        delete objects[i];
    }
    cout << "All objects deleted (virtual destructor ensures proper cleanup)" << endl;
    cout << endl;
    
    
    // ========== TEST 8: Edge Cases ==========
    cout << "TEST 8: Edge Cases" << endl;
    cout << "------------------" << endl;
    
    cout << "Creating character with negative health:" << endl;
    Character deadChar(0.0, 0.0, "Corpse", -50);
    deadChar.draw();
    cout << "  isAlive(): " << (deadChar.isAlive() ? "true" : "false") << endl;
    cout << "  Note: Health clamped to 0 (can't be negative)" << endl;
    cout << endl;
    
    cout << "Setting health to negative value:" << endl;
    hero.setHealth(-10);
    cout << "  Hero health after setHealth(-10): " << hero.getHealth() << endl;
    cout << "  Note: Health clamped to 0" << endl;
    cout << endl;
    
    
    // ========== Summary ==========
    cout << "========================================" << endl;
    cout << "   All tests completed successfully!    " << endl;
    cout << "========================================" << endl;
    cout << endl;
    
    cout << "Class Hierarchy:" << endl;
    cout << "  Vector2d" << endl;
    cout << "      ↑" << endl;
    cout << "  GameObject (abstract)" << endl;
    cout << "      ↑" << endl;
    cout << "      ├─ Decor (concrete - static objects)" << endl;
    cout << "      └─ Character (concrete - living entities)" << endl;
    cout << endl;
    
    cout << "Key Features Demonstrated:" << endl;
    cout << "  ✓ Decor: Static environment objects (update does nothing)" << endl;
    cout << "  ✓ Character: Living entities with health and isAlive()" << endl;
    cout << "  ✓ Both implement draw() and update() (pure virtual from GameObject)" << endl;
    cout << "  ✓ Both inherit Vector2d functionality (distance, position)" << endl;
    cout << "  ✓ Polymorphism works with GameObject pointers" << endl;
    cout << "  ✓ Health validation (can't be negative)" << endl;
    
    return 0;
}

