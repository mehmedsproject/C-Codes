/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
/* Includes */
#include <stdio.h>
/* Private Function Prototypes */	
void swap(int *, int *);
/* Private Global Variables */
int x, y;
/* Private Functions*/
// İki sayının değerlerini değiştiren fonksiyon
void swap(int *a, int *b) {
    // Birinci sayının değerini geçici bir değişkende sakla
    *a = *a + *b;
    // İkinci sayının değerini birinci sayıya ata
    *b = *a - *b;
    // Geçici değişkendeki değeri ikinci sayıya ata
    *a = *a - *b;
}
/* the main() method */ 
// Fonksiyonu main metodu içinde çalıştırmak istersek;
int main() {
    // İki değişkenin değerlerini ata.
    x = 17;
    y = 503;
    // Değişim öncesi değerleri ekrana yazdır
    printf("Önce: x = %d, y = %d\n", x, y); // Önce: x = 5, y = 22

    // swap fonksiyonunu kullanarak iki değişkenin değerlerini değiştir
    swap(&x, &y);

    // Değişim sonrası değerleri ekrana yazdır
    printf("Sonra: x = %d, y = %d\n", x, y); // Sonra: x = 22, y = 5

    return 0;
}


