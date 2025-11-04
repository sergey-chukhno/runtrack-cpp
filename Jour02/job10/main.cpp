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

        // --- Démo du journal d'aventures (Job09) ---
        a->ajouterAventure("2025-11-01", "Chasse au krill difficile, mer agitée");
        a->ajouterAventure("2025-11-02", "Aider un poussin blessé");
        a->afficherAventures();

        std::cout << "\nModification de l'aventure du 2025-11-02...\n";
        a->modifierAventure("2025-11-02", "Transporter un poussin blessé jusqu'au nid");
        a->afficherAventures();

        std::cout << "\nRetrait de l'aventure du 2025-11-01...\n";
        a->retirerAventure("2025-11-01");
        a->afficherAventures();

        // --- Démo Job10: temps de compétition (ms) ---
        a->ajouterTempsCompetitionMs(2345); // 2.345 s
        a->ajouterTempsCompetitionMs(1980); // 1.980 s
        a->ajouterTempsCompetitionMs(2345); // duplicate
        a->ajouterTempsCompetitionMs(3000); // 3.000 s

        std::cout << "\nAvant suppression (triés) :\n";
        a->afficherTempsCompetitionsMs();

        std::cout << "\nSuppression d'une occurrence de 2345 ms...\n";
        a->retirerUneOccurrenceTempsMs(2345);
        std::cout << "Occurrences de 2345 ms : " << a->compterOccurencesTempsMs(2345) << std::endl;
        std::cout << "Après suppression :\n";
        a->afficherTempsCompetitionsMs();

        return 0;
}
