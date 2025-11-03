#include <iostream>

int main() {
    int n, m;
    std::cout << "Enter two integers (n m): ";
    if (!(std::cin >> n >> m)) {
        std::cerr << "Invalid entry\n";
        return 1;
    }

    std::cout << "Before swap: n = " << n << ", m = " << m << "\n";

    int temp = n;
    n = m;
    m = temp;

    std::cout << "After swap: n = " << n << ", m = " << m << "\n";
    return 0;
}
