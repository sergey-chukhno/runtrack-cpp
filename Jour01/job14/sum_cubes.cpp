#include <iostream>
#include <cstdint>

int main() {
    long long N;
    std::cout << "Entrez un entier N: ";
    if (!(std::cin >> N)) {
        std::cerr << "Entrée invalide\n";
        return 1;
    }
    if (N < 5) {
        std::cout << "N < 5, somme = 0\n";
        return 0;
    }

    // somme des cubes de 5^3 à N^3
    // utilisation de la formule: sum_{k=1..n} k^3 = (n(n+1)/2)^2
    auto sum_cubes_to = [](long long x) -> __int128 {
        __int128 t = (__int128)x * (__int128)(x + 1) / 2;
        return t * t;
    };

    __int128 total = sum_cubes_to(N) - sum_cubes_to(4);

    // afficher __int128
    if (total == 0) { std::cout << "Somme = 0\n"; return 0; }
    __int128 tmp = total;
    bool neg = tmp < 0;
    if (neg) tmp = -tmp;
    std::string s;
    while (tmp > 0) {
        int digit = (int)(tmp % 10);
        s.push_back('0' + digit);
        tmp /= 10;
    }
    if (s.empty()) s = "0";
    if (neg) s.push_back('-');
    std::reverse(s.begin(), s.end());
    std::cout << "Somme = " << s << "\n";
    return 0;
}
