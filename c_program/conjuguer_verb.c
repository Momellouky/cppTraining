// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct terminaisons
{
    char ter[4]; 
}terminaisons;

typedef struct v_conjugue
{
    char v_conj[15];
}v_conjugue; 

v_conjugue V[6]; 

terminaisons termi[6] = {"ai", "as", "a", "ons", "ez", "ont"};

void conjuguer(char *Verb)
{
    int i ;
    char aide[15];  
    
    for(i = 0; i < 6; i++)
    {
        strcpy(aide, Verb);
        //strcpy(aide, "\0");  
        strcat(aide, termi[i].ter); 
        strcpy(V[i].v_conj, aide); 
    }
}

void print(char *t)
{
    int i = 0; 
    
    for( i = 0 ; i < 6 ; i++)
    {
        printf("%s \n", V[i].v_conj); 
    }
}
int main() {
    char verb[15];
    int Len; 
    
    printf("Saisir le verbe: "); 
    scanf("%s", verb); 
    
    Len = strlen(verb);
    
    if(verb[Len - 1] == 'r' && verb[Len - 2] == 'e')
        conjuguer(verb); 
        
    print(verb); 

    return 0;
}
