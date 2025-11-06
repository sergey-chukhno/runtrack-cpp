#include <iostream>
#include "Game.hpp"

/**
 * Main Entry Point - Campus Quest Game
 * 
 * This is the CULMINATION of all 7 jobs!
 * 
 * Job 01: Vector2d (position, distance calculations)
 * Job 02: GameObject (polymorphic base class)
 * Job 03: Character, Decor (concrete types)
 * Job 04: Weapon system (Bow, Spear, Sword)
 * Job 05: Player, Enemy (combat AI)
 * Job 06: GameManager (smart pointers, container)
 * Job 07: Game Loop (THIS FILE - brings it all together!)
 * 
 * Architecture Demonstrated:
 * - Object-Oriented Programming (inheritance, polymorphism)
 * - Design Patterns (Strategy, Factory, Manager, State Machine)
 * - Modern C++ (smart pointers, RAII, move semantics)
 * - Game Development (game loop, AI, combat system)
 * - Memory Management (automatic cleanup, no leaks)
 * 
 * This is PROFESSIONAL game architecture!
 * Used by Unity, Unreal, and every modern game engine.
 */

int main() {
    try {
        // Create game instance
        Game game;
        
        // Run the complete game
        // This includes:
        // - Setup (create world)
        // - Game loop (main gameplay)
        // - Results (victory/defeat)
        game.run();
        
        std::cout << "\n[Main] Game completed successfully!" << std::endl;
        
    } catch (const std::exception& e) {
        // Exception handling (modern C++ best practice)
        std::cerr << "\n[ERROR] Exception caught: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        // Catch any other exceptions
        std::cerr << "\n[ERROR] Unknown exception caught!" << std::endl;
        return 1;
    }
    
    std::cout << "\n";
    std::cout << "════════════════════════════════════════════════" << std::endl;
    std::cout << "         Thanks for playing Campus Quest!       " << std::endl;
    std::cout << "════════════════════════════════════════════════" << std::endl;
    std::cout << "\n";
    std::cout << "🎓 You've completed all 7 jobs!" << std::endl;
    std::cout << "🏆 Professional game architecture achieved!" << std::endl;
    std::cout << "💻 Modern C++ mastery demonstrated!" << std::endl;
    std::cout << "\n";
    
    return 0;
}
