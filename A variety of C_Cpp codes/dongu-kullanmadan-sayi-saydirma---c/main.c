#include <stdio.h>

void print_without_loop(int n) {
    if (n > 0) {
        print_without_loop(n - 1); // n-1'den başlayarak fonksiyonu tekrar çağır
        printf("%d ", n); // n'i yazdır
    }
}

int main() {
    int num = 10;
    print_without_loop(num); // çıktı: 1 2 3 4 5 6 7 8 9 10
    printf("\n");

    return 0;
}
