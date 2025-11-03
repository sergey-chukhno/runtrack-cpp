#include <iostream>

int find_min(int* arr, size_t n) {
    if (n == 0 || arr == nullptr) {
        // Comportement indéfini théoriquement; ici on renvoie INT_MAX comme signal d'erreur
        return std::numeric_limits<int>::max();
    }
    int* p = arr; 
    int min = *p;
    for (size_t i = 1; i < n; ++i) {
        ++p;
        if (*p < min) min = *p;
    }
    return min;
}

int main() {
    int data[] = { 10, -3, 25, 7, -1, 0, 4 };
    size_t n = sizeof(data) / sizeof(data[0]);
    int m = find_min(data, n);
    std::cout << "Min = " << m << "\n";
    return 0;
}
