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

// Çapraz Korelasyon hesapla
double calculateCrossCorrelation(double *matrix1, double *matrix2, int rows, int cols, double mean1, double mean2) {
    double crossCorrelation = 0.0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            crossCorrelation += (matrix1[i * cols + j] - mean1) * (matrix2[i * cols + j] - mean2);
        }
    }

    return crossCorrelation / (rows * cols);
}

// Otokorelasyon hesapla
double calculateAutoCorrelation(double *matrix, int rows, int cols, double mean) {
    double autoCorrelation = 0.0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            autoCorrelation += (matrix[i * cols + j] - mean) * (matrix[i * cols + j] - mean);
        }
    }

    return autoCorrelation / (rows * cols);
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

    // Çapraz Korelasyonu hesapla
    double crossCorrelation = calculateCrossCorrelation(matrix1, matrix2, rows, cols, mean1, mean2);

    // Otokorelasyonları hesapla
    double autoCorrelation1 = calculateAutoCorrelation(matrix1, rows, cols, mean1);
    double autoCorrelation2 = calculateAutoCorrelation(matrix2, rows, cols, mean2);

    // Sonuçları yazdır
    printf("Çapraz Korelasyon: %lf\n", crossCorrelation);
    printf("Otokorelasyon (Matris 1): %lf\n", autoCorrelation1);
    printf("Otokorelasyon (Matris 2): %lf\n", autoCorrelation2);

    // Belleği serbest bırak
    free(matrix1);
    free(matrix2);

    return 0;
}
