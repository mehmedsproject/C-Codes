/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

void reverse(int n) {
    int reversed = 0;

    while (n != 0) {
        int digit = n % 10; // Son basamağı al
        reversed = reversed * 10 + digit; // Son basamağı ters sayıya ekle
        n /= 10; // Bir basamak sağa kaydır
    }

    printf("Tersi: %d\n", reversed);
}

int main() {
    int num = 789;
    reverse(num); // çıktı: Tersi: 987

    return 0;
}
