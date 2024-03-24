/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Ortalama hesapla
double calculateMean(double *matrix, int rows, int cols) {
    double mean = 0.0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            mean += matrix[i * cols + j];
        }
    }

    return mean / (rows * cols);
}

// Varyans hesapla
double calculateVariance(double *matrix, int rows, int cols, double mean) {
    double variance = 0.0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            variance += pow(matrix[i * cols + j] - mean, 2);
        }
    }

    return variance / ((rows * cols) - 1);
}

int main() {
    int rows, cols;

    printf("Matris boyutunu girin (satır sütun): ");
    scanf("%d %d", &rows, &cols);

    // Matris için bellek tahsisi
    double *matrix = (double *)malloc(rows * cols * sizeof(double));

    printf("Matris elemanlarını girin:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            scanf("%lf", &matrix[i * cols + j]);
        }
    }

    // Ortalama hesapla
    double mean = calculateMean(matrix, rows, cols);

    // Varyans hesapla
    double variance = calculateVariance(matrix, rows, cols, mean);

    // Sonuçları yazdır
    printf("Ortalama: %lf\n", mean);
    printf("Varyans: %lf\n", variance);

    // Belleği serbest bırak
    free(matrix);

    return 0;
}



