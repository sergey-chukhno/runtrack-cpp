#include <iostream>
#include <iomanip>

int main() {
    int x;            // variable pour la saisie courante
    int sum = 0;      // accumulateur

    std::cout << "Please enter five integeres separated by space :\n";

    for (int i = 0; i < 5; ++i) {
        if (!(std::cin >> x)) {
            std::cerr << "Invalid entry\n";
            return 1;
        }
        sum += x;
    }

    double average = static_cast<double>(sum) / 5.0;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Average is: " << average << "\n";
    return 0;
}
