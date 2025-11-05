#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "GameObject.hpp"

/**
 * Player - Concrete implementation of GameObject
 * 
 * Represents a player character in Campus Quest.
 * This is a CONCRETE class - can be instantiated.
 * 
 * Inheritance chain: Player -> GameObject -> Vector2d
 */
class Player : public GameObject {
private:
    int health;  // Player's health points

public:
    // ========== CONSTRUCTORS ==========
    
    /**
     * Default constructor - creates player at origin with 100 health
     */
    Player();
    
    /**
     * Parameterized constructor
     * @param x Starting x position
     * @param y Starting y position
     * @param name Player's name
     * @param health Starting health (default 100)
     */
    Player(double x, double y, const std::string& name, int health = 100);
    
    /**
     * Destructor - not virtual (Player is a leaf class, unlikely to be inherited)
     */
    ~Player();
    
    
    // ========== HEALTH MANAGEMENT ==========
    
    /**
     * Get player's current health
     * @return Health value
     */
    int getHealth() const;
    
    /**
     * Set player's health
     * @param health New health value
     */
    void setHealth(int health);
    
    /**
     * Take damage
     * @param damage Amount of damage to take
     */
    void takeDamage(int damage);
    
    /**
     * Heal player
     * @param amount Amount of health to restore
     */
    void heal(int amount);
    
    
    // ========== OVERRIDE PURE VIRTUAL METHODS ==========
    
    /**
     * Draw the player (implementation of pure virtual from GameObject)
     * 
     * "override" keyword (C++11):
     * - Tells compiler: "I'm overriding a virtual method"
     * - Compiler checks that parent actually has this method
     * - Catches typos and mistakes
     */
    void draw() const override;
    
    /**
     * Update player state (implementation of pure virtual from GameObject)
     * Simulates player movement/actions
     */
    void update() override;
};

#endif // PLAYER_HPP

