/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct etu 
{
    char nom[30];
    float moyenne; 
}Etudiant;


void lireEtudiant(Etudiant *T, int n)
{
    int i ; 
    
    for ( i = 0; i < n ; i++)
    {
        printf("Le nom: "); 
        scanf("%s", T[i].nom); 
        
        do{
            printf("La note: "); 
            scanf("%f", &T[i].moyenne); 
        }while(T[i].moyenne > 20 || T[i].moyenne < 0);
    }
}
void ActualiserMoyenne(Etudiant *T, int n)
{
    int i ; 
    
    for ( i = 0; i < n ; i++)
    {
        if(T[i].moyenne < 10)
            T[i].moyenne += 1; 
        else if((T[i].moyenne >= 10) && (T[i].moyenne) <= 15 )
            T[i].moyenne += 0.5; 
    }
}

int main()
{   
    int n, i; 
    Etudiant *T ; 
    
    printf("Donner le nombre n: "); 
    scanf("%d", &n); 
    
    T = (Etudiant*)malloc(sizeof(Etudiant)*n); 
    
    lireEtudiant(T,n); 
    
    ActualiserMoyenne(T,i); 
    
    for(i = 0; i < n ; i++)
    {
        printf("La moyenne d'etudiant %d: %f \n", i, T[i].moyenne); 
    }
    
    
    system("pause"); 
    return 0;
}
