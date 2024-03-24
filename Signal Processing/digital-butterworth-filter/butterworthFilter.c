#include "butterworthFilter.h"
#include "math.h"

void butterWorth_Init(bwf *bwf, float cutoffFreqHz, float sampleTimeS)
{
	float timeConstant = 1.0f / (2 * M_PI * cutoffFreqHz);

	bwf->coeff[0] = sampleTimeS / (sampleTimeS + timeConstant);
	bwf->coeff[1] = timeConstant / (sampleTimeS + timeConstant);

	bwf->y[0] = 0.0f;
	bwf->y[1] = 0.0f;

}

float butterWorth_update(bwf *bwf, float x)
{
	bwf->y[1] = bwf->y[0];

	bwf->y[0] = bwf->coeff[0] * x + bwf->coeff[1] * bwf->y[1];

	return(bwf->y[0]);
}