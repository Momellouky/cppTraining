#include <iostream>
#include <cassert>



const int SIZE = 50;
template <class type>
class queue
{
	int front, rear, count; 
	type arr[SIZE]; // to store queue elements. 

public:
	queue()
	{
		front = -1; 
		rear  = -1;
		count = 0;  // empty queue.  
	}

	bool empty()
	{
		return count == 0; // no element were added
	}

	bool full()
	{
		return count == SIZE - 1; 
	}

	void enQueue(type element)
	{
		if(full())
			std::cout << "Queue is full!" << std::endl;
		else if( count == 0) // if queue is empty. 
		{
			rear = 0;
			front = 0; 
			arr[rear] = element; 
			count++;
		}
		else
		{
			rear = (rear + 1 ) % SIZE;
			arr[rear] = element; 
			count++;	
		}

		

	}

	type deQueue()
	{
		if(empty())
			std::cout << "Queue is empty!" << std::endl;
		else
		{
			front = (front + 1) % SIZE;
			count--;
		}

		return arr[--front]; 
	}

	type search(type element)
	{

		int position = -1, i = front, index = -1; 

		for(i = front ; i != rear; i = (i + 1)% SIZE)
		{

			index++;

			if(arr[i] == element)
			{
				position = index; 
				break;  // return the first occurence
			}
		}

		if(position == -1) // 
		{
			if(arr[i] == element) // arr[i] <-- is the last element 
				{
					position = ++index; 
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

		if(!empty())
			return arr[front]; 
		else
			return -1; 
	}

	int getRear()
	{

		if(!empty())
			return arr[rear]; 
		else
			return -1;

	}


};

int main()
{

	queue<int> myq; 

	myq.enQueue(20); 
	myq.enQueue(50);
	myq.enQueue(60);
	myq.enQueue(100);

	int front = myq.getFront(); 

	std::cout << "front: " << front << std::endl; 

	int rear = myq.getRear(); 

	std::cout << "rear: " << rear << std::endl; 

	myq.display(); 

	myq.deQueue(); 
	myq.deQueue();

	myq.display(); 

	int pos = myq.search(100);

	std::cout << pos << std::endl; 

	return 0;
}