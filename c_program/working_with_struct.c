/******************************************************************************

Gestion d'une base de donnée d'inscription pour l'organisation d'un congès qui dure une journée

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct Participant
{
    char nom[25], prenom[25]; 
    
    char repas[30]; 
    
    int hotel; // int ( 2 etoiles ou 3 etoiles ) 0 non hotel. 
    
    int conjoint; // 0 seul, 1 avec conjoint 
    
}Participant; 

void Nb_2Etoiles(Participant *Tab)
{
    int i = 0; 
    
    for(i = 0; i < 100 ; i++)
    {
        if(Tab[i].hotel == 2)
            printf("%s %s \t", Tab[i].nom, Tab[i].prenom); 
    }
}

int Nb_Dej(Participant *Tab)
{
    int i = 0, conteur = 0; 
    
    for(i = 0; i < 100; i++)
    {
        if( (!strcmp(Tab[i].repas, "Dejeuner") || !strcmp(Tab[i].repas, "Diner")) )
        {
            if(Tab[i].conjoint == 1) 
                conteur += 2; 
            else
                conteur++; 
        }
            
    }
    
    return conteur; 
}

float Montant(Participant Tab)
{
    float total = 0; 
    
    if(!strcmp(Tab.repas, "Dejeuner"))
        total += 80; 
    else if(!strcmp(Tab.repas, "Diner"))
        total += 150; 
    
    if(Tab.conjoint == 1)
        total *= 2;
        
    if(Tab.hotel == 2)
        total += 300; 
    else if(Tab.hotel == 3)
        total += 500; 
        
 
        
    return total; 
}

int main()
{

    Participant Tab_Part[100];
    
    strcpy(Tab_Part[0].nom, "Mohamed");
    strcpy(Tab_Part[0].prenom, "Mellouky");
    strcpy(Tab_Part[0].repas, "Dejeuner");
    Tab_Part[0].hotel = 2; 

    
    strcpy(Tab_Part[1].nom, "Mohamed");
    strcpy(Tab_Part[1].prenom, "Amlouky"); 
    strcpy(Tab_Part[1].repas, "Dejeuner");
    Tab_Part[1].hotel = 2; 
    
    strcpy(Tab_Part[2].nom, "Mohamed");
    strcpy(Tab_Part[2].prenom, "test");
    strcpy(Tab_Part[2].repas, "Diner");
    Tab_Part[2].conjoint = 1; // true 
    Tab_Part[2].hotel = 3; 
    
    Nb_2Etoiles(Tab_Part); 
    int dejNbr = Nb_Dej(Tab_Part); 
    printf("LE nbr de dejeuner est %d", dejNbr); 
    
    float M2 = Montant(Tab_Part[2]); 
    
    printf("Le montant à payer: %.2f", M2 ); 
    
    
    return 0;
}
