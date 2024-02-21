#include<iostream>// Вариант 8
using namespace std;
int mn(int n, ...)
{
	int* p = &n;
	int num = *(++p);
	for (int i = 0; i < n; i++)
	{
		if (*(++p) < num)
			num = *p;
	}
	return num;
}
int main()
{
	setlocale(0, "rus");
	cout << "Минимальное число из последовательности: " << mn(6, 1, 2, 3, 4, 5, 6) << endl;
	cout << "Минимальное число из последовательности: " << mn(8, 1, -2, 3, 4, 6, 5, 7, 8) << endl;
	cout << "Минимальное число из последовательности: " << mn(10, 1, 2, 3, 4, -5, 6, 7, 8, 9, 10) << endl;
}