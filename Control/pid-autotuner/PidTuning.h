#ifndef INC_PIDTUNING_H_
#define INC_PIDTUNING_H_

class IMCController;
class IMC {
private:
    IMCController *imcControl;

public:
    
    IMC(double T, double L, double lambda, double m);
    ~IMC();
    
    double calculateOutput(double error, double prevError, double dt);
    
};

#endif /* INC_PIDTUNING_H_ */