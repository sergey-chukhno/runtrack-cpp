#include <iostream>

int main() {
    long long n;
    std::cout << "Enter an integer: ";
    if (!(std::cin >> n)) {
        std::cerr << "Invalid entry\n";
        return 1;
    }
    if (n % 2 == 0) {
        std::cout << n << " is pair\n";
    } else {
        std::cout << n << " is impair\n";
    }
    return 0;
}
