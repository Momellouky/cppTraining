/*
Output: 
if the input is a triangular number --> %number is triangular else is not triangular;



 */

#include <iostream>
using namespace std;

int triangulaire(int n) {
    int k = 1, somme = 0;
    for (int conteur = 1; conteur <= n; conteur++) {

        somme += conteur;
        if (somme == n) {
            k = conteur - 1;
            return 1;
        }

    }
    if (somme != n) return 0;
}

int main()
{
    int num1 = 5;
    int r = triangulaire(num1);


    if (r == 1)
        cout << num1 << " is a triangular number." << endl;
    else
        cout << num1 << " is not a triangular number." << endl; 


    return 0;
}
