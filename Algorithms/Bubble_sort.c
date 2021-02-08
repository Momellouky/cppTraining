// bubble sort : tri à bulle
// complexity : O(n^2)
#include <stdio.h>

void bubble_sort(int *T, int N)
{
    int terme_tri = N-2; 
    int ordre, aide, i; 
    // in case of c++, ordre must be boolean. 
    do
    {
        ordre = 1; 
        for(i = 0 ; i < N ; i++)
        {
            if(T[i] > T [i + 1])
            {
                aide = T[i]; 
                T[i] = T[i + 1]; 
                T[i + 1] = aide; 
                ordre = 0; 
            }
            if(ordre == 0)
            {
                terme_tri -= 1; 
            }
        }
    }while(ordre == 0); 
}

void print(int *T, int N)
{
    int i ;
    for(i = 0; i < N; i++)
    {
        printf("| %d", T[i]); 
    }
    printf("\n"); 
}
int main() {
    // Write C code here
    int T[10] = {2,5,4,7,10,6,0,5,55,10} ; 
    
    bubble_sort(T,10);
    
    print(T, 10); 
    
    return 0;
}