#include "Pingouin.hpp"
#include <iostream>

int main() {
    // demonstrate competences
    Pingouin::afficherCompetences();
    Pingouin::ajouterCompetence("natation", 3);
    Pingouin::ajouterCompetence("plongee", 2);
    Pingouin::ajouterCompetence("natation", 5); // duplicate ignored
    Pingouin::afficherCompetences();

    Pingouin::modifierCompetence("plongee", 4);
    Pingouin::afficherCompetences();

    Pingouin::retirerCompetence("natation");
    Pingouin::afficherCompetences();

    // keep previous demo behavior
    Pingouin::ajouterLieu("lac");
    Pingouin::afficherLieux();
    auto p1 = Pingouin::create("Tux", 2.5, 1.2, 3.0);
    Pingouin::afficherTempsTous();
    return 0;
}
