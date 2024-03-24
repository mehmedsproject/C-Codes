#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <math.h>

double complex *fft(double complex* x, int N) {
    double complex* X = malloc(N * sizeof(double complex));

    for (int k = 0; k < N; ++k) {
        X[k] = 0.0f;
        for (int n = 0; n < N; ++n) {
            X[k] += x[n] * cexp(-I * 2.0f * M_PI * (double)(k * n) / (double)N);
        }
    }

    return X;
}

complex double* ifft(complex double* X, int N) {
    complex double* x = malloc(N * sizeof(complex double));

    for (int n = 0; n < N; ++n) {
        x[n] = 0.0;
        for (int k = 0; k < N; ++k) {
            x[n] += X[k] * cexp( I * 2.0f * M_PI * (double)(k * n) / (double)N ) * (double)(1/(double)N);
            
//            double angle = -2.0f * M_PI * (double)(k * n / (double)N);
//            x[n] += (X[k] * cexp(I * angle) * (double)(1/(double)N));
        }
    }

    return x;
}

double complex *fftshift(double complex* x, int N) {
    double complex* X = malloc(N * sizeof(double complex));
    
    int shiftAmount = N/2;
    
    // Kaydırma işlemi
    for (int i = 0; i < N; ++i) {
        int newPosition = (i + shiftAmount) % N;
        X[newPosition] = x[i];
    }

    return X;
}

double complex *ifftshift(double complex* X, int N) {
    double complex* x = malloc(N * sizeof(double complex));
    
    int shiftAmount = N/2;
    
    // Kaydırma işlemi
    for (int i = 0; i < N; ++i) {
        int newPosition = (i - shiftAmount + N) % N;
        x[newPosition] = X[i];
    }

    return x;
}


int main() {
    const int N = 8; // Örnek sayısı, 2'nin üssü olmalıdır
    
    double complex* x = malloc(N * sizeof(complex double));
    double complex* X;
    double complex* Xshifted;
    double complex* Xshifted2;
    double complex* x2 = malloc(N * sizeof(complex double));

    // Test fonksiyonunu kullanarak sinyali doldur
    for (int i = 1; i <= N; i++) {
        x[i-1] = sin(2 * M_PI * i / N) + 0.5f * sin(4 * M_PI * i / N) * I;
    }

    // FFT işlemini uygula
    X = fft(x, N);
    // fftshift işlemini uygula
    Xshifted = fftshift(X,N);
    // ifftshift işlemini uygula
    Xshifted2 = ifftshift(Xshifted, N);
    // iFFT işlemini uygula
    x2 = ifft(Xshifted2, N);

    

    // Sonuçları yazdır
    printf("input signal:\n");
    for (int i = 0; i < N; i++) {
        printf("x[%d] = %.4f + %.4fi\n", i, creal(x[i]), cimag(x[i]));
    }
    
    printf("fft of input signal:\n");
    for (int i = 0; i < N; i++) {
        printf("x[%d] = %.4f + %.4fi\n", i, creal(X[i]), cimag(X[i]));
    }
    
    printf("fftshift of fft of input signal:\n");
    for (int i = 0; i < N; i++) {
        printf("x[%d] = %.4f + %.4fi\n", i, creal(Xshifted[i]), cimag(Xshifted[i]));
    }
    
    printf("ifftshift of fftshifted signal:\n");
    for (int i = 0; i < N; i++) {
        printf("x[%d] = %.4f + %.4fi\n", i, creal(Xshifted2[i]), cimag(Xshifted2[i]));
    }
    
    printf("ifft of fft-form of the signal:\n");
    for (int i = 0; i < N; i++) {
        printf("x[%d] = %.4f + %.4fi\n", i, creal(x2[i]), cimag(x2[i]));
    }

    free(X);
    free(x);
    free(Xshifted);
    free(Xshifted2);
    free(x2);

    return 0;
}

/*
Result:
 Columns 1 through 4:

        0 +      0i   2.8284 - 2.8284i   0.0000 + 2.0000i        0 +      0i

 Columns 5 through 8:

        0 +      0i        0 +      0i  -0.0000 + 2.0000i   2.8284 + 2.8284i
        
        y =

 Columns 1 and 2:

  -2.3349e-16 - 1.2246e-16i   2.8284e+00 - 2.8284e+00i

 Columns 3 and 4:

   7.2335e-16 + 2.0000e+00i   1.7432e-32 + 1.7319e-16i

 Columns 5 and 6:

   1.1442e-17 + 1.2246e-16i  -1.7432e-32 + 1.7319e-16i

 Columns 7 and 8:

  -5.0130e-16 + 2.0000e+00i   2.8284e+00 + 2.8284e+00i
*/
