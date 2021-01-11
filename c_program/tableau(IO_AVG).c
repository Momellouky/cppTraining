
#include <stdio.h>
 

void saisisTableau(float tab[], float dimension)
{
    int i; // iterateur; 
    
    for(i = 0; i < dimension; i++)
    {
        printf("Saisis le %deme nombre: \t", i); 
        scanf("%f", &tab[i]); 
    }
}

void affichertableau(float tab[], float dimension)
{
    int i;
    
    for(i = 0; i < dimension; i++)
    {
        printf("%.2f \n", tab[i]); 
    }
}

void valeurMax(float tab[], float dim)
{
    int i, indice  = 0; 
    float max = tab[0];
    
    for(i = 1; i < dim; i++)
    {
        if(max < tab[i])
        {
            max = tab[i]; 
            indice = i; 
        }    
    }
    
    printf("La valeur maximal est %.2f \n", max); 
    
    printf("L'indice de la valeur maximal est %d \n", indice); 
}

void valeurMin(float tab[], float dim)
{
    int i, indice  = 0; 
    float min = tab[0];
    
    for(i = 1; i < dim; i++)
    {
        if(min > tab[i])
        {
            min = tab[i]; 
            indice = i; 
        }    
    }
    
    printf("La valeur minimale est %.2f \n", min); 
    
    printf("L'indice de la valeur minimale est %d \n", indice);
}

float moyenneTableau(float tab[], float dim)
{
    int i;
    float moyenne, somme = tab[0]; 
    
    for(i = 1; i < dim; i++)
    {
        somme += tab[i]; 
    }
    
    moyenne = somme / dim; 
    
    return moyenne; 
}


int main()
{
    float N; // dimenssion du tableau. 
    
    do
    {
        printf("Entrer la dimension du tableau: \t"); 
        scanf("%f", &N); 
    } while(!((N <= 50) || (N != 0))); 
    
    
    
    float tableau[(int)N]; 
    
    saisisTableau(tableau, N); 
    
    affichertableau(tableau, N); 
    
    valeurMax(tableau, N); 

    valeurMin(tableau, N); 
    
    float moyenne = moyenneTableau(tableau, N); 
    
    printf("La moyenne du tableau est %.2f", moyenne); 


    return 0;
}
