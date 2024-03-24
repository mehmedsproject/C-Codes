#ifndef INC_PID_H_
#define INC_PID_H_

class Pid;
class PID
{
    public:
        // Kp -  proportional gain
        // Ki -  Integral gain
        // Kd -  derivative gain
        // dt -  loop interval time
        // max - maximum value of manipulated variable
        // min - minimum value of manipulated variable
        PID( double dt, double max, double min, double Kp, double Ki, double Kd );

        // Returns the manipulated variable given a setpoint and current process value
        double calculate( double setpoint, double var );
        ~PID();

    private:
        Pid *applyPid;
};

#endif