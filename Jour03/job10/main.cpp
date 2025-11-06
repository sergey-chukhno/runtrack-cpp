#include <iostream>
#include "Game.hpp"

/**
 * Main Entry Point - Campus Quest with PROJECTILES
 * 
 * JOB 10 - PROJECTILES
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
 * Job 09: Collision Detection (spatial physics)
 * Job 10: PROJECTILES (flying arrows!) ← YOU ARE HERE!
 * 
 * New Features (Job 10):
 * - Projectile class (flying arrows)
 * - Bow fires projectiles (different from melee)
 * - Collision-based damage (projectiles hit targets)
 * - Automatic projectile cleanup
 * - Visual feedback for ranged attacks
 * - Instant-hit model with visible objects
 * 
 * Bow attacks now feel DIFFERENT from Spear/Sword!
 */

int main() {
    try {
        std::cout << "╔════════════════════════════════════════════════╗" << std::endl;
        std::cout << "║    CAMPUS QUEST: PROJECTILE WARFARE! 🏹💥      ║" << std::endl;
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
    std::cout << "🎓 You've completed 10 JOBS!" << std::endl;
    std::cout << "🏆 From basic classes to complete game systems!" << std::endl;
    std::cout << "💻 Modern C++ mastery + Game development!" << std::endl;
    std::cout << "💥 Collisions + 🏹 Projectiles!" << std::endl;
    std::cout << "🎮 YOU'RE NOW A GAME ENGINE ARCHITECT!" << std::endl;
    std::cout << "\n";
    
    return 0;
}
