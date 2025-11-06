#include "Game.hpp"
#include <iostream>
#include <iomanip>

// ========== CONSTRUCTOR & DESTRUCTOR ==========

Game::Game() 
    : state(GameState::SETUP),
      player(nullptr),
      currentTurn(0)
{
    std::cout << "[Game] Game instance created" << std::endl;
}

Game::~Game() {
    std::cout << "[Game] Game instance destroyed" << std::endl;
    // manager automatically cleans up all objects (smart pointers!)
}


// ========== MAIN GAME INTERFACE ==========

/**
 * Run the complete game
 * 
 * This is the MAIN GAME ARCHITECTURE:
 * - Setup phase
 * - Game loop phase
 * - Results phase
 * 
 * This pattern is used in EVERY game!
 */
void Game::run() {
    displayIntro();
    
    // Phase 1: Setup
    setup();
    
    // Phase 2: Game Loop
    state = GameState::PLAYING;
    gameLoop();
    
    // Phase 3: Results
    displayResult();
}


// ========== GAME PHASES ==========

/**
 * Setup - Create the game world
 * 
 * This is where we instantiate all game objects:
 * - Player at origin
 * - Multiple enemies at various distances
 * - Decorative objects for immersion
 */
void Game::setup() {
    std::cout << "\n[SETUP] Initializing game world..." << std::endl;
    
    // Create player at origin
    player = manager.createObject<Player>(0.0, 0.0, "Hero", 80);
    std::cout << "  ✓ Created player: " << player->getName() 
              << " (HP: " << player->getHealth() << ")" << std::endl;
    
    // Create enemies at various distances
    Enemy* enemy1 = manager.createObject<Enemy>(5.0, 0.0, "Goblin", 25, player, 6);
    std::cout << "  ✓ Created enemy: " << enemy1->getName() 
              << " (HP: " << enemy1->getHealth() << ", Distance: " << player->distance(*enemy1) << ")" << std::endl;
    
    Enemy* enemy2 = manager.createObject<Enemy>(10.0, 0.0, "Orc", 35, player, 8);
    std::cout << "  ✓ Created enemy: " << enemy2->getName() 
              << " (HP: " << enemy2->getHealth() << ", Distance: " << player->distance(*enemy2) << ")" << std::endl;
    
    Enemy* enemy3 = manager.createObject<Enemy>(8.0, 6.0, "Troll", 40, player, 10);
    std::cout << "  ✓ Created enemy: " << enemy3->getName() 
              << " (HP: " << enemy3->getHealth() << ", Distance: " << player->distance(*enemy3) << ")" << std::endl;
    
    // Set player's initial target
    player->setTarget(enemy1);
    std::cout << "  ✓ Player targeting: " << enemy1->getName() << std::endl;
    
    // Create decorative objects for atmosphere
    manager.createObject<Decor>(3.0, 3.0, "Ancient Tree");
    manager.createObject<Decor>(-2.0, 4.0, "Boulder");
    manager.createObject<Decor>(7.0, -3.0, "Ruins");
    std::cout << "  ✓ Created 3 decorative objects" << std::endl;
    
    std::cout << "\n[SETUP] World initialized with " << manager.size() << " objects" << std::endl;
    
    // Display initial state
    std::cout << "\n[SETUP] Initial game state:" << std::endl;
    manager.printStats();
}

/**
 * Main Game Loop - THE HEART OF THE GAME!
 * 
 * This loop runs continuously while the game is playing.
 * It's the same pattern used by:
 * - Unity (Update loop)
 * - Unreal (Tick loop)
 * - Every game ever made!
 * 
 * Loop structure:
 * - Check condition (while playing)
 * - Process turn
 * - Check if game should end
 * - Repeat
 */
void Game::gameLoop() {
    std::cout << "\n╔════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║          GAME STARTED - GOOD LUCK!             ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════╝" << std::endl;
    
    // MAIN GAME LOOP - runs until game ends
    while (state == GameState::PLAYING) {
        currentTurn++;
        
        // Display turn information
        displayTurnHeader();
        
        // Process one turn of gameplay
        processTurn();
        
        // Check if game should end
        checkGameOver();
        
        // Safety check: enforce turn limit
        if (currentTurn >= MAX_TURNS && state == GameState::PLAYING) {
            std::cout << "\n⏰ Turn limit reached! Game ends in a draw." << std::endl;
            state = GameState::DRAW;
        }
    }
}

/**
 * Process one turn
 * 
 * This is the core game logic!
 * 
 * Turn Order (Important!):
 * 1. Player acts first (fair - they initiated combat)
 * 2. Enemies act second (respond to player)
 * 3. Clean up dead objects
 * 
 * This is standard turn-based game design.
 */
void Game::processTurn() {
    // Display current state before actions
    displayState();
    
    std::cout << "\n┌─────────────────────────────────────┐" << std::endl;
    std::cout << "│         ACTIONS THIS TURN           │" << std::endl;
    std::cout << "└─────────────────────────────────────┘" << std::endl;
    
    // Update all objects (polymorphic update calls)
    // Player updates first (attacks, switches weapon)
    // Then enemies update (AI, movement, attacks)
    std::cout << "\n[PLAYER PHASE]" << std::endl;
    if (player && player->isAlive()) {
        player->update();
        
        // Check if player's target is dead and switch to next enemy
        if (player->getTarget() && !player->getTarget()->isAlive()) {
            std::cout << "  ℹ️  Current target defeated, looking for new target..." << std::endl;
            
            // Find next living enemy
            for (size_t i = 0; i < manager.size(); i++) {
                if (Enemy* enemy = dynamic_cast<Enemy*>(manager.getObject(i))) {
                    if (enemy->isAlive()) {
                        player->setTarget(enemy);
                        std::cout << "  ℹ️  New target: " << enemy->getName() << std::endl;
                        break;
                    }
                }
            }
        }
    }
    
    std::cout << "\n[ENEMY PHASE]" << std::endl;
    // Update all enemies (they act after player)
    for (size_t i = 0; i < manager.size(); i++) {
        if (Enemy* enemy = dynamic_cast<Enemy*>(manager.getObject(i))) {
            enemy->update();
        }
    }
    
    // Clean up dead enemies
    std::cout << "\n[CLEANUP PHASE]" << std::endl;
    size_t removed = manager.removeDeadObjects();
    if (removed > 0) {
        std::cout << "  🗑️  Removed " << removed << " dead object(s)" << std::endl;
    } else {
        std::cout << "  ✓ No objects to remove" << std::endl;
    }
    
    std::cout << std::endl;
}

