#include <iostream>
#include "Vector2d.hpp"

using namespace std;

/**
 * Test program for Vector2d class
 * Demonstrates all features: constructors, getters, setters, operators, distance
 */
int main() {
    cout << "========================================" << endl;
    cout << "   Vector2d Class Test - Campus Quest  " << endl;
    cout << "========================================" << endl;
    cout << endl;
    
    // ========== TEST 1: Constructors ==========
    cout << "TEST 1: Constructors" << endl;
    cout << "--------------------" << endl;
    
    Vector2d v1;  // Default constructor: should be (0, 0)
    cout << "v1 (default constructor): (" << v1.getX() << ", " << v1.getY() << ")" << endl;
    
    Vector2d v2(3.0, 4.0);  // Parameterized constructor
    cout << "v2 (parameterized): (" << v2.getX() << ", " << v2.getY() << ")" << endl;
    
    Vector2d v3(6.0, 8.0);  // Another vector for testing
    cout << "v3 (parameterized): (" << v3.getX() << ", " << v3.getY() << ")" << endl;
    cout << endl;
    
    
    // ========== TEST 2: Getters ==========
    cout << "TEST 2: Getters" << endl;
    cout << "---------------" << endl;
    cout << "v2.getX() = " << v2.getX() << endl;
    cout << "v2.getY() = " << v2.getY() << endl;
    cout << endl;
    
    
    // ========== TEST 3: Setters ==========
    cout << "TEST 3: Setters" << endl;
    cout << "---------------" << endl;
    cout << "Setting v1 to (10.5, 20.3)..." << endl;
    v1.setX(10.5);
    v1.setY(20.3);
    cout << "v1 after setters: (" << v1.getX() << ", " << v1.getY() << ")" << endl;
    cout << endl;
    
    
    // ========== TEST 4: Addition Operator ==========
    cout << "TEST 4: Addition Operator (+)" << endl;
    cout << "------------------------------" << endl;
    cout << "v2 = (" << v2.getX() << ", " << v2.getY() << ")" << endl;
    cout << "v3 = (" << v3.getX() << ", " << v3.getY() << ")" << endl;
    
    Vector2d sum = v2 + v3;  // Uses operator+
    cout << "v2 + v3 = (" << sum.getX() << ", " << sum.getY() << ")" << endl;
    cout << "Expected: (9.0, 12.0)" << endl;
    cout << endl;
    
    
    // ========== TEST 5: Subtraction Operator ==========
    cout << "TEST 5: Subtraction Operator (-)" << endl;
    cout << "---------------------------------" << endl;
    cout << "v3 = (" << v3.getX() << ", " << v3.getY() << ")" << endl;
    cout << "v2 = (" << v2.getX() << ", " << v2.getY() << ")" << endl;
    
    Vector2d diff = v3 - v2;  // Uses operator-
    cout << "v3 - v2 = (" << diff.getX() << ", " << diff.getY() << ")" << endl;
    cout << "Expected: (3.0, 4.0)" << endl;
    cout << endl;
    
    
    // ========== TEST 6: Distance Calculation ==========
    cout << "TEST 6: Distance Calculation" << endl;
    cout << "----------------------------" << endl;
    cout << "v2 = (" << v2.getX() << ", " << v2.getY() << ")" << endl;
    cout << "v3 = (" << v3.getX() << ", " << v3.getY() << ")" << endl;
    
    double dist = v2.distance(v3);
    cout << "Distance from v2 to v3 = " << dist << endl;
    cout << "Expected: 5.0" << endl;
    cout << "Calculation: sqrt((6-3)² + (8-4)²) = sqrt(9 + 16) = sqrt(25) = 5" << endl;
    cout << endl;
    
    
    // ========== TEST 7: Campus Quest Example ==========
    cout << "TEST 7: Campus Quest Game Example" << endl;
    cout << "----------------------------------" << endl;
    
    Vector2d playerPos(0.0, 0.0);      // Player starts at origin
    Vector2d treasurePos(30.0, 40.0);  // Treasure location
    
    cout << "Player position: (" << playerPos.getX() << ", " << playerPos.getY() << ")" << endl;
    cout << "Treasure position: (" << treasurePos.getX() << ", " << treasurePos.getY() << ")" << endl;
    
    double distanceToTreasure = playerPos.distance(treasurePos);
    cout << "Distance to treasure: " << distanceToTreasure << " units" << endl;
    
    // Player moves 10 units right, 15 units up
    Vector2d movement(10.0, 15.0);
    playerPos = playerPos + movement;  // Uses operator+
    
    cout << "\nPlayer moves by (" << movement.getX() << ", " << movement.getY() << ")" << endl;
    cout << "New player position: (" << playerPos.getX() << ", " << playerPos.getY() << ")" << endl;
    
    distanceToTreasure = playerPos.distance(treasurePos);
    cout << "New distance to treasure: " << distanceToTreasure << " units" << endl;
    cout << endl;
    
    
    // ========== TEST 8: Validation Test (Optional) ==========
    cout << "TEST 8: Validation Test" << endl;
    cout << "-----------------------" << endl;
    cout << "Testing invalid input handling..." << endl;
    
    try {
        v1.setX(0.0 / 0.0);  // NaN (Not a Number)
        cout << "ERROR: Should have thrown exception for NaN!" << endl;
    } catch (const std::invalid_argument& e) {
        cout << "✓ Caught exception for NaN: " << e.what() << endl;
    }
    
    cout << endl;
    
    
    // ========== Summary ==========
    cout << "========================================" << endl;
    cout << "   All tests completed successfully!    " << endl;
    cout << "========================================" << endl;
    
    return 0;
}

