#include <iostream>

template<class _class_type_>

class Stack
{
	struct node
	{
		_class_type_ item; 
		node *next; 
	};

	node *top ; 
public:

	Stack()
	{
		top = NULL; 
	}

	void push(_class_type_ newItem)
	{

		node *item_to_push = new node; 

		if(item_to_push == NULL)
			std::cout << "memory allocation failed" ; 
		else
		{
			item_to_push->item = newItem; 
			item_to_push->next = top;
			top = item_to_push; 			
		}

	}

	bool is_empty()
	{

		return top == NULL; 
	}

	void pop()  
	{

		if( is_empty() )
		{
			std::cout << "Empty stack"; 
		}
		else
		{
			node *temp = top; 
			top = top->next; 
			temp = temp->next = NULL; 
			delete temp; 
		}

	}

	void pop(_class_type_& returnValue) // return poped value 
	{

		if( is_empty())
		{
			std::cout << "Empty stack"; 
		}
		else
		{
			node *temp = top; 
			returnValue = temp->item; 
			top = top->next; 
			temp->next = NULL; 
			delete temp; 
		}

	}

	_class_type_ getTop()
	{
		if(is_empty())
			std::cout << "stack is empty"; 
		else
		{
			return top->item; 
		}
	}

	void display()
	{
		node *temp = top; 
		std::cout << "[ "; 
		while(temp != NULL)
		{
			std::cout << temp->item << " "; 
			temp = temp->next; 
		}
		std::cout << " ]";

		delete temp;  
	}
};

int main()
{
	Stack<int> myStack; 

	myStack.push(20);
	myStack.push(150);
	myStack.push(300); 

	myStack.display(); 

	myStack.pop(); 

	myStack.display(); 

	myStack.pop(); 
	myStack.pop(); 

	myStack.display(); 

	myStack.pop();

	return 0; 
}