#include <iostream>
#include <limits>

// find_min takes an array of pointers to int and its size, returns the smallest value
int find_min(int* arr[], size_t n) {
    if (n == 0 || arr == nullptr) return std::numeric_limits<int>::max();
    int min = *arr[0];
    for (size_t i = 1; i < n; ++i) {
        if (*arr[i] < min) min = *arr[i];
    }
    return min;
}

int main() {
    int a = 10, b = -3, c = 25, d = 7, e = -1, f = 0;
    int* ptrs[] = { &a, &b, &c, &d, &e, &f };
    size_t n = sizeof(ptrs) / sizeof(ptrs[0]);
    int m = find_min(ptrs, n);
    std::cout << "Min = " << m << "\n";
    return 0;
}
