#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "GameObject.hpp"

/**
 * Enemy - Another concrete implementation of GameObject
 * 
 * Represents an enemy character in Campus Quest.
 * This is a CONCRETE class - can be instantiated.
 * 
 * Inheritance chain: Enemy -> GameObject -> Vector2d
 */
class Enemy : public GameObject {
private:
    int damage;     // Attack damage
    bool isActive;  // Is enemy active/alive?

public:
    // ========== CONSTRUCTORS ==========
    
    /**
     * Default constructor - creates enemy at origin
     */
    Enemy();
    
    /**
     * Parameterized constructor
     * @param x Starting x position
     * @param y Starting y position
     * @param name Enemy's name/type
     * @param damage Attack damage (default 10)
     */
    Enemy(double x, double y, const std::string& name, int damage = 10);
    
    /**
     * Destructor
     */
    ~Enemy();
    
    
    // ========== ENEMY PROPERTIES ==========
    
    /**
     * Get enemy's attack damage
     * @return Damage value
     */
    int getDamage() const;
    
    /**
     * Set enemy's attack damage
     * @param damage New damage value
     */
    void setDamage(int damage);
    
    /**
     * Check if enemy is active
     * @return true if active, false if defeated
     */
    bool getIsActive() const;
    
    /**
     * Set enemy active state
     * @param active New active state
     */
    void setIsActive(bool active);
    
    /**
     * Defeat the enemy (set inactive)
     */
    void defeat();
    
    
    // ========== OVERRIDE PURE VIRTUAL METHODS ==========
    
    /**
     * Draw the enemy (implementation of pure virtual from GameObject)
     */
    void draw() const override;
    
    /**
     * Update enemy state (implementation of pure virtual from GameObject)
     * Simulates enemy AI behavior
     */
    void update() override;
};

#endif // ENEMY_HPP

