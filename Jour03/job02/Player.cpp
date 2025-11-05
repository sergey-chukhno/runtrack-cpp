#include "Player.hpp"
#include <iostream>

// ========== CONSTRUCTORS & DESTRUCTOR ==========

Player::Player() : GameObject(0.0, 0.0, "Player"), health(100) {
    // GameObject(0.0, 0.0, "Player") calls parent constructor
    // health(100) initializes our health member
}

Player::Player(double x, double y, const std::string& name, int health)
    : GameObject(x, y, name), health(health) {
    // Call parent constructor with position and name
    // Initialize our health member
}

Player::~Player() {
    // Cleanup for Player-specific resources (none in this simple example)
}


// ========== HEALTH MANAGEMENT ==========

int Player::getHealth() const {
    return health;
}

void Player::setHealth(int health) {
    // Clamp health between 0 and 100
    if (health < 0) {
        this->health = 0;
    } else if (health > 100) {
        this->health = 100;
    } else {
        this->health = health;
    }
}

void Player::takeDamage(int damage) {
    health -= damage;
    if (health < 0) {
        health = 0;  // Can't go below 0
    }
}

void Player::heal(int amount) {
    health += amount;
    if (health > 100) {
        health = 100;  // Max health is 100
    }
}


// ========== OVERRIDE PURE VIRTUAL METHODS ==========

/**
 * Implementation of pure virtual draw() from GameObject
 * 
 * This provides the CONCRETE implementation that was required.
 * Without this, Player would also be abstract!
 */
void Player::draw() const {
    std::cout << "[PLAYER '" << getName() << "'] ";
    std::cout << "Position: (" << getX() << ", " << getY() << ") ";
    std::cout << "Health: " << health << "/100";
    std::cout << std::endl;
}

/**
 * Implementation of pure virtual update() from GameObject
 * 
 * In a real game, this might:
 * - Read keyboard input
 * - Update animations
 * - Check for collisions
 * 
 * For this demo, we just print a message.
 */
void Player::update() {
    // Simulate some player logic
    // In real game: handle input, physics, etc.
    std::cout << "  > Updating " << getName() << "... (checking input, physics)" << std::endl;
}

