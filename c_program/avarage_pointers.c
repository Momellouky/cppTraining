
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *N , *nbr , *somme, *produit; 
    float *moyenne; 
    
    // variable pour les boucles. 
    
    int i; 
    
    // réservation de memoire 
    
    N           = (int*)malloc(sizeof(int)); 
    nbr         = (int*)malloc(sizeof(int));  
    somme       = (int*)malloc(sizeof(int)); 
    produit     = (int*)malloc(sizeof(int)); 
    
    moyenne     = (float*)malloc(sizeof(float)); 
    
    printf("Entrer le nombre d'entier: \t"); 
    scanf("%d", N); 
    
    // initialisation 
    
    *somme = 0; 
    *produit = 1; 
    
    for(i = 1; i <= *N ; i++)
    {
        printf("Entrer le nombre %d \t", i  ); 
        scanf("%d", nbr); 
        
        *somme += *nbr ; 
        *produit *= *nbr; 
        
    }
    
    *moyenne =  (float)(*somme)/(*N) ; 
    
    printf("La moyenne des notes est %.2f", *moyenne); 
    
    

    return 0;
}
