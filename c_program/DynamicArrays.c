#include <stdio.h>
#include <stdlib.h>

void saisie_tableau(int *Tableau, int taille)
{
    int i = 0; 
    
    for(i = 0; i < taille; i++)
    {
        printf("Saisir %deme valeur du tableau: \t", i);
        scanf("%d", &Tableau[i]); 
    }
}

void afficher_tableau(int *Tableau, int taille)
{
    int i = 0; 
    
    for(i = 0; i < taille; i++)
    {
        printf("%d \t", Tableau[i]);  
    }
}

int trouver_V(int *Tableau, int taille, int V)
{
    int i = 0 ; 
    
    for(i = 0; i < taille; i++)
    {
        if(Tableau[i] == V)
            return i; 
    }
    
    return -1; 
}

void afficher_nombre_occurences(int *Tableau, int taille, int V)
{
    int i = 0, nbr_occurence = 0 ; 
    
    printf("Les indices des occurrences sont: "); 
    for(i = 0; i < taille; i++)
    {
        if(Tableau[i] == V)
        {
            printf("%d, ", i); 
            nbr_occurence++; 
        }
             
    }
    
    printf("\nLe nombre d'occurrence de %d est %d", V, nbr_occurence); 
}

int main()
{
    int *T , N, V; 
    
    do
    {
        printf("Saisir la dimension du tableau: \t"); 
        scanf("%d", &N); 
    }while(N <= 0); 
    
    T = (int*)malloc(sizeof(int) * N);
    
    printf("Saisir le nombre V: \t"); 
    scanf("%d", &V);
    
    saisie_tableau(T,N); 
    
    afficher_tableau(T,N); 
    
    int indice_de_V = trouver_V(T, N, V); 
    
    printf("\nL'indice de %d est %d\n",V,  indice_de_V);
    
    afficher_nombre_occurences(T, N, V); 
    
    
    
    

    return 0;
}
