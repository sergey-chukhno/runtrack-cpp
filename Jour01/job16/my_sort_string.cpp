#include <iostream>
#include <string>

// Tri par sélection utilisant des pointeurs sur tableau de std::string
void MySortString(std::string* arr, size_t n) {
    for (size_t i = 0; i + 1 < n; ++i) {
        std::string* minp = &arr[i];
        for (size_t j = i + 1; j < n; ++j) {
            std::string* cur = &arr[j];
            if (*cur < *minp) minp = cur;
        }
        if (minp != &arr[i]) {
            std::string tmp = arr[i];
            arr[i] = *minp;
            *minp = tmp;
        }
    }
}

int main() {
    std::string arr[] = {"orange", "apple", "banana", "grape", "kiwi"};
    size_t n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Avant tri:\n";
    for (size_t i = 0; i < n; ++i) std::cout << arr[i] << (i + 1 < n ? ", " : "\n");

    MySortString(arr, n);

    std::cout << "Après tri:\n";
    for (size_t i = 0; i < n; ++i) std::cout << arr[i] << (i + 1 < n ? ", " : "\n");
    return 0;
}
