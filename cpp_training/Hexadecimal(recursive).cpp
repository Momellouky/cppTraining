/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std; 

int hexa(int n)
{
    if (n == 0) return 0;
    hexa(n / 16);
    if (n % 16 < 10) cout <<  n % 16 ;
    else
    {
        switch (n % 16)
        {

        case 10: cout << "A" ; 
            break;

        case 11: cout << "B";
            break;

        case 12: cout << "C";
            break;


        case 13: cout << "D";
            break;

        case 14: cout << "E";
            break;


        case 15: cout << "F";
            break;

        }
    }

}
int main()
{

    hexa(45);
    return 0;
}
