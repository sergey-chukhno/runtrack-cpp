#include <iostream>
#include <limits>

int main() {
    long long n;
    std::cout << "Entrez un entier: ";
    if (!(std::cin >> n)) {
        std::cerr << "Entrée invalide\n";
        return 1;
    }

    bool negative = n < 0;
    unsigned long long x = negative ? static_cast<unsigned long long>(-n) : static_cast<unsigned long long>(n);

    unsigned long long rev = 0;
    while (x > 0) {
        rev = rev * 10 + (x % 10);
        x /= 10;
    }

    if (negative) std::cout << "Inversé: -" << rev << "\n";
    else std::cout << "Inversé: " << rev << "\n";
    return 0;
}
