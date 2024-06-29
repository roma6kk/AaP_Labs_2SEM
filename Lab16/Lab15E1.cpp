#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] < arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int n;
    std::cout << "Введите размер массива: ";
    std::cin >> n;

    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::vector<int> arrA(n);
    std::cout << "Массив A (случайные числа): ";
    for (int i = 0; i < n; ++i) {
        arrA[i] = std::rand() % 100; // Генерация случайных чисел от 0 до 99
        std::cout << arrA[i] << " ";
    }
    std::cout << std::endl;

    // Создание массива B с элементами, имеющими четные индексы из массива A
    std::vector<int> arrB;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) { // Проверка на четность индекса
            arrB.push_back(arrA[i]);
        }
    }

    // Вывод массива B на экран
    std::cout << "Массив B (с элементами с четными индексами): ";
    for (int num : arrB) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Сортировка массива B методом пузырька
    std::vector<int> arrB_bubble = arrB; // Копия массива B для сортировки пузырьком
    std::clock_t startBubbleSort = std::clock();
    bubbleSort(arrB_bubble);
    std::clock_t endBubbleSort = std::clock();

    // Вывод отсортированного массива B методом пузырька на экран
    std::cout << "Отсортированный массив B (пузырек): ";
    for (int num : arrB_bubble) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Сортировка массива B методом простой вставки
    std::vector<int> arrB_insertion = arrB; // Копия массива B для сортировки простой вставкой
    std::clock_t startInsertionSort = std::clock();
    insertionSort(arrB_insertion);
    std::clock_t endInsertionSort = std::clock();

    // Вывод отсортированного массива B методом простой вставки на экран
    std::cout << "Отсортированный массив B (сортировка простой вставкой): ";
    for (int num : arrB_insertion) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Вычисление времени выполнения сортировок
    double timeBubbleSort = static_cast<double>(endBubbleSort - startBubbleSort) / CLOCKS_PER_SEC;
    double timeInsertionSort = static_cast<double>(endInsertionSort - startInsertionSort) / CLOCKS_PER_SEC;

    // Вывод времени выполнения сортировок на экран
    std::cout << "Время сортировки пузырьком: " << timeBubbleSort << " сек" << std::endl;
    std::cout << "Время сортировки простой вставкой: " << timeInsertionSort << " сек" << std::endl;

    return 0;
}
