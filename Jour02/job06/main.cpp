#include "Pingouin.hpp"
#include <iostream>

int main() {
    // demonstrate lieux static list
    Pingouin::afficherLieux();
    Pingouin::ajouterLieu("lac");
    Pingouin::ajouterLieu("glacier");
    Pingouin::ajouterLieu("banquise");
    Pingouin::ajouterLieu("lac"); // duplicate, should be ignored
    Pingouin::afficherLieux();

    Pingouin::retirerLieu("glacier");
    Pingouin::afficherLieux();

    // also demonstrate colony functionality unchanged
    auto p1 = Pingouin::create("Tux", 2.5, 1.2, 3.0);
    Pingouin::afficherTempsTous();

    return 0;
}
