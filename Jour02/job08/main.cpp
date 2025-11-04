#include "Pingouin.hpp"
#include <iostream>

int main() {
    auto a = Pingouin::create("A", 2.0, 1.0, 1.5);
    auto b = Pingouin::create("B", 2.2, 1.1, 1.4);
    auto c = Pingouin::create("C", 1.8, 1.0, 1.2);

    // add friends (unidirectional)
    a->ajouterAmi(b);
    a->ajouterAmi(c);
    b->ajouterAmi(c);

    std::cout << "Amis de A:" << std::endl;
    for (auto &f : a->listerAmis()) std::cout << "- " << f->getNom() << std::endl;

    // destroy c and show that A's friend list is cleaned
    c.reset();
    std::cout << "Après destruction de C:" << std::endl;
    for (auto &f : a->listerAmis()) std::cout << "- " << f->getNom() << std::endl;

    return 0;
}
