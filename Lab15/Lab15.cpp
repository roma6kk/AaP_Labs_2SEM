#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm> 
#include <chrono>    

using namespace std;
using namespace std::chrono;

vector<int> generateRandomArray(int size) {
    vector<int> arr(size);
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 1000;
    }
    return arr;
}


void moveElements(const vector<int>& A, vector<int>& B) {
    for (int i = 1; i < A.size(); i += 2) {
        if (i + 1 < A.size()) {
            B.push_back(A[i]);
        }
    }
}


void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        if (L[i] >= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Сортировка Хоара (быстрая сортировка)
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] >= pivot) { // Здесь заменяем <= на >= для сортировки по убыванию
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Функция для проверки ввода размера массива
int getValidInput() {
    int size;
    char input[100]; // Буфер для ввода

    while (true) {
        cin.getline(input, 100); // Считываем строку из ввода
        bool validInput = true;
        // Проверяем каждый символ в строке
        for (int i = 0; input[i] != '\0'; ++i) {
            if (!isdigit(input[i])) { // Если символ не является цифрой
                validInput = false; // Ввод неверный
                break;
            }
        }
        if (validInput) { // Если ввод верный, преобразуем строку в число
            size = atoi(input);
            break;
        }
        else {
            cout << "Ошибка: введите число." << endl;
            cout << "Введите размер массива: ";
        }
    }

    return size;
}

int main() {
    setlocale(0, "");
    srand(time(nullptr));

    int size;
    cout << "Введите размер массива: ";
    size = getValidInput();
    vector<int> A = generateRandomArray(size); // Генерируем массив A

    // Выводим массив A
    cout << "Массив A: ";
    for (int num : A) {
        cout << num << " ";
    }
    cout << endl;

    // Создаем массив B и переносим элементы из A
    vector<int> B;
    moveElements(A, B);

    // Выводим массив B до сортировки
    cout << "Массив B до сортировки: ";
    for (int num : B) {
        cout << num << " ";
    }
    cout << endl;

    // Создаем копии массива B для сортировок
    vector<int> B_merge = B;
    vector<int> B_quick = B;

    auto startMergeSort = high_resolution_clock::now(); // Замеряем время начала сортировки слиянием
    mergeSort(B_merge, 0, B_merge.size() - 1); // Сортировка слиянием
    auto stopMergeSort = high_resolution_clock::now(); // Замеряем время завершения сортировки слиянием

    auto startQuickSort = high_resolution_clock::now(); // Замеряем время начала быстрой сортировки
    quickSort(B_quick, 0, B_quick.size() - 1); // Быстрая сортировка (Хоара)
    auto stopQuickSort = high_resolution_clock::now(); // Замеряем время завершения быстрой сортировки

    // Выводим массив B, отсортированный слиянием
    cout << "Отсортированный массив B (сортировкой слиянием): ";
    for (int num : B_merge) {
        cout << num << " ";
    }
    cout << endl;

    // Выводим массив B, отсортированный быстрой сортировкой
    cout << "Отсортированный массив B (сортировкой Хоара): ";
    for (int num : B_quick) {
        cout << num << " ";
    }
    cout << endl;

    auto durationMergeSort = duration_cast<milliseconds>(stopMergeSort - startMergeSort); // Вычисляем время выполнения сортировки слиянием
    auto durationQuickSort = duration_cast<milliseconds>(stopQuickSort - startQuickSort); // Вычисляем время выполнения быстрой сортировки

    cout << "Время выполнения сортировки слиянием для массива размером " << size << ": " << durationMergeSort.count() << " миллисекунд." << endl;
    cout << "Время выполнения быстрой сортировки для массива размером " << size << ": " << durationQuickSort.count() << " миллисекунд." << endl;

    return 0;
}
