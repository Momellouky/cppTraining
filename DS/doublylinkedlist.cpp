#include <iostream>

class DoublyLinkedList
{
	struct node
	{
		int item;
		node *next;
		node *prev; 
	};

	int lenght; 
	node *head; 
	node *tail; 

	int is_empty()
	{
		if(lenght == 0) return 1;  
		return 0; 
	}
public: 

	DoublyLinkedList()
	{
		lenght = 0;
		head = tail = NULL;   
	}

	void insert_first(int element)
	{
		node *new_node = new node; 
		new_node->item = element; 
		if(is_empty() == 1 )
		{
			head = tail = new_node; 
			new_node->next = NULL;
			new_node->prev = NULL; 
			lenght++; 
		}
		else
		{
			new_node->next = head; 
			new_node->prev = NULL; 
			head->prev = new_node; 
			head = new_node; 
			lenght++; 
		}
	}

	void insert_last(int element)
	{
		node *new_node = new node; 
		new_node->item = element; 
		if(is_empty() == 1 )
		{
			head = tail = new_node; 
			new_node->next = NULL;
			new_node->prev = NULL; 
			lenght++; 
		}
		else
		{
			new_node->next = NULL; 
			new_node->prev = tail; 
			tail->next = new_node; 
			tail = new_node; 
			lenght++; 
		}
	}

	void insertAt(int pos, int element)
	{
		if(pos < 0 || pos > lenght)
			std::cout << "out of range" << std::endl; 

		if(pos == 0) insert_first(element); 
		else if(pos == lenght - 1) insert_last(element); 
		else
		{
			node *cur, *new_node = new node ; 
			new_node->item = element; 
			cur = head->next; 
			for(int i = 1; i < pos; i++)
			{
				cur = cur->next; 
			}

			new_node->next = cur; 
			new_node->prev = cur->prev; 
			cur->prev->next = new_node; 
			cur->prev = new_node ; 
			lenght++; 
		}
	}

	void remove_first()
	{
		if(is_empty() == 1)
			std::cout << "list empty : nothing to remove" << std::endl;

		else if(lenght == 1)
		{
			delete head; 
			head = tail = NULL;
			lenght--;  
		} 
		else
		{
			node *cur = head; 
			head = head->next; 
			head->prev = NULL; 
			delete cur; 
			lenght--; 
		}
	}

	void remove_last()
	{
		if(is_empty() == 1)
			std::cout << "list empty : nothing to remove" << std::endl;

		else if(lenght == 1)
		{
			delete head; 
			head = tail = NULL;
			lenght--;  
		} 
		else
		{
			node *cur = tail;
			tail = tail->prev; 
			tail->next = NULL; 
			delete cur; 
			lenght--;  

		}
	}

	void remove_element(int element)
	{
		if(is_empty() == 1)
			std::cout << "list empty : nothing to remove" << std::endl;
		else if(head->item == element)
			remove_first(); 
		else if(tail->item == element)
			remove_last(); 
		else
		{
			node *cur = head->next; 
			while(cur != NULL)
			{ 
				if(cur->item == element)
					break;

				cur = cur->next;

			}

			if(cur == NULL)
				std::cout << "element not found" << std::endl; 
			else
			{
				cur->prev->next = cur->next ; 
				cur->next->prev = cur->prev; 
				delete cur; 
				lenght--;
			}
 
		}
	}

	void print()
	{
		node *cur = head; 
		while(cur != NULL)
		{
			std::cout << cur->item << " " ; 
			cur = cur->next; 
		}


	}

};

int main()
{
	DoublyLinkedList dl; 

	dl.insert_first(20); 
	dl.insert_last(10); 
	dl.insert_last(50);
	dl.insert_last(30);
	dl.insert_last(33);
	dl.insert_last(420);
	dl.insertAt(2,55); 

	dl.remove_last(); 
	dl.remove_first(); 
	dl.remove_element(50); 


	dl.print(); 
	return 0;
}