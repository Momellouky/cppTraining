/******************************************************************************

SEARCHING ALGORITHM 
BINARY SEARCH

COMPLEXITY : O(logn)

OUTPUT 
       IF N IS IN THE ARRAY 
       binary_search FUNCTION RETURNS THE INDEX OF N 
       ELSE
       binary_search RETURNS -1

*******************************************************************************/
#include <iostream>

using namespace std; 

int binary_search(int Array[], int size, int key)
{
    int high = size - 1; 
    int low = 0; 
    
    int mid = ( high + low) / 2; 
    
    while(high >= low)
    {
        if(Array[mid] == key) 
            return mid ;
        
        if(Array[mid] < key)
        {
            low = mid + 1;
        }
        
        if(Array[mid] > key)
        {
            high = mid - 1; 
        }
        
        mid = ( high + low ) / 2;
        
    }
    
    return -1;
}
int main()
{
    
    int Tab[10] = {2,4,7,10,66,80,102,1666};
    
    int result = binary_search(Tab, 10, 102); 
    
    cout << result << endl; 
    return 0;
}
