#define _CRT_SECURE_NO_WARNINGS// Вариант 7
#include <iostream>
#include <stdio.h>
#include <sstream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	FILE* NameA, * NameB, * NameC, * NameD;
	NameA = fopen("NameA.txt", "r");
	NameB = fopen("NameB.txt", "r");
	NameC = fopen("NameC.txt", "r");
	char arrA[10], arrB[10], arrC[10];
	int arrD[4];
	fgets(arrA, 10, NameA);
	fgets(arrB, 10, NameB);
	fgets(arrC, 10, NameC);
	int temp;
	int max_el;
	NameD = fopen("NameD.txt", "w");
	for (int i = 0; i < 4; i++)
	{
		temp = max(stoi(arrA + i * 2), stoi(arrB + i * 2));
		max_el = max(temp, stoi(arrC + i * 2));
		cout << max_el << " ";
		arrD[i] = max_el;
		fprintf(NameD, "%d ", arrD[i]);
	}
	fclose(NameD);
	fclose(NameA);
	fclose(NameB);
	fclose(NameC);
}