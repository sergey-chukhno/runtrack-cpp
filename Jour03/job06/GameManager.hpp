#ifndef GAMEMANAGER_HPP
#define GAMEMANAGER_HPP

#include "GameObject.hpp"
#include <vector>
#include <memory>  // For smart pointers
#include <string>

/**
 * GameManager - Container and manager for all game objects
 * 
 * This class demonstrates MODERN C++ memory management using smart pointers.
 * 
 * Key Concepts:
 * - Uses std::unique_ptr for automatic memory management
 * - RAII (Resource Acquisition Is Initialization)
 * - Move semantics (ownership transfer)
 * - No manual delete needed (automatic cleanup)
 * - Exception safe (no memory leaks even with exceptions)
 * 
 * Design Pattern: Manager/Repository Pattern
 * - Centralized management of game objects
 * - Single source of truth for all game entities
 * - Provides operations on all objects collectively
 * 
 * This is PROFESSIONAL game engine architecture!
 */
class GameManager {
private:
    // Container of game objects using SMART POINTERS
    // std::unique_ptr ensures:
    // - Automatic deletion when removed from vector
    // - Clear ownership (GameManager owns all objects)
    // - No memory leaks possible
    // - Exception safety
    std::vector<std::unique_ptr<GameObject>> objects;

public:
    // ========== CONSTRUCTORS & DESTRUCTOR ==========
    
    /**
     * Default constructor
     */
    GameManager();
    
    /**
     * Destructor
     * 
     * Thanks to unique_ptr, this automatically deletes ALL objects!
     * No manual cleanup needed - RAII in action!
     */
    ~GameManager();
    
    // Prevent copying (unique_ptr can't be copied)
    GameManager(const GameManager&) = delete;
    GameManager& operator=(const GameManager&) = delete;
    
    // Allow moving (unique_ptr can be moved)
    GameManager(GameManager&&) = default;
    GameManager& operator=(GameManager&&) = default;
    
    
    // ========== ADDING OBJECTS ==========
    
    /**
     * Add an object to the game (transfer ownership)
     * 
     * @param obj unique_ptr to GameObject (ownership transferred)
     * 
     * Usage:
     *   auto player = std::make_unique<Player>(...);
     *   manager.addObject(std::move(player));  // Transfer ownership
     *   // player is now nullptr
     * 
     * This demonstrates MOVE SEMANTICS:
     * - Ownership transfers from caller to GameManager
     * - Original pointer becomes nullptr
     * - No copying, just ownership transfer
     */
    void addObject(std::unique_ptr<GameObject> obj);
    
    /**
     * Create and add object using perfect forwarding (template method)
     * 
     * @tparam T Type of object to create (must inherit from GameObject)
     * @tparam Args Constructor argument types
     * @param args Constructor arguments
     * @return Raw pointer to created object (for immediate use)
     * 
     * Usage:
     *   Player* player = manager.createObject<Player>(0, 0, "Hero", 100);
     *   Enemy* enemy = manager.createObject<Enemy>(10, 10, "Goblin", 50, player, 5);
     * 
     * This is a FACTORY METHOD pattern:
     * - Manager creates object directly
     * - Returns pointer for immediate use
     * - Manager owns the object
     * - Modern C++ convenience!
     */
    template<typename T, typename... Args>
    T* createObject(Args&&... args) {
        // Create unique_ptr of specific type
        auto obj = std::make_unique<T>(std::forward<Args>(args)...);
        
        // Get raw pointer before moving (for return value)
        T* rawPtr = obj.get();
        
        // Move into container (ownership transfer)
        objects.push_back(std::move(obj));
        
        // Return raw pointer for immediate use
        return rawPtr;
    }
    
    
    // ========== GAME LOOP OPERATIONS ==========
    
    /**
     * Update all game objects
     * 
     * Calls update() on every object in the game.
     * This is called every frame/turn in the game loop.
     * 
     * Demonstrates POLYMORPHISM:
     * - Each object's correct update() is called
     * - Player, Enemy, Decor all behave correctly
     */
    void updateAll();
    
    /**
     * Draw all game objects
     * 
     * Calls draw() on every object in the game.
     * This renders all visible entities.
     * 
     * Demonstrates POLYMORPHISM:
     * - Each object's correct draw() is called
     */
    void drawAll();
    
    
    // ========== CONTAINER OPERATIONS ==========
    
    /**
     * Get number of objects in game
     * @return Count of managed objects
     */
    size_t size() const;
    
    /**
     * Check if game is empty
     * @return true if no objects, false otherwise
     */
    bool empty() const;
    
    /**
     * Remove all objects from game
     * 
     * Thanks to unique_ptr, all objects are automatically deleted!
     * No memory leaks, no manual cleanup needed.
     */
    void clear();
    
    /**
     * Get raw pointer to object at index
     * 
     * @param index Index in container
     * @return Raw pointer to GameObject (doesn't transfer ownership)
     * @throws std::out_of_range if index invalid
     * 
     * Note: Returns raw pointer for observation only.
     * GameManager still owns the object.
     */
    GameObject* getObject(size_t index);
    
    /**
     * Get const raw pointer to object at index
     * 
     * @param index Index in container
     * @return Const raw pointer to GameObject
     * @throws std::out_of_range if index invalid
     */
    const GameObject* getObject(size_t index) const;
    
    
    // ========== ADVANCED OPERATIONS ==========
    
    /**
     * Remove dead objects (health <= 0)
     * 
     * Iterates through all objects and removes those that are not alive.
     * Demonstrates automatic memory management - removed objects are
     * automatically deleted by unique_ptr!
     * 
     * @return Number of objects removed
     */
    size_t removeDeadObjects();
    
    /**
     * Find object by name
     * 
     * @param name Name to search for
     * @return Raw pointer to found object, or nullptr if not found
     */
    GameObject* findByName(const std::string& name);
    
    /**
     * Print statistics about managed objects
     * Shows counts by type, alive/dead status, etc.
     */
    void printStats() const;
};

#endif // GAMEMANAGER_HPP

