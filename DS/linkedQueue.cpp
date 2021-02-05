#include <iostream>

template <class TYPE>
class queue
{
	struct node 
	{
		TYPE value; 
		node *next; 
	};

	node *front; 
	node *rear; 

	int count;// queue is empty

public: 

	queue() // constructor 
	{
		front =  NULL;
		rear = NULL;  
		count = 0; 
	}

	bool isempty()
	{
		return count == 0; 
	}

	void enqueue(TYPE element)
	{
		
		if(isempty()) // front and rear point to the same node.  
		{
			front = new node; 
			front->value = element; 
			front->next = NULL; 

			rear = front; 
		} 
		else
		{
			node *newElemenet = new node; 

			newElemenet->value = element; 
			newElemenet->next = NULL; 

			rear->next = newElemenet; 

			rear = newElemenet; 
		}

		count++; 
	}

	TYPE dequeue() // return poped value
	{
		TYPE value; 
		if(isempty())
			std::cout << "queue is empty. " << std::endl; 
		else
		{
			node *temp = new node; 
			temp = front;
			value = temp->value; 

			front = front->next; 

			delete temp;  

		}

		count--;

		return value;  
	}

	TYPE getfront()
	{
		if(isempty())
		{
			std::cout << "queue is empty." << std::endl;
			return -1; // even if queue of an other type
					  //  -1 mean front doesn't exist ( queue is empty).
		}
		else
			return front->value; 
	}

	TYPE getRear()
	{
		if(isempty())
		{
			std::cout << "queue is empty." << std::endl;
			return -1; // even if queue of an other type
					  //  -1 mean rear doesn't exist ( queue is empty).
		}
		else
			return rear->value; 
	}

	void display()
	{
		node *temp = front ; 
		while(temp != NULL)
		{
			std::cout << temp->value << " "; 
			temp = temp->next; 
		}

		std::cout << std::endl; 

		delete temp; 
	}

};

int main(void)
{	

	queue<int> q; 

	q.enqueue(20); 
	q.enqueue(30); 
	q.enqueue(40); 

	int front = q.getfront(); 

	int rear = q.getRear(); 

	std::cout << "front: " << front << std::endl
		      << "rear:  " << rear << std::endl; 

	q.display(); 

	q.dequeue(); 

	q.display(); 

	return 0; 
}