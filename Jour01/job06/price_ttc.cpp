#include <iostream>
#include <iomanip>

int main() {
    double prixHT_per_kg;
    double kilos;
    double tauxTVA_percent;

    std::cout << "Prix HT par kilo (ex: 2.50): ";
    if (!(std::cin >> prixHT_per_kg)) { std::cerr << "Entrée invalide\n"; return 1; }

    std::cout << "Nombre de kilos (ex: 3.5): ";
    if (!(std::cin >> kilos)) { std::cerr << "Entrée invalide\n"; return 1; }

    std::cout << "Taux de TVA en pourcentage (ex: 15): ";
    if (!(std::cin >> tauxTVA_percent)) { std::cerr << "Entrée invalide\n"; return 1; }

    double totalHT = prixHT_per_kg * kilos;
    double totalTTC = totalHT * (1.0 + tauxTVA_percent / 100.0);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Prix HT = " << totalHT << "\n";
    std::cout << "Prix TTC = " << totalTTC << "\n";

    return 0;
}
