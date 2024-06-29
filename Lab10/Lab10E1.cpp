#include"Header.h"
int main() {
    setlocale(0, "rus");
    int m, n, choice, result1, result2;
    do {
        cout << "1. Задание 1" << endl;
        cout << "2. Задание 2" << endl;
        if (!(cin >> choice) || cin.get() != '\n')
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Ошибка ввода" << endl;
            continue;
        }
        switch (choice)
        {
        case 1: {
            cout << "Введите число m: " << endl;
            if (!(cin >> m) || cin.get() != '\n') {
                cout << "Ошибка ввода" << endl;
                cin.clear();
                cin.ignore(32767, '\n');
                continue;
            }

            cout << "Введите число n: " << endl;
            if (!(cin >> n) || cin.get() != '\n') {
                cout << "Ошибка ввода" << endl;
                cin.clear();
                cin.ignore(32767, '\n');
                continue;
            }
            if (n < 1) {
                cout << "Число n не может быть меньше 1" << endl;
                continue;
            }
            cout << "Количество разбиений: " << CountXM(m, n) << endl;
            break; }
        case 2:
        {
            cout << "Введите значение n: ";
            if (!(cin >> n) || cin.get() != '\n') {
                cout << "Ошибка ввода" << endl;
                cin.clear();
                cin.ignore(32767, '\n');
                continue;
            }
            if (n < 1)              
            {
                cout << "Значение n не может быть меньше 1" << endl;
                continue;   
            }
            cout << "Результат выражения: " << Calculate(n, 1) << endl;

            break;
        }
        default:
            cout << "Ошибка ввода" << endl;
        }
    } while (true);

    return 0;
}