
#include <stdio.h>
#include <stdlib.h>

typedef struct Etu
{
    int CNE; 
    char Nom_etudiant[30]; 
    char Prenom_etudiant[30]; 
    float M1, M2; 
    float MG ; 
    
}Etudiant; 

void Remplir_T(Etudiant *T , int N)
{
    int i; 
    
    for(i = 0; i < N ; i++)
    {
        printf("CNE: "); 
        scanf("%d", &T[i].CNE); 
        
        printf("Nom: "); 
        scanf("%s", T[i].Nom_etudiant); 
        
        printf("Prenom: "); 
        scanf("%s", T[i].Prenom_etudiant); 
        
        printf("Note1: "); 
        scanf("%f", &T[i].M1); 
        
        printf("Note2: ");
        scanf("%f", &T[i].M2); 
        
        T[i].MG = (T[i].M1 + T[i].M2) / 2; 
        
    }
}
int Etudiant_Valider(Etudiant *T, int N)
{
    int i , c = 0; 
    
    for(i = 0; i < N ; i++)
    {
        if(T[i].MG >= 10 )
            c++; 
    }
    
    return c; 
}

void Remplir_T_Valider(Etudiant *T2, Etudiant *T1, int N)
{
    int i, j = 0; 
    
    for( i = 0; i < N; i++)
    {
        if(T1[i].MG >= 10)
        {
            strcpy(T2[j].Nom_etudiant, T1[i].Nom_etudiant);
            strcpy(T2[j].Prenom_etudiant, T1[i].Prenom_etudiant);
            T2[j].M1   = T1[i].M1; 
            T2[j].M2   = T1[i].M2; 
            T2[j].MG   = T1[i].MG; // on peux la calculer. 
            T2[j].CNE = T1[i].CNE; 
            
            j++; 
        }
    }
}

void trie(Etudiant *T , int N)
{
    int i, j, aide, indice_max; 
    
    for(i = 0; i < N ; i++)
    {
        indice_max = i ; 
        
        for( j = i + 1; j < N ; j++)
        {
            if(T[j].MG > T[indice_max].MG)
                indice_max = j; 
        }
        
        if( i != indice_max)
        {
            aide = T[i].MG; 
            T[i].MG = T[indice_max].MG; 
            T[indice_max].MG = aide; 
        }
    }
    
}

void print(Etudiant *T , int N)
{
    int i; 
    
    for(i = 0; i < N; i++)
    {
        printf("| %f ", T[i].MG); 
    }
    printf("\n"); 
    
}

void pourcentage_moyenne(Etudiant *T , int N)
{
     int i;
     float c = 0, pourcentage;  
     
     for(i = 0; i < N ; i++)
     {
           if(T[i].MG >= 12 ) 
                      c++;       
     }
     
     pourcentage = (c / N ) * 100 ;     
     
     printf("Le poucentage : %f", pourcentage ); 
}
int main() {
    
    Etudiant *T, *T_valide; 
    int N ; 
    
    do
    {
        printf("saisir le nombre N: "); 
        scanf("%d", &N); 
    }while( N < 1 && N > 25);
    
    T = (Etudiant*)malloc(sizeof(Etudiant)*N); 
    
    Remplir_T(T,N); 
    
    int nbr_Valide = Etudiant_Valider(T,N); 
    
    T_valide = (Etudiant*)malloc(sizeof(Etudiant)*nbr_Valide); 
    
    Remplir_T_Valider(T_valide, T, N); 
    
    trie(T_valide, nbr_Valide); 
    
    print(T_valide, nbr_Valide); 
    
    pourcentage_moyenne(T,N); 
    
    
    
    
    
    
    system("pause"); 
    return 0;
}
