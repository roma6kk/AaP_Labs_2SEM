#include <iostream>// Вариант 1
#include <fstream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	ifstream fileF("f.txt");
	ofstream fileG("g.txt");
	if (!fileF.is_open()) {
		cout << "Не удалось открыть файл f" << endl;
		return 1;
	}
	if (!fileG.is_open()) {
		cout << "Не удалось открыть файл g" << endl;
		return 1;
	}
	int k;
	cout << "Введите число K: ";
	cin >> k;
	int number;
	while (fileF >> number) {
		if (number % k != 0) {
			continue;
		}
		fileG << number << " ";
	}
	fileF.close();
	fileG.close();
	return 0;
}
