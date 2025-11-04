#include "Pingouin.hpp"
#include <iostream>
#include <memory>

int main() {
    {
        auto p1 = Pingouin::create("Tux", 2.5, 1.2, 3.0);
        auto p2 = Pingouin::create("Penny", 1.8, 1.0, 2.5);

        Pingouin::nettoyerColonie();
        std::cout << "Colonie size (inside scope): " << Pingouin::colonie.size() << std::endl;
        for (auto &w : Pingouin::colonie) if (auto p = w.lock()) p->sePresenter();
    }

    // after scope, p1 and p2 are destroyed; clean expired weak_ptrs
    Pingouin::nettoyerColonie();
    std::cout << "Colonie size (after scope): " << Pingouin::colonie.size() << std::endl;
    return 0;
}
