#include<iostream>
using namespace std;

int fsum(int n, ...)
{
	int* p = &n;
	int sum = 0;
	int num = *(++p);
	for (int i = 1; i < n; i++)
	{
		sum += (num * *(++p));
		num = *p;
	}
	return sum;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "Значение, вычисленное по формуле: " << fsum(5, 1, 2, 3, 4, 5) << endl;
	cout << "Значение, вычисленное по формуле: " << fsum(6, 1, 2, 3, 4, 5, 6) << endl;
	cout << "Значение, вычисленное по формуле: " << fsum(7, 1, 2, 3, 4, 5, 6, 7) << endl;
}