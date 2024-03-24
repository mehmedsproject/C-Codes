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

    return variance / (rows * cols);
}

// Covaryans hesapla
double calculateCovariance(double *matrix1, double *matrix2, int rows, int cols, double mean1, double mean2) {
    double covariance = 0.0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            covariance += (matrix1[i * cols + j] - mean1) * (matrix2[i * cols + j] - mean2);
        }
    }

    return covariance / ((rows * cols) -1);
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

    // Varyansları hesapla
    double variance1 = calculateVariance(matrix1, rows, cols, mean1);
    double variance2 = calculateVariance(matrix2, rows, cols, mean2);

    // Covaryansı hesapla
    double covariance = calculateCovariance(matrix1, matrix2, rows, cols, mean1, mean2);

    // Sonuçları yazdır
    printf("Covaryans: %lf\n", covariance);

    // Belleği serbest bırak
    free(matrix1);
    free(matrix2);

    return 0;
}
