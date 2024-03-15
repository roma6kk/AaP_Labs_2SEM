#include <iostream>
#include <Windows.h>

using namespace std;

void funSum(int a, int n, int m, int* first, ...) {
    int** p = reinterpret_cast<int**>(&first);
    for (int k = 0; k < a; k++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (j < i) {
                    sum += **p;
                }
                ++(*p);
            }
        }
        cout << sum << '\n';
        p++;
    }
    cout << '\n';
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int a[5][5];
    cout << "Матрица A:" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            a[i][j] = rand() % 100 + 1;
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }

    int b[5][5];
    cout << "Матрица B:" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            b[i][j] = rand() % 100 + 1;
            cout << b[i][j] << ' ';
        }
        cout << '\n';
    }

    int c[5][5];
    cout << "Матрица C:" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            c[i][j] = rand() % 100 + 1;
            cout << c[i][j] << ' ';
        }
        cout << '\n';
    }

    int d[5][5];
    cout << "Матрица D:" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            d[i][j] = rand() % 100 + 1;
            cout << d[i][j] << ' ';
        }
        cout << '\n';
    }

    cout << "вызов функции 1: " << endl;
    funSum(2, 5, 5, (int*)a, (int*)b);

    cout << "вызов функции 2: " << endl;
    funSum(3, 5, 5, (int*)d, (int*)c, (int*)a);

    cout << "вызов функции 3: " << endl;
    funSum(1, 5, 5, (int*)d);

    return 0;
}