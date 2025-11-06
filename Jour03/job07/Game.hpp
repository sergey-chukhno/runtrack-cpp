#ifndef GAME_HPP
#define GAME_HPP

#include "GameManager.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Decor.hpp"

/**
 * Game - Main game controller with game loop
 * 
 * This is the HEART of the game - where everything comes together!
 * 
 * Responsibilities:
 * - Initialize game world (player, enemies, decorations)
 * - Run main game loop (update, draw, check conditions)
 * - Manage game state (playing, victory, defeat)
 * - Display game information
 * - Handle victory/defeat conditions
 * 
 * This demonstrates:
 * - Game loop architecture (universal game pattern)
 * - State machine (game state management)
 * - Integration of all previous jobs (1-6)
 * 
 * Game Flow:
 * 1. Setup: Create player, enemies, decorations
 * 2. Loop: While playing
 *    - Display turn info
 *    - Player updates (attacks, switches weapon)
 *    - Enemies update (AI pathfinding, attack)
 *    - Clean up dead enemies
 *    - Check victory/defeat
 * 3. End: Display results
 * 
 * This is PROFESSIONAL game architecture!
 */

/**
 * GameState - Represents current state of the game
 * 
 * This is a STATE MACHINE pattern:
 * - Clear states with defined transitions
 * - Easy to extend (add PAUSED, MENU, etc.)
 * - Separates state from logic
 */
enum class GameState {
    SETUP,      // Initializing game
    PLAYING,    // Main gameplay
    VICTORY,    // Player won
    DEFEAT,     // Player lost
    DRAW        // Turn limit reached
};

class Game {
private:
    // ========== GAME COMPONENTS ==========
    GameManager manager;     // Manages all game objects (smart pointers!)
    GameState state;         // Current game state
    
    // ========== GAME OBJECTS (Raw pointers - manager owns them) ==========
    Player* player;          // Player character (borrowed from manager)
    
    // ========== GAME PARAMETERS ==========
    int currentTurn;         // Current turn number
    static const int MAX_TURNS = 50;  // Turn limit (prevents infinite games)
    
public:
    // ========== CONSTRUCTOR & DESTRUCTOR ==========
    
    /**
     * Constructor - initializes game state
     */
    Game();
    
    /**
     * Destructor
     * GameManager handles all object cleanup automatically!
     */
    ~Game();
    
    
    // ========== MAIN GAME INTERFACE ==========
    
    /**
     * Run the complete game
     * 
     * This is the MAIN ENTRY POINT:
     * 1. Setup game world
     * 2. Run game loop
     * 3. Display final results
     * 
     * This is the classic game architecture pattern!
     */
    void run();
    
private:
    // ========== GAME PHASES ==========
    
    /**
     * Setup phase - Initialize game world
     * 
     * Creates:
     * - Player character
     * - Enemy characters at various distances
     * - Decorative objects
     * 
     * Sets up initial game state.
     */
    void setup();
    
    /**
     * Main game loop - The heart of the game!
     * 
     * Runs while state == PLAYING:
     * 1. Display turn information
     * 2. Process one turn of gameplay
     * 3. Check if game should end
     * 
     * This is the GAME LOOP pattern used by EVERY game!
     */
    void gameLoop();
    
    /**
     * Process one turn of gameplay
     * 
     * Turn sequence:
     * 1. Display current game state
     * 2. Player acts (attack, switch weapon)
     * 3. Enemies act (move, attack)
     * 4. Clean up dead objects
     * 
     * This is turn-based game logic.
     */
    void processTurn();
    
    /**
     * Check victory/defeat conditions
     * 
     * Victory: All enemies defeated
     * Defeat: Player health <= 0
     * Draw: Turn limit reached
     * 
     * Updates game state accordingly.
     */
    void checkGameOver();
    
    
    // ========== DISPLAY METHODS ==========
    
    /**
     * Display game title and introduction
     */
    void displayIntro();
    
    /**
     * Display turn header with turn number and state
     */
    void displayTurnHeader();
    
    /**
     * Display current game state
     * Shows all object positions, health, etc.
     */
    void displayState();
    
    /**
     * Display final game results
     * Shows victory/defeat message and statistics
     */
    void displayResult();
    
    /**
     * Display game statistics
     * Turns taken, damage dealt, etc.
     */
    void displayStats();
    
    
    // ========== HELPER METHODS ==========
    
    /**
     * Count living enemies in the game
     * @return Number of enemies still alive
     * 
     * Used for victory condition checking.
     */
    int countLivingEnemies() const;
    
    /**
     * Get state name as string
     * @param state Game state
     * @return String representation
     */
    std::string getStateName(GameState state) const;
};

#endif // GAME_HPP

