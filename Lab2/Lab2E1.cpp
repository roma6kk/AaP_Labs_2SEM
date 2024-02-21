#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
    char filenameA[] = "fA.txt";
    char filenameB[] = "fB.txt";
    char filenameC[] = "fC.txt";
    FILE* fileA = fopen(filenameA, "r");
    if (fileA == NULL) {
        printf("Не удалось открыть файл %s\n", filenameA);
        return 1;
    }
    int num_colsA;
    fscanf(fileA, "%d", &num_colsA);
    int num_rowsA = 0;
    double* matrixA = NULL;
    double value;
    while (fscanf(fileA, "%lf", &value) == 1) {
        num_rowsA++;
        matrixA = (double*)realloc(matrixA, num_rowsA * num_colsA * sizeof(double));
        matrixA[(num_rowsA - 1) * num_colsA] = value;
        for (int j = 1; j < num_colsA; j++) {
            if (fscanf(fileA, "%lf", &value) != 1) {
                printf("Некорректный формат файла %s\n", filenameA);
                free(matrixA);
                return 1;
            }
            matrixA[(num_rowsA - 1) * num_colsA + j] = value;
        }
    }
    fclose(fileA);
    FILE* fileB = fopen(filenameB, "r");
    if (fileB == NULL) {
        printf("Не удалось открыть файл %s\n", filenameB);
        free(matrixA);
        return 1;
    }
    int num_colsB;
    fscanf(fileB, "%d", &num_colsB);
    int num_rowsB = 0;
    double* matrixB = NULL;
    while (fscanf(fileB, "%lf", &value) == 1) {
        num_rowsB++;
        matrixB = (double*)realloc(matrixB, num_rowsB * num_colsB * sizeof(double));
        matrixB[(num_rowsB - 1) * num_colsB] = value;
        for (int j = 1; j < num_colsB; j++) {
            if (fscanf(fileB, "%lf", &value) != 1) {
                printf("Некорректный формат файла %s\n", filenameB);
                free(matrixA);
                free(matrixB);
                return 1;
            }
            matrixB[(num_rowsB - 1) * num_colsB + j] = value;
        }
    }
    fclose(fileB);
    if (num_colsA != num_rowsB) {
        printf("Невозможно перемножить матрицы\n");
        free(matrixA);
        free(matrixB);
        return 0;
    }
    int num_rowsC = num_rowsA;
    int num_colsC = num_colsB;
    double* matrixC = (double*)calloc(num_rowsC * num_colsC, sizeof(double));
    for (int i = 0; i < num_rowsC; i++) {
        for (int j = 0; j < num_colsC; j++) {
            for (int k = 0; k < num_colsA; k++) {
                matrixC[i * num_colsC + j] += matrixA[i * num_colsA + k] * matrixB[k * num_colsB + j];
            }
        }
    }
    FILE* fileC = fopen(filenameC, "w");

    if (fileC == NULL) {
        printf("Не удалось открыть файл %s\n", filenameC);
        return 1;
    }
    for (int i = 0; i < num_rowsA; i++) {
        for (int j = 0; j < num_colsB; j++) {
            fprintf(fileC, "%.2lf ", matrixC[i * num_colsB + j]);
        }
        fprintf(fileC, "\n");
    }
}
