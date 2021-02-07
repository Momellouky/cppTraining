/******************************************************************************

given an array of Etudiant:
    LireEtudiant fills up the array of Etudiant ( full name && grade )
    AfficherEtudiant shows up students with grade greater then or equal to 10

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct etu 
{
    char nom[30];
    char prenom[30]; 
    float note; 
}Etudiant;


void lireEtudiant(Etudiant *T, int n)
{
    int i ; 
    
    for ( i = 0; i < n ; i++)
    {
        printf("Le nom: "); 
        scanf("%s", T[i].nom); 
        
        printf("Le prenom: "); 
        scanf("%s", T[i].prenom); 
        
        do{
            printf("La note: "); 
            scanf("%f", &T[i].note); 
        }while(T[i].note > 20 || T[i].note < 0);
    }
}
void AfficherEtudiant(Etudiant *T, int n)
{
    int i ; 
    
    for ( i = 0; i < n ; i++)
    {
        if(T[i].note >= 10 )
            printf("Nom: %s, Prenom: %s \n", T[i].nom, T[i].prenom); 
    }
}

int main()
{   
    int n; 
    Etudiant *T ; 
    
    printf("Donner le nombre n: "); 
    scanf("%d", &n); 
    
    T = (Etudiant*)malloc(sizeof(Etudiant)*n); 
    
    lireEtudiant(T,n); 
    
    AfficherEtudiant(T,n); 
    
    
    
    return 0;
}
