// Online C compiler to run C program online
#include <stdio.h>

int main() {
    // Write C code here
    int v_zero = 2, v;
    int i, N, s = 0; 
    printf("Donner N: "); 
    scanf("%d", &N); 
    
    for(i = 1; i <= N ; i++)
    {
        if( i % 2 != 0)
        {
            v = v_zero + 4;
            v_zero = v; 
        }
        else
        {
            v = v_zero + 2; 
            v_zero = v ; 
        }
        
        s += v; 
    }
    
    printf("Result : %d", s); 
    return 0;
}