#include <iostream>
#include <cstdint>

// Retourne 1 si le nombre de bits à 1 est pair, 0 sinon.
// Utilise uniquement des opérations bitwise (pas d'opérateurs de comparaison).
int even_popcount_bitwise(uint32_t x) {
    // Parity can be computed by xor-folding the bits down to a single bit.
    x ^= x >> 16;
    x ^= x >> 8;
    x ^= x >> 4;
    x ^= x >> 2;
    x ^= x >> 1;
    // Now x & 1 is 1 if popcount is odd, 0 if even.
    // We want to return 1 for even, 0 for odd. So return (x & 1) ^ 1
    return (x & 1) ^ 1;
}

int main() {
    uint32_t tests[] = {42u, 0u, 7u, 0xFFFFFFFFu, 0xAAAAAAAAu};
    for (uint32_t t : tests) {
        std::cout << t << " -> even popcount? " << (even_popcount_bitwise(t) ? "true" : "false") << "\n";
    }
    return 0;
}
