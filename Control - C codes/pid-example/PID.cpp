#ifndef SRC_PID_
#define SRC_PID_

#include <iostream>
#include <cmath>
#include "PID.h"

using namespace std;

class Pid
{
    public:
        Pid(double dt, double max, double min, double Kp, double Ki, double Kd);
        ~Pid();
        double calculate(double setpoint, double var);
        
    private:
        double _dt;
        double _max;
        double _min;
        double _Kp;
        double _Ki;
        double _Kd;
        double _prev_error;
        double _integral;
        
};

PID::PID(double dt, double max, double min, double Kp, double Ki, double Kd)
{
    applyPid = new Pid(dt, max, min, Kp, Ki, Kd);
}

double PID::calculate(double setpoint, double var)
{
    return applyPid->calculate(setpoint, var);
}
PID::~PID()
{
    delete applyPid;
}

/* Application of PID */

Pid::Pid(double dt, double max, double min, double Kp, double Ki, double Kd) :
    _dt(dt),
    _max(max),
    _min(min),
    _Kp(Kp),
    _Ki(Kd),
    _Kd(Ki),
    _prev_error(0),
    _integral(0)
{
    
}

double Pid::calculate(double setpoint, double var)
{
    
    // Calculate error
    double error = setpoint - var;
    
    // Proportional term
    double pOut = _Kp * error;
    
    // Integral term
    _integral += error * _dt;
    double iOut = _Ki * _integral;

    // Derivative term
    double derivative = (error - _prev_error) / _dt;
    double dOut = _Kd * derivative;

    // Calculate total output
    double output = pOut + iOut + dOut;

    // Restrict to max/min
    if( output > _max )
        output = _max;
    else if( output < _min )
        output = _min;

    // Save error to previous error
    _prev_error = error;

    return output;
}

Pid::~Pid()
{
    
}

#endif