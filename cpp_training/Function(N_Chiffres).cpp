/*
*
* OUTPUT OF THIS PROGRAM
* FOR N = 6574
* N HAS 4 DIGITS 
* SO N_chiffres RETURNS 4
*
*/
/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std; 

int N_chiffres(int n)
{
    int counter = 0, Devision = n;
    
    if(Devision == 0) return 1; 
    
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
    
    cout << N_chiffres(0) << endl; 
    return 0;
}
