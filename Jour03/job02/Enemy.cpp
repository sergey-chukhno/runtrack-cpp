#include "Enemy.hpp"
#include <iostream>

// ========== CONSTRUCTORS & DESTRUCTOR ==========

Enemy::Enemy() : GameObject(0.0, 0.0, "Enemy"), damage(10), isActive(true) {
    // GameObject(0.0, 0.0, "Enemy") calls parent constructor
    // damage(10) initializes attack damage
    // isActive(true) initializes active state
}

Enemy::Enemy(double x, double y, const std::string& name, int damage)
    : GameObject(x, y, name), damage(damage), isActive(true) {
    // Call parent constructor with position and name
    // Initialize our damage and isActive members
}

Enemy::~Enemy() {
    // Cleanup for Enemy-specific resources (none in this simple example)
}


// ========== ENEMY PROPERTIES ==========

int Enemy::getDamage() const {
    return damage;
}

void Enemy::setDamage(int damage) {
    this->damage = (damage < 0) ? 0 : damage;  // Damage can't be negative
}

bool Enemy::getIsActive() const {
    return isActive;
}

void Enemy::setIsActive(bool active) {
    this->isActive = active;
}

void Enemy::defeat() {
    isActive = false;
}


// ========== OVERRIDE PURE VIRTUAL METHODS ==========

/**
 * Implementation of pure virtual draw() from GameObject
 * 
 * Draws enemy information differently than Player.
 * Each class can have its own unique implementation!
 */
void Enemy::draw() const {
    std::cout << "[ENEMY '" << getName() << "'] ";
    std::cout << "Position: (" << getX() << ", " << getY() << ") ";
    std::cout << "Damage: " << damage << " ";
    std::cout << "Status: " << (isActive ? "ACTIVE" : "DEFEATED");
    std::cout << std::endl;
}

/**
 * Implementation of pure virtual update() from GameObject
 * 
 * In a real game, this might:
 * - Run AI pathfinding
 * - Check player distance
 * - Execute attack patterns
 * 
 * For this demo, we just simulate basic AI.
 */
void Enemy::update() {
    if (isActive) {
        // Simulate some enemy AI logic
        // In real game: pathfinding, targeting, attacking
        std::cout << "  > Updating " << getName() << "... (AI: patrol, search for player)" << std::endl;
    } else {
        std::cout << "  > " << getName() << " is defeated (no update)" << std::endl;
    }
}

