#include <iostream>
#include <array>
#include <random>
#include <string>

enum class Specialite { IA, Web, Logiciel, SystemeImmersif, Cybersecurite, Count };

const char* specialiteToString(Specialite s) {
    switch (s) {
        case Specialite::IA: return "IA";
        case Specialite::Web: return "Web";
        case Specialite::Logiciel: return "Logiciel";
        case Specialite::SystemeImmersif: return "Système Immersif";
        case Specialite::Cybersecurite: return "Cybersécurité";
        default: return "Unknown";
    }
}

void afficherSpecialite(Specialite s, int nbEtudiants) {
    const int capacite = 66;
    int places = capacite - nbEtudiants;
    std::cout << specialiteToString(s) << ": " << nbEtudiants << " étudiants, Places disponibles = " << places << "\n";
}

int main() {
    constexpr size_t nbSpec = static_cast<size_t>(Specialite::Count);
    std::array<Specialite, nbSpec> tab{};
    for (size_t i = 0; i < nbSpec; ++i) tab[i] = static_cast<Specialite>(i);

    // random numbers between 12 and 66
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(12, 66);

    std::array<int, nbSpec> nbEtudiants{};
    for (size_t i = 0; i < nbSpec; ++i) nbEtudiants[i] = dist(gen);

    for (size_t i = 0; i < nbSpec; ++i) {
        afficherSpecialite(tab[i], nbEtudiants[i]);
    }
    return 0;
}
