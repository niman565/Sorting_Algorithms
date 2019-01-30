#include <iostream>
#include <string>
#include <exception>
#include "student.h"

#ifndef START2_H
#define START2_H


class StudentRecord{
		
	private:
	
		Student* head;
		int recordLength;
		
	public:
	
		//prints the names of each Student node in the Student Record linked list.
		void printRecord(){
			if(this->isEmpty()){
				std::cout << "The Student Record is empty." << std::endl;
			}
			else{
				Student *temp;
				temp = head;
				while(temp != NULL){
					std::cout << "name: " << temp->name << std::endl
							  << "ID #: " << temp->id << std::endl
							  << "Score on assignment: " << temp->score << std::endl;
					temp = temp->nextStudent;
				}
				//std::cout << temp->name << std::endl;
				//delete temp;
				temp = NULL;
			}
			return;
		}
		
		/*
		 * This adds a "Student" node to the "StudentRecord" linked list from the head Student node.
		 * One function takes a Student object as an argument and the other function takes the Student fields, an integer and a string, as arguments.
		 * Finally, one function takes a pointer as an argument and adds the data the pointer is pointing to to the Student Record
		 */
		void enrollStudent(Student& a){
			if(head != NULL){
				a.nextStudent = head;
				head = &a;
			}
			else{
				head = &a;
			}
			recordLength++;
			return;
		}
		
		void enrollStudent(Student* a){
			if(isEmpty())
				head = a;
			else{
				Student* b = head;
				head = a;
				head->nextStudent = b;
				b = NULL;
			}
			return;
		}
		
		void enrollStudent(int& grade, int& idnum, std::string& name){
			Student* tempObject = new Student(grade, idnum, name);
			if(head != NULL){
				Student* temp = head;
				head = tempObject;
				tempObject->nextStudent = temp;
			}
			else{
				head = tempObject;
			}
			tempObject = NULL;
			recordLength++;
			return;
		}
		
		/*
		 * @param:name the user wishes to insert a student after
		 * @param:a pointer to the Student object
		 */
		 
		 void enrollStudent(std::string location, Student* a){
			std::string astring = location;
			if(isEmpty() || (!searchStudent(astring))){
				std::cout << "The student: " << location << " does not exist in the StudentRecord." << std::endl;
				return;
			}
			else{
				Student* b = head;
				while(b != NULL){
					if(b->name.compare(location) == 0){
						Student* temp = b->nextStudent;
						b->nextStudent = a;
						a->nextStudent = temp;
						temp = NULL;
						b = NULL;
						recordLength++;
					}
					else b = b->nextStudent;
				}
			}
			return;
		 }
		
		//This method removes the specific "Student" node that the user specified with the input string from the student record.
		bool dismissStudent(std::string& name1){
			bool successful = false;
			if(isEmpty())
				return successful;
			else if(!searchStudent(name1))
				return successful;
			else{
				Student *a,*b;
				b = head;
				if(b->name.compare(name1) == 0){
					head = head->nextStudent;
					b->nextStudent = NULL;
					delete b;
					b = NULL;
					recordLength--;
					successful = true;
				}
				else{
					bool notNull = true;
					while(notNull){
						a = b;
						b = b->nextStudent;
						if(b == NULL)
							notNull = false;
						else if(b->name.compare(name1) == 0){
							a->nextStudent = b->nextStudent;
							b->nextStudent = NULL;
							delete b;
							b = NULL;
							successful = true;
							recordLength--;
							break;
						}
					}
				}
				return successful;																																																																																																																																																																																																																																																																																																																																																																																																																
			}
		}
		
		//This functions checks to see if the studentRecord is empty.
		bool isEmpty(){
			return (head == NULL);
		}
		
		/*
		 * This function takes a string as an argument and returns true if the name is in the studentRecord;
		 * if the name is not in the studentRecord or the studentRecord is empty, the function returns false.
		 * */
		bool searchStudent(std::string& name1){
			Student *a = head;
			bool found = false;
			if(isEmpty())
				found = false;
			else{
				bool notDone = true;
				while(notDone){
					if(a->name.compare(name1) == 0){
						notDone = false;
						found = true;
					}
					else if(a->nextStudent == NULL)
						notDone = false;
					else a = a->nextStudent;
				}
				if(!found)
					found = false;
			}
			return found;																																																																																																																																																																																																																																																																																																																																																																																																																																																																																	
		}
		
		Student* searchStudentRet(std::string& name1){
			if(searchStudent(name1)){
				Student* a = head;
				bool notDone = true;
				while(notDone){
					if(a->name.compare(name1) == 0)
						return a;
					else if(a->nextStudent == NULL)
						notDone = false;
					else a = a->nextStudent;
				}
			}
			else{
				std::cout << "The student you are looking for is not in the Student Record" << std::endl;
				return NULL;
			}
		}
		
		void makeEmpty(){
			bool notDone = true;
			while(notDone){
				if(head == NULL)
					notDone = false;
				/*else if(head->nextStudent == NULL){
					delete head;
					head = NULL;
				}*/
				else{
					Student *a = head;
					head = a->nextStudent;
					a->nextStudent = NULL;
					delete a;
					a = NULL;
				}
			}
			delete head;
			head = NULL;
		}
		
		Student* getLastStudent(){
			Student* tail = head;
			while(tail->nextStudent != NULL){
				tail = tail->nextStudent;
			}
			return tail;
		}
		
		Student* findMaxUnsorted(){
			int max = 0;
			Student* s1 = head;
			Student* maxStudent = NULL;
			if(!isEmpty()){
				for(;s1 != NULL; s1 = s1->nextStudent){
					if(s1->score >= max && s1->sorted == false){
						max = s1->score;
						maxStudent = s1;
					}
				}
				
			}
			else{
				std::cout << "The Student Record is empty" << std::endl;
				
			}
			return maxStudent;
		}
		
		/*
		 * Sorting methods
		 */
		 
		 //void selectionSort(StudentRecord &s1);
			
		/*
		 * Accessor methods for StudentRecord fields. 
		 * There is no need for mutator methods due to the fact that the user will not directly change "head" and "recordLength" fields 
		 */
		int getLength(){
			return recordLength;
		}
		
		std::string getFirstName(){
			return head->name;
		}
		
		Student* getHead(){
			return head;
		}
		
		//mutator methods
		
		void setHead(Student* a){
			//this->makeEmpty();
			head = a;
		}
		
		/*
		 * Constructors and destructor. Constructors can take StudentRecords, Students, and Student fields as arguments.
		 * Destructor uses while loop to traverse and delete all Student objects in the Student Record
		 */
		StudentRecord() : head(NULL) , recordLength(0) {}
		
		StudentRecord(StudentRecord& a) : head(a.getHead()) , recordLength(a.getLength()) {}
		
		StudentRecord(Student& a) : head(&a) , recordLength(1) {}
		
		StudentRecord(int& score, int& num, std::string& name) : head() , recordLength(1){
			head = new Student(score, num, name);
		}
		
		~StudentRecord(){
			bool notDone = true;
			while(notDone){
				if(head == NULL)
					notDone = false;
				/*else if(head->nextStudent == NULL){
					delete head;
					head = NULL;
				}*/
				else{
					Student *a = head;
					head = a->nextStudent;
					a->nextStudent = NULL;
					delete a;
					a = NULL;
				}
			}
			delete head;
			head = NULL;
		}
};
#endif
