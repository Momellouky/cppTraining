#include <stdio.h>
#include <stdlib.h>

void  Max_Min(int* a, int* b)
{
     // cette fonction ne traite pas le cas de *a == *b   
     
    // soit a le max 
    
    if ( *a < *b ) 
        printf("%d est le max et %d est le min", *b , *a); 
    
    else
        printf("%d est le max et %d est le min", *a, *b); 
     
   
        
}
int main()
{
    int *num1 , *num2 ; 
    
    // résérver la mémoire 
    
    num1 = (int*)malloc(sizeof(int)); 
    num2 = (int*)malloc(sizeof(int));
    
    // saisir la valeur des deux entiers. 
    
    printf("saisir la valeur des deux entiers \t"); 
    scanf("%d%d", num1, num2); 
    
    // appeller la fonction Max_Min(int *a, int *b)
    
    Max_Min(num1, num2); 
    
    
    return 0;
}
