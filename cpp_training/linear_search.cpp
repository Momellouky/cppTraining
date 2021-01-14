/******************************************************************************

Linear search : 
    search for a number n in an array. 
    time complexity : O(n) ( worst case )
    

    given an array Tab[] = {50,10,20,55,10,3,4,71,103,2,11,45,7}
    search for 10
    
Output: 
    
    the output will be 4 ( index of the last n)
    if n not found linear_search returns -1 

*******************************************************************************/


#include <iostream>

int linear_search(int Arr[], int size, int n)
{
    int result = -1; 
    for(int index = 0; index < size; index++)
    {
        
        if(Arr[index] == n)
            result = index; 
    }
    
    return result;
}


int main()
{
    int Array_elements[13] = {50,10,20,55,10,3,4,71,103,2,11,45,7}; 
    
    int result = linear_search(Array_elements, 13, 10 ); 
    
    std::cout << "result : " << result << std::endl; 

    return 0;
}
