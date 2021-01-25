#include <iostream>


void to_binary(int nbr_in_decimal) // 5 - 2 - 1 - 0
{
	int temp_nbr;

	if(nbr_in_decimal > 0) // true - true - true - false 
	{
		temp_nbr = nbr_in_decimal / 2; // 2 - 1 - 0
		to_binary(temp_nbr); // 2 - 1 - 0
		std::cout << nbr_in_decimal % 2 ; // print << 1 - 0 - 1
	}

	
}
int main()
{
	int number = 125; 

	to_binary(number); 

	return 0;
}