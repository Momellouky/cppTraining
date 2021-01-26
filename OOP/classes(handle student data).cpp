#include <iostream>
#include <stdlib.h>

// *class to get data of a student && print back its data

typedef unsigned int ui; 

class student
{
private:

	char first_name[20]; 
	char last_name[20]; 

	ui student_age,
	   student_id; 

	float semseter_grades[6]; // 6 is the number subjects in one semester


public: 
	student() // for object initialised without argument => set initial values
	{
		// 0 stands for value NOT ASSIGNED
		student_age = 0; 
		student_id  = 0; 

		// NONE : no info (last and first name) available for this student
		memcpy(first_name, "NONE", 20);  
		memcpy(last_name , "NONE", 20); 
	}

	student(const char f_name[], const char l_name[], ui s_age, ui s_id) // constructor
	{

		student_id  = s_id; 
		student_age = s_age; 

		memcpy(first_name, f_name, 20); 
		memcpy(last_name , l_name, 20); 

	}

	/*
		* no need for copy constructor.
	*/ 

	student(const student& old_student) = delete; 



	// *Grades are valid
	bool grade_valid(float grades[])
	{

		bool not_valid = false; 

		for(size_t counter_i = 0; counter_i < 6; counter_i++)
		{
			if(grades[counter_i] < 0 || grades[counter_i] > 20) 
			{
				not_valid = true; 
				break; 
			} 
		}

		return not_valid; 

	}

	// *function to get semester grades
	void get_grades(float grades[])
	{

		for(size_t counter_i = 0; counter_i < 6; counter_i++)
		{
			semseter_grades[counter_i] = grades[counter_i];	
		}

	}

	// *function to calculate the avarage of student's grades
	// * return the avg if all grades are valid ( FOR EACH GRADE: ALL GRADES ARE EQUAL 
	// 	 OR GREATER THEN 0 && LESS THEN 20 )
	// * return -1 if an input isn't valid. 

	float avg_grade(float grades[])
	{
		float sum = 0;  

		if(grade_valid(grades))
		{

			std::cout << "Invalid grade" << std::endl;
			return -1;  	

		}
		else
		{

			for(size_t counter_i = 0; counter_i < 6; counter_i++)
			{
				sum += grades[counter_i]; 
			}
			return sum / 6 ;

		}

		
	}
}; 
int main()
{

	float mygrades[6] = { 0, 0, 0, 18, 0, 0};

	student me("Mohamed", "Mellouky", 20, 10001);

	me.get_grades(mygrades); 
	
	
	float avg = me.avg_grade(mygrades); 

	std::cout << avg << std::endl; 

	return 0; 
}