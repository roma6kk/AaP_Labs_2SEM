#define _CRT_SECURE_NO_WARNINGS// Вариант 4
#include <stdio.h>

int main() {
    FILE* fileA = fopen("fileA.txt", "r");
    FILE* fileB = fopen("fileB.txt", "w");

    if (fileA == NULL || fileB == NULL) {
        printf("Ошибка открытия файла.\n");
        return 1;
    }

    int number;
    while (fscanf(fileA, "%d", &number) == 1) {
        if (number > 0) {
            fprintf(fileB, "%d ", number);
        }
    }

    fclose(fileA);
    fclose(fileB);

    return 0;
}