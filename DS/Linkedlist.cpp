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

	int is_empty()
	{
		if(lenght == 0) return 1; 
		return 0; // is not empty
	}

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


	void remove_first()
	{
		if(is_empty() == 1)
			std::cout << "list is empty: can't delete" << std::endl; 

		if(lenght == 1)
		{
			delete head; 
			head = tail = NULL; 
			lenght--; // lenght = 0; 
		}
		else
		{
			node *cur = new node; 
			cur = head; 
			head = head->next; 
			delete cur; 
			lenght--;
		}

	}

	void remove_last()
	{
		if(is_empty() == 1)
			std::cout << "list is empty: can't delete" << std::endl; 

		if(lenght == 1)
		{
			delete head; 
			head = tail = NULL; 
			lenght--; 
		}
		else
		{
			node *cur = new node; 
			node *prev = new node; 

			cur = head->next; 
			prev = head; 

			while(cur != tail)
			{
				prev = cur; 
				cur = cur->next; 
			}

			prev->next = NULL; 
			delete cur; 
			tail = prev; 
			lenght--; 
		}
	}

	void remove(int element)
	{
		if(is_empty() == 1)
			std::cout << "list is empty: can't delete" << std::endl; 

		if(lenght == 1)
		{
			delete head; 
			head = tail = NULL; 
			lenght--; 
		}

		if(head->item == element)
			remove_first();

		else if(tail->item == element)
			remove_last(); 

		else
		{
			node *cur = new node; 
			node *prev = new node; 

			cur = head->next; 
			prev = head;

			while(cur->item != element)
			{
				prev = cur; 
				cur = cur->next; 
			}

			prev->next = cur->next;
			if(cur == tail)
				tail = prev ; 
			delete cur; 
			lenght--; 

			if(lenght == 0)
				head = tail = NULL; 
		}
	}

	void remove_key(int key)
	{
		if(is_empty() == 1)
			std::cout << "list empty: can't delete" << std::endl; 

		if(lenght == 1)
		{
			delete head; 
			head = tail = NULL; 
			lenght--; 
		}
		if(key == 0)
			remove_first(); 
		else if(key == lenght-1 )
			remove_last();
		else
		{
			int counter = 1; 
			node *cur = new node; 
			node *prev = new node;
			cur = head->next; 
			prev = head; 

			while(counter < key)
			{
				prev = cur; 
				cur = cur->next; 
				counter++; 
			} 

			prev->next = cur->next; 

			if(cur == tail)
				tail = prev; 

			delete cur; 

			lenght--; 

		}
	}

	void reverse()
	{
		if(is_empty() == 1)
			std::cout << "empty list: can't reverse" << std::endl; 

		if(lenght != 1 )
		{
			node *prev, *cur, *holder; 
			prev = NULL; 
			cur = head; 
			holder = cur->next; 

			while(holder != NULL && cur != NULL)
			{
				holder = cur->next; 
				cur->next = prev; 
				prev = cur; 
				cur = holder; 
			}

			head = prev; 
			// find tail 
			cur = head; 
			while(cur->next != NULL)
			{
				cur = cur->next; 
			}

			tail = cur; 
		}

	}

	int search(int element)
	{
		if(is_empty() == 1)
			std::cout << "list empty: can't search" << std::endl; 

		else if(lenght == 1)
		{
			if(head->item == element) 
				return 0; 
		}
		else
		{
			int pos = 0; 
			node *cur ; 
			cur = head; 

			while(cur != NULL)
			{
				if(cur->item == element)
					return pos; 

				cur = cur->next; 
				pos++; 
			}	
		}

		return -1; 




	}

	void test_tail()
	{
		std::cout << "tail: " << tail->item << std::endl; 
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

	int list_size()
	{
		return lenght;
	}




};


int main(){

	Linkedlist l; 
	int position; 

	 l.insert_form_start(20); 
	 l.insert_form_end(30); 
	 l.insert_form_end(50);
	 l.insert_form_end(60);
	 l.insert_from_pos(2,40);
	 
	 l.reverse(); 
	 position = l.search(20); 

	 std::cout << "Pos = " << position << std::endl; 

	 l.print(); 

	 return 0; 
}