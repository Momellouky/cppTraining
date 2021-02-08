// Selection sort ( tri par selection)

#include <stdio.h>

void selection_sort(int *arr, int n)
{
    int i, j, indice_min, temp; 
    
    for( i = 0; i < n; i++)
    {
        indice_min = i ;
        
        for( j = i +1; j < n; j++)
        {
            if(arr[j] < arr[indice_min])
                indice_min = j ; 
        }
        
        if( i != indice_min)
        {
            temp = arr[i]; 
            arr[i] = arr[indice_min]; 
            arr[indice_min] = temp; 
        }
    }
}

void print(int *arr, int N)
{
    int i; 
    
    for( i = 0; i < N; i++)
    {
        printf("| %d ", arr[i]); 
    }
    printf("\n"); 
}

int main() {
    
    int arr[10] = {5,4,8,10,6,7,11, 20, 7, 0}; 
    
    selection_sort(arr,10); 
    
    print(arr, 10); 

    return 0;
}