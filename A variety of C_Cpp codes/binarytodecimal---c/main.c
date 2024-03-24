#include <stdio.h>

void binary_to_decimal(int n) {
    int decimal = 0;
    int base = 1;

    while (n > 0) {
        int last_digit = n % 10; // Son basamağı al
        n /= 10; // Bir basamak sağa kaydır
        decimal += last_digit * base; // Son basamağı onluk sayıya ekle
        base *= 2; // Temel sayıyı artır
    }

    printf("Onluk karşılığı: %d\n", decimal);
}

int main() {
    int binary_number = 10011011;
    binary_to_decimal(binary_number); // çıktı: Onluk karşılığı: 155

    return 0;
}
