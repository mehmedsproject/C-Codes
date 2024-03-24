/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

// Recursive Fonksiyon : faktöriyel örneği
int faktoriyel(int sayi)
{
    if(sayi == 1) { return sayi;}
    
    return sayi * faktoriyel(sayi - 1);
}

int main()
{
    cout<<faktoriyel(5)<<endl;

    return 0;
}