/**
 * Check game over conditions
 * 
 * Victory: All enemies defeated
 * Defeat: Player dead
 * 
 * This is called after every turn.
 */
void Game::checkGameOver() {
    // Check defeat condition first (player dead)
    if (!player || !player->isAlive()) {
        state = GameState::DEFEAT;
        return;
    }
    
    // Check victory condition (no living enemies)
    int livingEnemies = countLivingEnemies();
    if (livingEnemies == 0) {
        state = GameState::VICTORY;
        return;
    }
    
    // Game continues
    state = GameState::PLAYING;
}


// ========== DISPLAY METHODS ==========

void Game::displayIntro() {
    std::cout << "\n";
    std::cout << "╔════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║                                                ║" << std::endl;
    std::cout << "║           CAMPUS QUEST: ARENA BATTLE           ║" << std::endl;
    std::cout << "║                                                ║" << std::endl;
    std::cout << "║        Complete Game with Game Loop            ║" << std::endl;
    std::cout << "║                                                ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════╝" << std::endl;
    std::cout << "\n";
    std::cout << "Objective: Defeat all enemies before you fall!" << std::endl;
    std::cout << "Victory: All enemies defeated" << std::endl;
    std::cout << "Defeat: Player health reaches 0" << std::endl;
    std::cout << "Turn Limit: " << MAX_TURNS << " turns" << std::endl;
    std::cout << "\n";
}

void Game::displayTurnHeader() {
    std::cout << "\n╔════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║  TURN " << std::setw(3) << currentTurn << " / " << MAX_TURNS;
    std::cout << "                                  ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════╝" << std::endl;
}

void Game::displayState() {
    std::cout << "\n┌─────────────────────────────────────┐" << std::endl;
    std::cout << "│         CURRENT GAME STATE          │" << std::endl;
    std::cout << "└─────────────────────────────────────┘" << std::endl;
    
    // Display all game objects
    manager.drawAll();
    
    // Display additional info
    std::cout << "\n📊 Living enemies: " << countLivingEnemies() << std::endl;
}

void Game::displayResult() {
    std::cout << "\n\n";
    std::cout << "╔════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║                                                ║" << std::endl;
    
    switch (state) {
        case GameState::VICTORY:
            std::cout << "║              🎉 VICTORY! 🎉                    ║" << std::endl;
            std::cout << "║                                                ║" << std::endl;
            std::cout << "║        All enemies have been defeated!         ║" << std::endl;
            break;
            
        case GameState::DEFEAT:
            std::cout << "║              💀 DEFEAT 💀                      ║" << std::endl;
            std::cout << "║                                                ║" << std::endl;
            std::cout << "║          The hero has fallen...                ║" << std::endl;
            break;
            
        case GameState::DRAW:
            std::cout << "║              ⚔️  DRAW ⚔️                       ║" << std::endl;
            std::cout << "║                                                ║" << std::endl;
            std::cout << "║         Turn limit reached - no winner         ║" << std::endl;
            break;
            
        default:
            std::cout << "║              GAME ENDED                        ║" << std::endl;
            break;
    }
    
    std::cout << "║                                                ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════╝" << std::endl;
    
    displayStats();
}

void Game::displayStats() {
    std::cout << "\n";
    std::cout << "┌─────────────────────────────────────┐" << std::endl;
    std::cout << "│          GAME STATISTICS            │" << std::endl;
    std::cout << "└─────────────────────────────────────┘" << std::endl;
    
    std::cout << "Total turns: " << currentTurn << " / " << MAX_TURNS << std::endl;
    
    if (player) {
        std::cout << "Player final health: " << player->getHealth() << std::endl;
        std::cout << "Player status: " << (player->isAlive() ? "ALIVE" : "DEFEATED") << std::endl;
    }
    
    int livingEnemies = countLivingEnemies();
    std::cout << "Enemies remaining: " << livingEnemies << std::endl;
    
    std::cout << "\nFinal game state:" << std::endl;
    manager.printStats();
    
    std::cout << "\n";
}


// ========== HELPER METHODS ==========

/**
 * Count living enemies
 * 
 * Iterates through all objects and counts Enemies that are alive.
 * Uses dynamic_cast for type checking.
 */
int Game::countLivingEnemies() const {
    int count = 0;
    
    for (size_t i = 0; i < manager.size(); i++) {
        // Try to cast to Enemy
        if (const Enemy* enemy = dynamic_cast<const Enemy*>(manager.getObject(i))) {
            if (enemy->isAlive()) {
                count++;
            }
        }
    }
    
    return count;
}

std::string Game::getStateName(GameState state) const {
    switch (state) {
        case GameState::SETUP:   return "SETUP";
        case GameState::PLAYING: return "PLAYING";
        case GameState::VICTORY: return "VICTORY";
        case GameState::DEFEAT:  return "DEFEAT";
        case GameState::DRAW:    return "DRAW";
        default:                 return "UNKNOWN";
    }
}

