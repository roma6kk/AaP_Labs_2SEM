#include<iostream>
using namespace std;
int fmin(int n, ...)
{
	int* p = &n;
	int k = *(++p);
	for (int i = 0; i < n; i++)
	{
		int num = *(++p);
		if (num < k)
			k = num;
	}
	return k;
}
int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "Наименьшее число в последовательности: " << fmin(6, 1, 2, 3, 4, 5, -6) << endl;
	cout << "Наименьшее число в последовательности: " << fmin(8, 1, 2, 3, 4, 5, 6, -1, 2) << endl;
	cout << "Наименьшее число в последовательности: " << fmin(4, 3, 4, 5, 6) << endl;
}