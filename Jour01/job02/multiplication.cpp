#include <iostream>

int main() {
    int a, b;
    std::cout << "Enter two integers: ";
    if (!(std::cin >> a >> b)) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    int result = a * b;
    std::cout << "The multiplication of " << a << " and " << b << " is " << result << "\n";
    return 0;
}
