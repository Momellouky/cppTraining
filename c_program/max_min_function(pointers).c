
#include <stdio.h>
#include <stdlib.h>

void  Max_Min(int a, int b, int *max , int *min)
{
      
    *max = a; 
    *min = a;
    // si b le max 
    
    if ( *max < b ) 
    {    
        *max = b;       
    }   
    if(*min > b)
            *min = b; 
    
     
     
   
        
}
void main()
{
    int a, b;
    int  max, min; 
    
    // saisir la valeur des deux entiers. 
    
    printf("saisir la valeur des deux entiers \t"); 
    scanf("%d%d", &a, &b); 
    
    // soit a le max  
    
 
    
    // appeller la fonction Max_Min(int *a, int *b) pour verifier l'hypothese
    
    Max_Min(a, b, &max, &min);
    
    // afficher les resultats.  
    
    printf("le nombre max est: %d et le nombre min est %d \n", max, min);
    
    
    system("pause"); 
    
    
}
