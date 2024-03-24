#ifndef INC_BUUTERWORTHFILTER_H_
#define INC_BUUTERWORTHFILTER_H_

typedef struct{
	float coeff[2];
	float y[2];
}bwf;

void butterWorth_Init(bwf *bwf, float cutoffFreqHz, float sampleTimeS);
float butterWorth_update(bwf *bwf, float x);


#endif /* INC_BUUTERWORTHFILTER_H_ */