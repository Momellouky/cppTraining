/******************************************************************************

* top <- -1     : stack is empty 
* _STACK_SIZE_ :  the maximum size of our stack
* stack implemented using static array. 

*******************************************************************************/
#include <iostream>

const int _STACK_SIZE_ = 20; 


template <class _data_type_> 
class stack {
    
    int top; 
    _data_type_ element[_STACK_SIZE_]; 
    
    public:
        stack(): top(-1) {}
        
        void push(_data_type_ _element_to_push_)
        {
            if(top >= _STACK_SIZE_) 
                std::cout << "stack full" << std::endl; 
            else
                top++; 
                element[top] = _element_to_push_; 
        }
        
        bool isEmpty()
        {
            return top < 0; 
        }
        _data_type_ pop()
        {
            if(isEmpty())
                std::cout << "stack is empty" << std::endl; 
            else
                top--; 
                
            return element[top + 1]; 
        }
        
        
        void printStack()
        {
            std::cout << "[ " ; 
            for(int i = top; i >= 0; i--)
            {
                std::cout << element[i] << " "; 
            }
            
            std::cout << "]" ; 
            
            std::cout << std::endl; 
        }

} ;

int main()
{
    
    stack<int> s; 
    
    s.push(5); 
    s.push(20);
    s.push(100); 
    
    s.printStack(); 
    
    int poped = s.pop();  // 100 out ( LIFO ) && returned  
    
    s.printStack(); 
    
    std::cout << poped << std::endl; 
    
    

    return 0;
}
