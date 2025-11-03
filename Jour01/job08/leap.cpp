#include <iostream>

int main() {
    long long year;
    std::cout << "Entrez une année: ";
    if (!(std::cin >> year)) {
        std::cerr << "Entrée invalide\n";
        return 1;
    }

    bool leap = (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));

    if (leap) std::cout << year << " est bissextile\n";
    else std::cout << year << " n'est pas bissextile\n";

    return 0;
}
