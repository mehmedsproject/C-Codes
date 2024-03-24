/******************************************************************************

*******************************************************************************/
#include <iostream>

using namespace std;

// Recursive Fonksiyon : fibonacci örneği

// 1 1 2 3 5 8 13 21 ...
int fibonacci(int step)
{
    if(step == 0) { return 0; }
    if(step == 1) { return 1; }
    if(step == 2) { return 1; }
    
    return fibonacci(step - 1) + fibonacci(step - 2);
}

int main()
{
    cout<<fibonacci(7)<<endl;
    cout<<fibonacci(4)<<endl;
    

    return 0;
}

