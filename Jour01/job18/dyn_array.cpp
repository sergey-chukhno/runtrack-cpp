#include <iostream>
#include <cstddef>

// Alloue un nouveau tableau de taille currentSize+1, copie les éléments,
// ajoute value à la fin, libère l'ancien tableau et retourne le nouveau pointeur.
int* addElement(int* arr, std::size_t currentSize, int value) {
    int* newArr = new int[currentSize + 1];
    for (std::size_t i = 0; i < currentSize; ++i) {
        newArr[i] = arr[i];
    }
    newArr[currentSize] = value;
    // libérer l'ancien tableau
    delete[] arr;
    return newArr;
}

// Affiche les éléments du tableau
void showTable(int* arr, std::size_t size) {
    std::cout << "Table (size=" << size << "): ";
    for (std::size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << (i + 1 < size ? ", " : "\n");
    }
}

int main() {
    // Capacité initiale = 5 (tableau alloué), mais taille actuelle = 0
    std::size_t capacity = 5;
    int* table = new int[capacity];
    std::size_t size = 0;

    // Ajouter plusieurs entiers via addElement
    int toAdd[] = {10, 20, 30, 40, 50, 60, 70};
    std::size_t nAdd = sizeof(toAdd) / sizeof(toAdd[0]);

    for (std::size_t i = 0; i < nAdd; ++i) {
        table = addElement(table, size, toAdd[i]);
        ++size;
    }

    // Afficher le tableau
    showTable(table, size);

    // Nettoyage
    delete[] table;
    return 0;
}
