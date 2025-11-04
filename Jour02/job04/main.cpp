#include "Pingouin.hpp"
#include <iostream>

int main() {
    {
        auto p1 = Pingouin::create("Tux", 2.5, 1.2, 3.0);
        auto p2 = Pingouin::create("Penny", 1.8, 1.0, 2.5);
        auto p3 = Pingouin::create("Lazy", 1.0, 0.0, 1.5); // marche = 0 -> impossible

        std::cout << "--- Temps pendant scope ---\n";
        Pingouin::afficherTempsTous();
    }

    std::cout << "--- Après sortie de scope ---\n";
    Pingouin::afficherTempsTous();
    return 0;
}
