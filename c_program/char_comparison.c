/******************************************************************************

* given two arrays of character.
* if char1 is bigger then char2: compare fuction resturs 1
* if char2 is less then char2 :  compare function returns -1; 
* if char1 == char2 : compare function returns 0
*
*

*******************************************************************************/
#include <stdio.h>



int compare(char *ch1, char* ch2)
{
    int i = 0 ; 
    
    while(ch1[i] != '\0' && ch2[i] != '\0')
    {
        if(ch1[i] != ch2[i]) break;
        i++; 
    }
    
    if(ch1[i] > ch2[i]) 
        return 1; 
    else
        if(ch1[i] < ch2[i])
            return -1; 
        else
            return 0; 
    

}
int main()
{
    char name[25] = "Mohamed Mellouky"; 
    char lname[25] = "Mohamed"; 
    
    
    int result = compare(name, lname); 
    
    printf("result = %d", result); 
    
    system("pause");
    return 0;
}
