#include <iostream>
#include <stack>
#include <string>

typedef unsigned int ui; 

bool arepair(char first_txt, char second_txt)
{
	if(first_txt == '(' && second_txt == ')')
		return true; 

	else if(first_txt == '[' && second_txt == ']')
		return true; 

	else if(first_txt == '{' && second_txt == '}')
		return true;
	else
		return false;  
}

bool isBalanced(std::string txt)
{

	std::stack<char> mystack;

	ui length = txt.length();

	std::cout << length << std::endl;  

	for(int i = 0; i < length; i++)
	{
		if(txt[i] == '(' || txt[i] == '[' || txt[i] == '{' )
			mystack.push(txt[i]); 

		if(txt[i] == ')' || txt[i] == ']' || txt[i] == '}' )
		{
			if(!mystack.empty() && arepair(mystack.top(), txt[i]))
			{
				mystack.pop(); 
			}
		}
	}

	if(mystack.empty())
		return true; 
	else 
		return false; 
}

int main()
{

	std::string content;

	std::cout << "Enter your text here: \t" << std::endl; 
	std::getline(std::cin, content); 

	std::cout << content << std::endl; 

	if(isBalanced(content))
	{
		std::cout << "You're text is balanced. \n"; 
	}
	else
		std::cout << "You're text is not balanced. \n"; 


	return 0; 
}