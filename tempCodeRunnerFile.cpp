#include <iostream>

// Функция для разделения массива
int partition(float arr[], int low, int high) {
    float pivot = arr[high]; // Используем последний элемент как опорный
    int i = low - 1; // Индекс меньшего элемента

    for (int j = low; j <= high - 1; ++j) {
        if (arr[j] >= pivot) { // Сортировка по убыванию
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Рекурсивная функция быстрой сортировки
void quickSort(float arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Разделить массив на две части

        // Рекурсивно сортируем подмассивы
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    const int size = 15;
    float numbers[size];

    std::cout << "Enter 15 floating-point numbers:\n";
    for (int i = 0; i < size; ++i) {
        std::cin >> numbers[i];
    }

    quickSort(numbers, 0, size - 1);

    std::cout << "Sorted numbers (from largest to smallest):\n";
    for (int i = 0; i < size; ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
