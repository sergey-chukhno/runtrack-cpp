#include <iostream>
#include "Game.hpp"

/**
 * Main Entry Point - Campus Quest INTERACTIVE Game
 * 
 * JOB 08 - INTERACTIVE MODE
 * 
 * This is the FINAL evolution of our game!
 * 
 * Evolution Timeline:
 * Job 01: Vector2d (position, math)
 * Job 02: GameObject (polymorphism)
 * Job 03: Character, Decor (types)
 * Job 04: Weapon system (strategy)
 * Job 05: Player, Enemy (AI, combat)
 * Job 06: GameManager (smart pointers)
 * Job 07: Game Loop (automation)
 * Job 08: INTERACTIVE MODE (player control!) ← YOU ARE HERE!
 * 
 * New Features:
 * - User input handling
 * - Menu system
 * - WASD movement controls
 * - Manual attack control
 * - Weapon selection
 * - Interactive gameplay
 * 
 * This is a COMPLETE, PLAYABLE GAME!
 */

int main() {
    try {
        std::cout << "╔════════════════════════════════════════════════╗" << std::endl;
        std::cout << "║    WELCOME TO CAMPUS QUEST: INTERACTIVE!       ║" << std::endl;
        std::cout << "╚════════════════════════════════════════════════╝" << std::endl;
        std::cout << "\n";
        
        std::cout << "Select game mode:" << std::endl;
        std::cout << "  [1] Interactive Mode (Player controlled) 🎮" << std::endl;
        std::cout << "  [2] Automated Mode (Watch AI play)" << std::endl;
        std::cout << "Choice: ";
        
        int modeChoice;
        std::cin >> modeChoice;
        std::cin.ignore();
        
        bool interactive = (modeChoice == 1);
        
        if (interactive) {
            std::cout << "\n✓ Interactive mode selected!" << std::endl;
            std::cout << "  You control the hero's every action!" << std::endl;
        } else {
            std::cout << "\n✓ Automated mode selected!" << std::endl;
            std::cout << "  Watch the game play itself!" << std::endl;
        }
        
        std::cout << "\nPress Enter to start...";
        std::cin.ignore();
        
        // Create game with chosen mode
        Game game(interactive);
        
        // Run the complete game
        game.run();
        
        std::cout << "\n[Main] Game completed successfully!" << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "\n[ERROR] Exception caught: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "\n[ERROR] Unknown exception caught!" << std::endl;
        return 1;
    }
    
    std::cout << "\n";
    std::cout << "════════════════════════════════════════════════" << std::endl;
    std::cout << "      Thanks for playing Campus Quest!          " << std::endl;
    std::cout << "════════════════════════════════════════════════" << std::endl;
    std::cout << "\n";
    std::cout << "🎓 You've completed ALL 8 JOBS!" << std::endl;
    std::cout << "🏆 From basic classes to interactive games!" << std::endl;
    std::cout << "💻 Modern C++ mastery + Game development!" << std::endl;
    std::cout << "🎮 YOU'RE NOW A GAME ENGINE ARCHITECT!" << std::endl;
    std::cout << "\n";
    
    return 0;
}
