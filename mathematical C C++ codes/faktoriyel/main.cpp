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
