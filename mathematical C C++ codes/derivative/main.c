/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include "stdio.h"
#include "derivative.h"

int main()
{
    double x0, h;
    x0 = 1.0; 
    h = 1.0e-6;
    
    // Türevi hesapla
    double result = derive(cos, x0, h);

    // Sonucu yazdır
    printf("Derivative at x = %.2f: %f\n", x0, result);
    return 0;
}
