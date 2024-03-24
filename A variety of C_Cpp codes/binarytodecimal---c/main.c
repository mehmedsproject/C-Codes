/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
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
