#include<iostream>
using namespace std;
int mn(int n, ...)
{
	int* p = &n;
	int k = *(++p);
	for (int i = 1; i < n; i++)
	{
		if (*(++p) > k)
			k = *p;
	}
	return k;
}
int main()
{
	setlocale(0, "rus");
	cout << "������������ �����: " << mn(6, 1, 2, 3, 4, 5, 6) << endl;
	cout << "������������ �����: " << mn(7, 22, 2, 3, 4, 5, 6, 1) << endl;
	cout << "������������ �����: " << mn(8, 9, 1, 2, 33, 4, 5, 6, 0) << endl;
}