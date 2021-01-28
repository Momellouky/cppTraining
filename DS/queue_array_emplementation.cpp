#include <iostream>

const int SIZE = 50;
template <class type>
class queue
{
	int front, rear, count; 
	type arr[SIZE]; // to store queue elements. 

public:
	queue()
	{
		front = 0;
		rear  = -1;
		count = 0;   
	}

	bool empty()
	{
		return count == 0; // no element were added
	}

	bool full()
	{
		return count == SIZE -1; 
	}

	void enQueue(type element)
	{
		if(full())
			std::cout << "Queue is full!" << std::endl;
		else
		{
			rear = (rear + 1 ) % SIZE; 
			arr[rear] = element; 
		}
	}

	void diQueue()
	{
		if(empty())
			std::cout << "Queue is empty!" << std::endl;
		else
		{
			front = (front + 1) % SIZE;
		}
	}

	type search(type element)
	{

		int position = -1, i = front; 

		for(i = front ; i != rear; i = (i + 1)% SIZE)
		{
			if(arr[i] == element)
			{
				position = i; 
				break;  // return the first occurence
			}
		}

		if(position == -1)
		{
			if(arr[i] == element)
				{
					position = i; 
				}
		}

		return position ; 

	}
	void display()
	{

		int i = front;

		for(i = front ; i != rear; i = (i + 1)% SIZE)
		{
			std::cout << arr[i] << " " ;
		}

		std::cout << arr[i] ;
		std::cout << std::endl; 

	}

	int getFront()
	{

		assert(empty());
		return front; 

	}

	int getRear()
	{

		assert(empty()); 
		return rear;

	}


};

int main()
{

	queue<int> myq; 

	myq.enQueue(20); 
	myq.enQueue(50); 

	myq.display(); 

	return 0;
}