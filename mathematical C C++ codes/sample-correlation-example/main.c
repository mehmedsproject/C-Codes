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

// Standart sapma hesapla
double calculateStandardDeviation(double *matrix, int rows, int cols, double mean) {
    double variance = 0.0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            variance += pow(matrix[i * cols + j] - mean, 2);
        }
    }

    return sqrt(variance / ((rows * cols)-1));
}

// Korelasyon hesapla
double calculateCorrelation(double *matrix1, double *matrix2, int rows, int cols, double mean1, double mean2, double sd1, double sd2) {
    double correlation = 0.0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            correlation += ((matrix1[i * cols + j] - mean1) / sd1) * ((matrix2[i * cols + j] - mean2) / sd2);
        }
    }

    return correlation / ((rows * cols)-1);
}

int main() {
    int rows, cols;

    printf("Matris boyutunu girin (satır sütun): ");
    scanf("%d %d", &rows, &cols);

    // Matrisler için bellek tahsisi
    double *matrix1 = (double *)malloc(rows * cols * sizeof(double));
    double *matrix2 = (double *)malloc(rows * cols * sizeof(double));

    printf("İlk matris elemanlarını girin:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            scanf("%lf", &matrix1[i * cols + j]);
        }
    }

    printf("İkinci matris elemanlarını girin:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            scanf("%lf", &matrix2[i * cols + j]);
        }
    }

    // Ortalamaları hesapla
    double mean1 = calculateMean(matrix1, rows, cols);
    double mean2 = calculateMean(matrix2, rows, cols);

    // Standart sapmaları hesapla
    double sd1 = calculateStandardDeviation(matrix1, rows, cols, mean1);
    double sd2 = calculateStandardDeviation(matrix2, rows, cols, mean2);

    // Korelasyonu hesapla
    double correlation = calculateCorrelation(matrix1, matrix2, rows, cols, mean1, mean2, sd1, sd2);

    // Sonuçları yazdır
    printf("Korelasyon: %lf\n", correlation);

    // Belleği serbest bırak
    free(matrix1);
    free(matrix2);

    return 0;
}
