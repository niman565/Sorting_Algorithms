#include <iostream>
#include <string>
#include <exception>

#ifndef STUDENT_H
#define STUDENT_H

class Student{
		
		friend class StudentRecord;
		
		private: 
		
		int score;					 //score given to student by professor
		int id;                      //identification number of the student
		std::string name;            //name of the student
		Student *nextStudent;        //pointer to next "Student" node in linked list "StudentRecord"
		bool sorted;				 //value that indicates whether or not the Student is in order; primarily, this field is meant for use in sorting algorithms
									 //unless changed, the default value of sorted is false
		
		public:
		
		/*
		 * Constructors and Destructor.
		 * Constructors accept Student objects and Student fields as arguments.
		 */
		Student() : score(0), id(0) , name(""), sorted(false) //default constructor; initializes fields to default values
			{nextStudent = NULL;}    //sets pointer to "NULL" since this is the default constructor
			
		Student(Student& s1) : score(s1.score), id(s1.id) , name(s1.name), sorted(false)
			{this->nextStudent = s1.nextStudent;}
			
		Student(Student* s1) : score(s1->score), id(s1->id) , name(s1->name), sorted(false)
			{this->nextStudent = s1->nextStudent;}
		
		//The following two constructors take L-value arguments.
		Student(int& grade, int& idnum, std::string& newName) : score(grade), id(idnum) , name(newName), sorted(false)
			{nextStudent = NULL;}
			
		Student(int& grade, int& idnum, std::string& newName, Student& s2) : score(grade), id(idnum) , name(newName), sorted(false)
			{nextStudent = &s2;}
			
		//The following two constructors take R-value arguments.
		Student(int&& grade, int&& idnum, std::string&& newName) : score(grade), id(idnum) , name(newName), sorted(false)
			{nextStudent = NULL;}
			
		Student(int&& grade, int&& idnum, std::string&& newName, Student& s2) : score(grade), id(idnum) , name(newName), sorted(false)
			{nextStudent = &s2;}
			
		~Student(){
			delete nextStudent;
			nextStudent = NULL;
		}
		
		void makeSorted(){
			sorted = true;
		}
		
		void notSorted(){
			sorted = false;
		}
		
		//accessor methods
		
		int getScore(){
			return score;
		}
		
		int getIdNum(){
			return id;
		}
		
		std::string getName(){
			return name;
		}
		
		Student* getNext(){
			return nextStudent;
		}
		
		bool isSorted(){
			return sorted;
		}
		
		//mutator methods
		
		void setNext(Student* a){
			nextStudent = a;
		}
	};
	
#endif
