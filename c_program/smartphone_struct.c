#include <stdio.h>
#include <stdlib.h>

typedef struct telephone
{
    char Marque[30]; 
    int model; 
}Type_Telephone; 

typedef struct panne
{
    int panne; 
}Type_de_panne; 

typedef struct sm{
    int Id_client; 
    Type_Telephone type; 
    Type_de_panne type_panne; 
}smartphone;

void saisir_Tableau(smartphone *T, int N)
{
    int i; 
    
    for(i = 0; i < N ; i++)
    {
        printf("ID: "); 
        scanf("%d", &T[i].Id_client); 
        
        printf("Marque: "); 
        scanf("%s", T[i].type.Marque); 
        
        printf("model: "); 
        scanf("%d", &T[i].type.model); 
        
        printf("Type de panne: "); 
        scanf("%d", &T[i].type_panne.panne); 
    }
}

void Afficher(smartphone T, int n)
{
    printf("Id_client: %d   Type de panne: %d", 
            T.Id_client, T.type_panne.panne); 
}
int main() {
    
    smartphone *T ; 
    int N ; 
    
    printf("Saisir N: "); 
    scanf("%d", &N); 
    
    T = (smartphone*)malloc(sizeof(smartphone)*N); 
    
    saisir_Tableau(T,N); 
    
    Afficher(T[0], N); 
    
    return 0;
}