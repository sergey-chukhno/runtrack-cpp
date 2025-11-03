#include <iostream>
#include <cstdint>
#include <array>

// constexpr Fibonacci computed at compile time
constexpr uint64_t fibonacci(size_t n) {
    return (n <= 1) ? n : (fibonacci(n - 1) + fibonacci(n - 2));
}

// constexpr popcount parity for uint32_t: returns true if number of set bits is even
constexpr bool even_popcount(uint32_t x) {
    // Kernighan's algorithm in constexpr-friendly form
    uint32_t cnt = 0;
    while (x) {
        x &= (x - 1);
        ++cnt;
    }
    return (cnt % 2) == 0;
}

constexpr std::array<uint64_t, 10> fib_array() {
    std::array<uint64_t, 10> a = {};
    for (size_t i = 0; i < a.size(); ++i) a[i] = fibonacci(i);
    return a;
}

int main() {
    std::cout << "Les 10 premiers termes de Fibonacci:\n";
    constexpr auto fibs = fib_array();
    for (size_t i = 0; i < fibs.size(); ++i) {
        std::cout << fibs[i] << (i + 1 < fibs.size() ? ", " : "\n");
    }

    // Tests pour even_popcount
    uint32_t test_vals[] = {0u, 1u, 3u, 0xF0F0F0F0u, 0xFFFFFFFFu};
    for (uint32_t v : test_vals) {
        std::cout << v << " -> popcount parity even? " << (even_popcount(v) ? "true" : "false") << "\n";
    }
    return 0;
}
