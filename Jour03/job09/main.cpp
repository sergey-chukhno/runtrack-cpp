#include <iostream>
#include "Game.hpp"

/**
 * Main Entry Point - Campus Quest with COLLISION DETECTION
 * 
 * JOB 09 - COLLISION DETECTION
 * 
 * Evolution Timeline:
 * Job 01: Vector2d (position, math)
 * Job 02: GameObject (polymorphism)
 * Job 03: Character, Decor (types)
 * Job 04: Weapon system (strategy)
 * Job 05: Player, Enemy (AI, combat)
 * Job 06: GameManager (smart pointers)
 * Job 07: Game Loop (automation)
 * Job 08: Interactive Mode (player control)
 * Job 09: COLLISION DETECTION (spatial physics!) ← YOU ARE HERE!
 * 
 * New Features (Job 09):
 * - Distance-based collision detection (0.5 unit radius)
 * - GameObjects cannot pass through each other
 * - Player movement blocked by collisions
 * - Enemy AI respects collisions
 * - Decor objects act as obstacles
 * - Collision feedback to player
 * 
 * This is now a PHYSICALLY REALISTIC GAME!
 */

int main() {
    try {
        std::cout << "╔════════════════════════════════════════════════╗" << std::endl;
        std::cout << "║  CAMPUS QUEST: WITH COLLISION DETECTION! 💥    ║" << std::endl;
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
    std::cout << "🎓 You've completed 9 JOBS!" << std::endl;
    std::cout << "🏆 From basic classes to physics-enabled games!" << std::endl;
    std::cout << "💻 Modern C++ mastery + Game development!" << std::endl;
    std::cout << "💥 With realistic collision detection!" << std::endl;
    std::cout << "🎮 YOU'RE NOW A GAME ENGINE ARCHITECT!" << std::endl;
    std::cout << "\n";
    
    return 0;
}
