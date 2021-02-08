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
    
    printf("\n"); 
}

int panne_materielle(smartphone *T, int n)
{
    int i,c = 0; 
    
    for(i = 0; i < n; i++)
    {
        if(T[i].type_panne.panne == 1)
            c++; 
    }
    
    return c; 
}
void trie(smartphone *T, int N)
{
    int i, j, indice_min, aide; 
    
    for(i = 0; i < N ; i++)
    {
        indice_min = i; 
        
        for(j = i +1; j < N; j++)
        {
            if(T[j].type.model < T[indice_min].type.model)
                indice_min = j; 
        }
        
        if( i != indice_min)
        {
            aide = T[i].type.model; 
            T[i].type.model = T[indice_min].type.model; 
            T[indice_min].type.model = aide; 
        }
    }
}

void print(smartphone *T, int N)
{
    int i; 
    
    for( i = 0; i < N ; i++)
    {
        printf("| %d ", T[i].type.model);
    }
    
    printf("\n"); 
}
int main() {
    
    smartphone *T ; 
    int N ; 
    
    printf("Saisir N: "); 
    scanf("%d", &N); 
    
    T = (smartphone*)malloc(sizeof(smartphone)*N); 
    
    saisir_Tableau(T,N); 
    
    Afficher(T[0], N); 
    
    trie(T, N); 
    
    print(T, N); // not required 
    
    int panne = panne_materielle(T, N); 
    
    printf("Les smartphones avec panne materielle: %d", panne); 
    
    system("pause"); 
    return 0;
}
