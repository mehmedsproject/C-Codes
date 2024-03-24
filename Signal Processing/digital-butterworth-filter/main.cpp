#include <iostream>

#include "butterworthFilter.h"

using namespace std;

bwf bwf1;

float *data, *dataFiltered;
int dataSize = 100;

int main()
{
    data = (float*) malloc(sizeof(float) * (dataSize + 1));
    dataFiltered = (float*) malloc(sizeof(float) * (dataSize + 1));
    butterWorth_Init(&bwf1, 450.0f, 0.0005f);
    float *ptr;
    
    for(int i = 0; i < dataSize; i++)
    {
        *(data + i) = i;
        

        *(dataFiltered + i) = butterWorth_update(&bwf1, *(data + i));
    
        cout << *(data+i) << " ";
        cout << *(dataFiltered+i) << endl;
    }
    
    free(data);
    free(dataFiltered);
    
    return 0;
}
