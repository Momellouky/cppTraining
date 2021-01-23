/******************************************************************************

* top <- -1     : stack is empty 
* _STACK_SIZE_ :  the maximum size of our stack
* stack implemented using static array. 

*******************************************************************************/
#include <iostream>

const int _STACK_SIZE_ = 20; 

class stack {
    
    int top; 
    int element[_STACK_SIZE_]; 
    
    public:
        stack(): top(-1) {}
        
        void push(int _element_to_push_)
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
        void pop()
        {
            if(isEmpty())
                std::cout << "stack is empty" << std::endl; 
            else
                top--; 
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
    
    stack s; 
    
    s.push(5); 
    s.push(20);
    s.push(100); 
    
    s.printStack(); 
    
    s.pop();  // 100 out ( LIFO ) 
    
    s.printStack(); 
    
    
    

    return 0;
}
