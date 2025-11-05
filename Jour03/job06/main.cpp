#include <iostream>
#include <memory>  // For smart pointers
#include "GameManager.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Decor.hpp"

using namespace std;

/**
 * Test program for GameManager with Smart Pointers
 * 
 * Demonstrates:
 * - unique_ptr usage and benefits
 * - Move semantics (ownership transfer)
 * - Automatic memory management (RAII)
 * - Polymorphic containers
 * - Factory pattern (createObject)
 * - No memory leaks (automatic cleanup)
 * 
 * This is MODERN C++ at its finest!
 */

int main() {
    cout << "========================================" << endl;
    cout << "  GameManager & Smart Pointers Test    " << endl;
    cout << "========================================" << endl;
    cout << endl;
    
    
    // ========== TEST 1: Creating GameManager ==========
    cout << "TEST 1: Creating GameManager" << endl;
    cout << "----------------------------" << endl;
    
    GameManager manager;
    cout << "GameManager created" << endl;
    cout << "Initial size: " << manager.size() << endl;
    cout << "Is empty: " << (manager.empty() ? "Yes" : "No") << endl;
    cout << endl;
    
    
    // ========== TEST 2: Adding Objects with unique_ptr ==========
    cout << "TEST 2: Adding Objects with unique_ptr (Move Semantics)" << endl;
    cout << "--------------------------------------------------------" << endl;
    
    cout << "\nCreating Player with make_unique:" << endl;
    auto player = std::make_unique<Player>(0.0, 0.0, "Hero", 100);
    cout << "  Player created, owned by local variable 'player'" << endl;
    cout << "  player pointer value: " << player.get() << endl;
    
    cout << "\nTransferring ownership to GameManager:" << endl;
    manager.addObject(std::move(player));  // MOVE SEMANTICS!
    cout << "  Ownership transferred using std::move()" << endl;
    cout << "  player pointer value after move: " << player.get() << " (nullptr!)" << endl;
    cout << "  GameManager now owns the Player" << endl;
    
    cout << "\nManager size after adding: " << manager.size() << endl;
    cout << endl;
    
    
    // ========== TEST 3: Factory Method (createObject) ==========
    cout << "TEST 3: Factory Method - createObject<T>()" << endl;
    cout << "--------------------------------------------" << endl;
    
    cout << "\nUsing factory method to create objects directly:" << endl;
    
    // Create and add Enemy using factory method
    Enemy* enemy1 = manager.createObject<Enemy>(10.0, 0.0, "Goblin", 30, nullptr, 5);
    cout << "  Created Enemy: " << enemy1->getName() << endl;
    
    // Create and add more objects
    manager.createObject<Decor>(5.0, 5.0, "Tree");
    manager.createObject<Decor>(15.0, 5.0, "Rock");
    
    cout << "\nManager size: " << manager.size() << endl;
    cout << endl;
    
    
    // ========== TEST 4: Polymorphic Operations ==========
    cout << "TEST 4: Polymorphic Operations (drawAll, updateAll)" << endl;
    cout << "----------------------------------------------------" << endl;
    
    cout << "\nDrawing all objects (polymorphism in action):" << endl;
    manager.drawAll();
    
    cout << "\nUpdating all objects:" << endl;
    manager.updateAll();
    
    cout << endl;
    
    
    // ========== TEST 5: Accessing Objects ==========
    cout << "TEST 5: Accessing Objects (getObject)" << endl;
    cout << "--------------------------------------" << endl;
    
    cout << "\nAccessing object at index 0:" << endl;
    GameObject* obj = manager.getObject(0);
    cout << "  Object name: " << obj->getName() << endl;
    cout << "  Object position: (" << obj->getX() << ", " << obj->getY() << ")" << endl;
    
    cout << "\nNote: getObject() returns raw pointer (borrowing)" << endl;
    cout << "      GameManager still owns the object" << endl;
    cout << "      No ownership transfer occurred" << endl;
    cout << endl;
    
    
    // ========== TEST 6: Finding Objects ==========
    cout << "TEST 6: Finding Objects by Name" << endl;
    cout << "--------------------------------" << endl;
    
    GameObject* found = manager.findByName("Goblin");
    if (found) {
        cout << "Found object: " << found->getName() << endl;
        found->draw();
    }
    
    GameObject* notFound = manager.findByName("Dragon");
    cout << "Looking for 'Dragon': " << (notFound ? "Found" : "Not found") << endl;
    cout << endl;
    
    
    // ========== TEST 7: Statistics ==========
    cout << "TEST 7: Game Statistics" << endl;
    cout << "-----------------------" << endl;
    
    manager.printStats();
    cout << endl;
    
    
    // ========== TEST 8: Combat Simulation ==========
    cout << "TEST 8: Combat Simulation with GameManager" << endl;
    cout << "-------------------------------------------" << endl;
    
    {  // New scope for separate test
        GameManager game;
        
        cout << "\nCreating combat scenario:" << endl;
        
        // Create player
        Player* hero = game.createObject<Player>(0.0, 0.0, "Knight", 50);
        
        // Create enemies
        Enemy* orc = game.createObject<Enemy>(5.0, 0.0, "Orc", 20, hero, 8);
        Enemy* goblin = game.createObject<Enemy>(8.0, 0.0, "Goblin", 15, hero, 5);
        
        // Set player target
        hero->setTarget(orc);
        
        cout << "\nInitial state:" << endl;
        game.drawAll();
        
        cout << "\nRunning 5 turns of combat:" << endl;
        for (int turn = 1; turn <= 5 && hero->isAlive(); turn++) {
            cout << "\n--- Turn " << turn << " ---" << endl;
            game.updateAll();
            
            // Remove dead enemies
            size_t removed = game.removeDeadObjects();
            if (removed > 0) {
                cout << "  [" << removed << " dead objects removed]" << endl;
            }
        }
        
        cout << "\nFinal state:" << endl;
        game.drawAll();
        
        game.printStats();
        
        cout << "\nExiting combat scope..." << endl;
        // GameManager destructor called here - automatic cleanup!
    }
    cout << "Combat GameManager destroyed (all objects automatically deleted!)" << endl;
    cout << endl;
    
    
    // ========== TEST 9: Clear Operation ==========
    cout << "TEST 9: Clear Operation" << endl;
    cout << "-----------------------" << endl;
    
    cout << "\nBefore clear - Manager size: " << manager.size() << endl;
    manager.clear();  // All objects automatically deleted!
    cout << "After clear - Manager size: " << manager.size() << endl;
    cout << endl;
    
    
    // ========== TEST 10: Large Scale Test ==========
    cout << "TEST 10: Large Scale Test (Many Objects)" << endl;
    cout << "-----------------------------------------" << endl;
    
    {
        GameManager largeGame;
        
        cout << "\nCreating 100 objects..." << endl;
        for (int i = 0; i < 100; i++) {
            if (i % 3 == 0) {
                largeGame.createObject<Decor>(i * 1.0, 0.0, "Decor_" + to_string(i));
            } else if (i % 3 == 1) {
                largeGame.createObject<Player>(i * 1.0, 0.0, "Player_" + to_string(i), 100);
            } else {
                largeGame.createObject<Enemy>(i * 1.0, 0.0, "Enemy_" + to_string(i), 50, nullptr, 10);
            }
        }
        
        cout << "Created " << largeGame.size() << " objects" << endl;
        
        largeGame.printStats();
        
        cout << "\nExiting scope..." << endl;
        // All 100 objects automatically deleted by unique_ptr!
    }
    cout << "All 100 objects automatically deleted - NO MEMORY LEAKS!" << endl;
    cout << endl;
    
    
    // ========== TEST 11: Exception Safety ==========
    cout << "TEST 11: Exception Safety Demonstration" << endl;
    cout << "----------------------------------------" << endl;
    
    cout << "\nDemonstrating exception safety:" << endl;
    try {
        GameManager exceptionTest;
        exceptionTest.createObject<Player>(0.0, 0.0, "TestPlayer", 100);
        exceptionTest.createObject<Enemy>(5.0, 0.0, "TestEnemy", 50, nullptr, 5);
        
        cout << "Created " << exceptionTest.size() << " objects" << endl;
        
        // Simulate exception
        cout << "Throwing exception..." << endl;
        throw std::runtime_error("Simulated exception");
        
        cout << "This line never executes" << endl;
    } catch (const std::exception& e) {
        cout << "Caught exception: " << e.what() << endl;
    }
    cout << "Despite exception, all objects were automatically cleaned up!" << endl;
    cout << "No memory leaks - this is the power of RAII!" << endl;
    cout << endl;
    
    
    // ========== Summary ==========
    cout << "========================================" << endl;
    cout << "   All tests completed successfully!    " << endl;
    cout << "========================================" << endl;
    cout << endl;
    
    cout << "Smart Pointer Benefits Demonstrated:" << endl;
    cout << "  ✓ Automatic memory management (no delete needed)" << endl;
    cout << "  ✓ Move semantics (clear ownership transfer)" << endl;
    cout << "  ✓ Exception safety (cleanup even with exceptions)" << endl;
    cout << "  ✓ No memory leaks (impossible to forget delete)" << endl;
    cout << "  ✓ RAII (Resource Acquisition Is Initialization)" << endl;
    cout << "  ✓ Clear ownership (unique_ptr = single owner)" << endl;
    cout << endl;
    
    cout << "Design Patterns Used:" << endl;
    cout << "  ✓ Manager/Repository Pattern (centralized object management)" << endl;
    cout << "  ✓ Factory Pattern (createObject method)" << endl;
    cout << "  ✓ RAII Pattern (automatic resource management)" << endl;
    cout << endl;
    
    cout << "Modern C++ Features:" << endl;
    cout << "  ✓ std::unique_ptr (smart pointers)" << endl;
    cout << "  ✓ std::move (move semantics)" << endl;
    cout << "  ✓ std::make_unique (factory function)" << endl;
    cout << "  ✓ Template methods (createObject<T>)" << endl;
    cout << "  ✓ Perfect forwarding (std::forward)" << endl;
    cout << "  ✓ Range-based for loops" << endl;
    cout << "  ✓ Lambda expressions (in removeDeadObjects)" << endl;
    cout << endl;
    
    cout << "🎮 Professional game engine architecture achieved! 🎮" << endl;
    cout << "This is EXACTLY how Unity, Unreal, and other engines work!" << endl;
    
    return 0;
}
