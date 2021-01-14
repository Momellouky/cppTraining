#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
    float T[50],  max, min;
    int i, N, imax, imin; 
    
    do
    {
        printf("Saisir la dimmension réel:\t");
        scanf("%d", &N);
    } while(!(N <= 50 || N > 0));  
    
    for(i = 0; i < N ; i++)
    {
          do
          {
               printf("Saisir T[%d]: \t", i);
               scanf("%f", &T[i]); 
          }while( T[i] == 0 ); 
          
    }
    
    printf("Affichage des valeur: \n"); 
    for(i = 0; i < N ; i++)
    {
          
          printf("%.2f \t", T[i]); 
          
    }
    
    printf("\n"); 
    
    
    // Valeur max et val min, indice max et indice min
    
    
    max = T[0]; 
    min = T[0];
    
    imax = 0; 
    imin = 0; 
    
    
    for(i = 0; i < N ; i++)
    {
          
          if(T[i] > max)
          {
                  max = T[i]; 
                  imax = i; 
          }

          if(T[i] < min)
          {
                  min = T[i]; 
                  imin= i; 
          }  
    
    } 
    
    // affichage   
    
    printf("Le max est %f et son indice est %d", max, imax); 
    
    printf("\n"); 
     
    printf("Le min est %f et son indice est %d \n", min, imin);    
    
    // La somme 
    
    
    float somme = 0; 
     

    for(i = 0; i < N ; i++)
    {
          
          somme += T[i]; 
    
    } 
    
    printf("La somme est %f \n", somme); 
    
    // La moyenne 
    
    float moyenne = somme / N; 
    
    printf("La moyenne %f \n", moyenne); 
    
    
     // La val la plus proche 
     
     
    float Dmin = fabs(T[0] - moyenne);   
    int k = 0; 


    for(i = 0; i < N ; i++)
    {
          
          if(Dmin > fabs(T[i] - moyenne))
          {
                  Dmin = fabs(T[i] - moyenne); 
                  k = i; 
          }

    }   
    
    printf("La valeur plus proche du moyenne est %f \n", T[k]);  
    
    // val la plus loin 
    
    float Dmax = fabs(T[0] - moyenne);   
    int kloin = 0; 


    for(i = 0; i < N ; i++)
    {
          
          if(Dmin < fabs(T[i] - moyenne))
          {
                  Dmax = fabs(T[i] - moyenne); 
                  kloin = i; 
          }

    }   
    
    printf("La valeur plus loin du moyenne est %f \n", T[kloin]);  
       
               
    
    
    system("pause");
    return 0; 
}
