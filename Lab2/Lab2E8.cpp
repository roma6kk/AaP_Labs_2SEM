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
	FILE* A, * B, * C, * D;
	A = fopen("A.txt", "r");
	B = fopen("B.txt", "r");
	C = fopen("C.txt", "r");
	char arrA[10], arrB[10], arrC[10];
	int arrD[18];
	fgets(arrA, 10, A); 
	fgets(arrB, 10, B);
	fgets(arrC, 10, C);
	int temp, element;
	D = fopen("D.txt", "w");
	for (int i = 0; i < 4; i++)
	{
		temp = stoi(arrA + i * 2); 
		element = temp;
		cout << element << " ";
		arrD[i] = element;
		fprintf(D, "%d ", arrD[i]); 
		for (int j = i; j < 4; j++)
		{
			temp = stoi(arrB + j * 2);
			element = temp;
			cout << element << " ";
			arrD[j] = element;
			fprintf(D, "%d ", arrD[j]);
			for (int k = i; k < 4; k++)
			{
				temp = stoi(arrC + k * 2);
				element = temp;
				cout << element << " ";
				arrD[k] = element;
				fprintf(D, "%d ", arrD[k]);
				break;
			}
			break;
		}
	}
	fclose(D);
	fclose(A);
	fclose(B);
	fclose(C);
}