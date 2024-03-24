#ifndef SRC_PIDTUNING_
#define SRC_PIDTUNING_

#include <iostream>
#include  "PidTuning.h"

using namespace std;

class IMCController {
private:
    double _Ti, _K, _N, _Td, _T, _L, _lambda, _m, _prevError;

public:
    
    IMCController(double T, double L, double lambda, double m);
    ~IMCController();
    
    double calculateOutput(double error, double prevError, double dt);
    
};

IMC::IMC(double T, double L, double lambda, double m)
{
    imcControl = new IMCController(T, L, lambda, m);
}
IMC::~IMC()
{
    delete imcControl;
}
    
double IMC::calculateOutput(double error, double prevError, double dt)
{
    return imcControl->calculateOutput(error, prevError, dt);
}

IMCController::IMCController(double T, double L, double lambda, double m):
    _Ti(0), 
    _K(0), 
    _N(0), 
    _Td(0), 
    _prevError(0),
    _T(T), 
    _L(L),
    _lambda(lambda), 
    _m(m)
    {

    }
IMCController::~IMCController()
    {
        
    }

double IMCController::calculateOutput(double error, double prevError, double dt) 
    {
        _Ti = _T + (_L * _L) / (2 * (_L + _lambda));
        _K = _Ti / (_m * (_L + _lambda));
        _N = _T * (_L + _lambda) / (_lambda * _Ti) - 1;
        _Td = (_lambda * _L * _N) / (2 * (_L + _lambda));
        
        double P = _K * error;
        double I = prevError + (error * dt) / _Ti;
        double D = (_Td / dt) * (error - prevError);
        
        return P + I + D;
    }

#endif
