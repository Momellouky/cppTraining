/*
*
* OUTPUT OF THIS PROGRAM
* FOR N = 6574
* N HAS 4 DIGITS 
* SO N_chiffres RETURNS 4
*
*/
#include <iostream>

using namespace std; 

int N_chiffres(int n)
{
    int counter = 0, Devision = n;
    
    while(Devision != 0)
    {
        n = n/10;
        Devision = n; 
        counter++; 
    }
    
    return counter; 
    
}

int main()
{
    
    cout << N_chiffres(393) << endl; 
    return 0;
}
