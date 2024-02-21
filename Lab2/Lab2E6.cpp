#define _CRT_SECURE_NO_WARNINGS
#define MAX_LENGTH 1000
#include <stdio.h>// Вариант 6
#include <stdlib.h>
#include <iostream>
int main() {
	setlocale(LC_ALL, "Russian");
	FILE* file1 = fopen("f1.txt", "r");
	FILE* file2 = fopen("f2.txt", "w");
	if (!file1) {
		printf("Не удалось открыть файл F1\n");
		return 1;
	}
	if (!file2) {
		printf("Не удалось открыть файл F2\n");
		return 1;
	}
	char line[MAX_LENGTH];
	int lineNumber = 1;
	while (fgets(line, MAX_LENGTH, file1)) {
		if (lineNumber % 2 == 0) {
			fprintf(file2, "%s", line);
		}
		lineNumber++;
	}
	fclose(file1);
	fclose(file2);
	return 0;
}