#include <iostream>

int doubleArray(int* arr, size_t n) {
    int sum = 0;
    int* p = arr;
    for (size_t i = 0; i < n; ++i) {
        *p = (*p) * 2;
        sum += *p;
        ++p;
    }
    return sum;
}

void printArray(int* arr, size_t n) {
    int* p = arr;
    for (size_t i = 0; i < n; ++i) {
        std::cout << *p;
        if (i + 1 < n) std::cout << " ";
        ++p;
    }
    std::cout << "\n";
}

int main() {
    int data[] = {1, 2, 3, 4, 5};
    size_t n = sizeof(data) / sizeof(data[0]);

    std::cout << "Avant: "; printArray(data, n);
    int sum = doubleArray(data, n);
    std::cout << "Après doublage: "; printArray(data, n);
    std::cout << "Somme des éléments doublés: " << sum << "\n";
    return 0;
}
