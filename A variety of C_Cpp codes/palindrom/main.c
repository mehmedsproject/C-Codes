#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

void boolpalindrome(char *); // Fonksiyon prototipi

void boolpalindrome(char *s) {
    int length = strlen(s);
    int i, j;

    for (i = 0, j = length - 1; i < j; i++, j--) {
        // Boşluk karakterlerini atlayarak ilerle
        for (; i < length && isspace(s[i]); i++);
        for (; j >= 0 && isspace(s[j]); j--);

        // Karakterleri karşılaştır
        if (tolower(s[i]) != tolower(s[j])) {
            printf("\"%s\" palindrom değil\n", s);
            return;
        }
    }

    printf("\"%s\" palindromdur.\n", s);
}

int main() {
    char str1[] = "ey edip adanada pide ye";
    char str2[] = "zamki cok o cikmaz";
    char str3[] = "Hello world";

    boolpalindrome(str1);
    boolpalindrome(str2);
    boolpalindrome(str3);

    return 0;
}
