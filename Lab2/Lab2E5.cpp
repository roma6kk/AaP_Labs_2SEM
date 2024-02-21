#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // Вариант 6
#include <stdlib.h>
#include <math.h>
#include<Windows.h>
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    FILE* fileA = fopen("fA.txt", "r");
    if (!fileA) {
        printf("Не удалось открыть файл fA\n");
        return 1;
    }
    double numbers[100];
    int numNumbers = 0;
    double number;
    while (fscanf(fileA, "%lf", &number) == 1) {
        numbers[numNumbers] = number;
        numNumbers++;
    }
    fclose(fileA);
    int target;
    printf("Введите целое число: ");
    scanf("%d", &target);

    double closest = numbers[0];
    int closestIndex = 0;
    double diff = fabs(target - closest);
    for (int i = 1; i < numNumbers; i++) {
        double newDiff = fabs(target - numbers[i]);
        if (newDiff < diff) {
            closest = numbers[i];
            closestIndex = i;
            diff = newDiff;
        }
    }
    printf("Число %lf наиболее близко к %d и имеет порядковый номер %d\n", closest, target, closestIndex + 1);
    return 0;
}
