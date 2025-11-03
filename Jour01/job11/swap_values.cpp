#include <iostream>

void swapValues(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int main() {
    int x = 3, y = 7;
    std::cout << "Avant: x = " << x << ", y = " << y << "\n";
    swapValues(x, y);
    std::cout << "Après: x = " << x << ", y = " << y << "\n";
    return 0;
}
