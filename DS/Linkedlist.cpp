#include <iostream>

class Linkedlist
{
	struct node
	{
		int item; 
		node *next; 
	};

	node *head; 
	node *tail; 
	int lenght; 

	public:

	Linkedlist()
	{
		head = tail = NULL; 
		lenght = 0; 
	}

	// inertion
	// from the start

	void insert_form_start(int element)
	{
		node *new_node = new node;
		new_node->item = element; 

		if(lenght == 0)
		{
			head= tail = new_node; 
			new_node->next = NULL; 
		}
		else
		{
			new_node->next = head; 
			head = new_node; 
		}

		lenght++; 

	}

	void insert_form_end(int element)
	{
		node* new_node = new node;
		new_node->item = element; 

		if(lenght == 0)
		{
			tail = head = new_node; 
			new_node->next = NULL; 			
		}
		else
		{
			tail->next = new_node; 
			new_node->next = NULL; 
			tail = new_node; 
		}
		lenght++; 
	}

	void insert_from_pos(int pos, int element)
	{
		if(pos < 0 || pos > lenght)
		{
			std::cout << "out of range" << std::endl; 
		}

		if(pos == 0)
			insert_form_start(element); 
		else if(pos == lenght)
			insert_form_end(element); 
		else
		{
			node *cur = new node;
			node *new_node = new node;
			cur = head; 
			for(int i = 1; i < pos; i++)
			{
				cur = cur->next;
			}

			new_node->item = element; 
			new_node->next = cur->next; 
			cur->next = new_node; 
			 
		}

		lenght++; 
	}


	void print()
	{
		node *cur = new node; 
		cur = head; 
		while(cur != NULL)
		{
			std::cout << cur->item << std::endl; 
			cur = cur->next; 
		}
	}




};


int main(){

	Linkedlist l; 

	 l.insert_form_start(20); 
	 l.insert_form_end(30); 
	 l.insert_form_end(50);
	 l.insert_form_end(60);
	 l.insert_from_pos(2,40);
	 l.print(); 

	 return 0; 
}