#define _CRT_SECURE_NO_WARNINGS// Вариант 4
#include <stdio.h>
#include <stdlib.h>
int main() {
	FILE* fileF = fopen("f.txt", "r");
	FILE* fileG = fopen("g.txt", "w");
	if (!fileF) {
		printf("Не удалось открыть файл f\n");
		return 1;
	}
	if (!fileG) {
		printf("Не удалось открыть файл g\n");
		return 1;
	}
	int num;
	printf("Enter number: ");
	scanf("%d", &num);
	int number;
	while (fscanf(fileF, "%d", &number) == 1) {
		if (number > num && number < 100 && number > -100) {
			fprintf(fileG, "%d\n", number);
		}
	}
	fclose(fileF);
	fclose(fileG);
	return 0;
}