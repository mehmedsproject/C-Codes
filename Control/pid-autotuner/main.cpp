
#include <iostream>
#include "PID.h"
#include "PidTuning.h"
#include <stdio.h>

using namespace std;

int main()
{
    PID pid = PID(0.1, 100, -100, 0.1, 0.01, 0.5);

    double val = 20;
    for (int i = 0; i < 100; i++) {
        double inc = pid.calculate(0, val);
        printf("val:% 7.3f inc:% 7.3f\n", val, inc);
        //std::cout << val << " " << inc << std::endl;
        val += inc;
    }
    

    IMC imc = IMC(1.0, 2.0, 0.5, 1.0);

    // Kontrol edilecek hedef değer
    double setpoint = 10.0;

    // Zaman adımı
    double dt = 0.1;

    // Başlangıç hata değeri
    double error = setpoint;
    double prevError = 0.0;

    // Belirli bir süre boyunca kontrolcüyü güncelle
     printf("\n IMC output \n\n");
    for (int i = 0; i < 100; ++i) {
        double controlOutput = imc.calculateOutput(error, prevError, dt);
        //std::cout  << controlOutput << "," << std::endl;
        printf("% 7.3f, \n" , controlOutput);
        // Hata ve önceki hata değerlerini güncelle
        prevError = error;
        error = setpoint - controlOutput;

        // Zaman adımını bekleyin
        // Burada zaman adımı boyunca süreç dinamikleri simüle edilebilir.
    }
}
