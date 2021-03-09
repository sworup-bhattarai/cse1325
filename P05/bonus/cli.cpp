#include "person.h"
#include "student.h"
#include "parent.h"
#include <ostream>
#include <istream>
#include <vector>
#include <iostream>
#include <sstream>



int main(){
	int a, b;
	std::vector<Student> students;
	std::vector<Parent> parents;
	int grade;
	std::string name , email;
	std::cout << "Hello and welcome to the SMART program\n";
	while(std::cin)
	{
		std::cout << "\nMenu:\n\n"<< 
				 "0) Exit\n1) Add parent \n2) Add student\n"
				 << "3) Pair student and parent \n4) Print info"<< std::endl;
	
		std::cin >> a;
		std::cin.clear(); // clear the fail state
		std::cin.ignore(99999,'\n');

		if (a < 0 || a > 4)
		{
			std::cout << "Enter a number between 1 and 4" << std::endl;
			
		}
		else if (a == 1)
		{
			std::cout << "Please enter the full name of parent: ";
			std::getline(std::cin, name );

			std::cout << "Please enter the email of parent: ";
			std::getline(std::cin, email );

			Parent p{name, email};
			parents.push_back(p);
			//delete &p;
		}
		else if (a == 2)
		{
			std::cout << "Please enter the full name of student: ";
			std::getline(std::cin, name );

			std::cout << "Please enter the email of student: ";
			std::getline(std::cin, email );

			std::cout << "Please enter the grade of student: ";
			std::cin >> grade;
			Student s{name, email, grade};
			students.push_back(s);		
		}
		else if (a == 3)
		{
			std::cout << "Select parent: \n";
			for(int i = 0; i < parents.size(); i++) 
			{
        		std::cout << i << ") " << parents[i] ;
    		}
    		std::cin >> a;
    		std::cout << "Select student: \n";
			for(int i = 0; i < students.size(); i++) 
			{
        		std::cout << i << ") " << students[i] ;
    		}
    		std::cin >> b;
    		parents[a].add_student(students[b]);
    		students[b].add_parent(parents[a]);
    		
    		
		}
		else if (a == 4)
		{
			for (auto p : parents )
			{
				std::cout << p.full_info();
			}
			for (auto s : students )
			{
				std::cout << s.full_info();
			}
			
		}
		else if (a == 0)
		{
			break;
		}
	}
}
