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
