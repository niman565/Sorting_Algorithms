#include "start2.h"
//#include "student.h"
#include <iostream>
#include <string>
#include <exception>

#ifndef SORT_CPP
#define SORT_CPP

/*
 * This function swaps element1 and element2.
 * This function assumes that element1 and element2 are in order: element1 is the original first element and element2 is the original second element.
 */
void swap(Student* prevptr, Student* element1, Student* element2){
	Student* temp = element2->getNext();
	prevptr->setNext(element2);
	element2->setNext(element1);
	element1->setNext(temp);
}

void selectionSort(StudentRecord &s1){
	bool notDone = true;
	
	Student* a = s1.findMaxUnsorted();
	Student* b = new Student(a);
	
	std::string astring = b->getName();
	s1.dismissStudent(astring);
	
	a = s1.getHead();
	//std::cout << a->getName() << std::endl;
	//Student* b = new Student(a->getScore(),a->getIdNum(),a->getName());
	//std::cout << b->getName() << std::endl;
	//s1.dismissStudent(a->getName());
	
	while(notDone){
		if(a->getNext() == NULL){
			b->makeSorted();
			s1.enrollStudent(a->getName(), b);
			notDone = false;
		}
		else a = a->getNext();
	}
	
	std::cout<<"Done with first max Student" << std::endl;
	
	while(s1.findMaxUnsorted() != NULL){
	//for(int i = 0; i < s1.getLength(); ++i){
		a = s1.findMaxUnsorted();
		Student* c = new Student(a);
		
		std::string name1 = a->getName();
		if(s1.dismissStudent(name1));
		
		std::cout << "in first while loop" << std::endl;
		
		Student* head1 = s1.getHead();
		//notDone = true;
		while(head1 != NULL){
			if(head1->getNext()->isSorted() == true){
				s1.enrollStudent(head1->getName(), c);
				c->makeSorted();
				c = NULL;
				head1 = NULL;
			}
			else head1 = head1->getNext();
			std::cout << "in second while loop" << std::endl;
		}
	}
}

void insertionSort(StudentRecord &s1){
	while(s1.findMaxUnsorted() != NULL){
		Student* a = s1.findMaxUnsorted();
		Student* c = new Student(a);
		
		std::string name1 = a->getName();
		if(s1.dismissStudent(name1));
		
		s1.enrollStudent(c);
		c->makeSorted();
		c = NULL;
	}
}

void bubbleSort(StudentRecord &s1){
	bool sortDone;
	for(int i = 0; i < s1.getLength() && !sortDone; ++i){
		Student *head1, *prev, *post;
		head1 = s1.getHead();
		prev = head1->getNext();
		post = prev->getNext();
		
		sortDone = true;
		
		if(head1->getScore() > prev->getScore()){
			sortDone = false;
			
			Student* temp = new Student(prev);
			std::string tempString = prev->getName();
			
			s1.dismissStudent(tempString);
			s1.enrollStudent(temp);
			
			head1 = s1.getHead();
			prev = head1->getNext();
			post = prev->getNext();
		}
		while(post != NULL){
			if(prev->getScore() > post->getScore()){
				swap(head1, prev, post);
				sortDone = false;
			}
			head1 = head1->getNext();
			prev = head1->getNext();
			post = prev->getNext();
		}
	}
}

void print(Student** a){
	Student* b = *a;
	if(b == NULL){
		std::cout << "Empty" << std::endl;}
	else{
	while(b != NULL){
		std::cout << b->getScore() << std::endl;
		b = b->getNext();
	}
	
}
std::cout << "Done!!" << std::endl;
}

//partitions the student record into two student records
void partition(Student* head, Student** front, Student** back){
	Student *fast, *slow;
	
	if(head == NULL || head->getNext() == NULL){
		*front = head;
		*back = NULL;
	}
	else{
		slow = head;
		fast = head->getNext();
		while(fast != NULL){
			fast = fast->getNext();
			if(fast != NULL){
				slow = slow->getNext();
				fast = fast->getNext();
			}
		}
	}
	
	*front = head;
	*back = slow->getNext();
	slow->setNext(NULL);
	
	//print(front);
	//print(back);
	//std::cout << "partition" << std::endl;
}

Student* merge(Student* a, Student* b){
	Student* headNew;
	
	if(a == NULL){
		return b;
	}
	else if(b == NULL){
		return a;
	}
	
	if(a->getScore() <= b->getScore()){
		headNew = a;
		headNew->setNext(merge(a->getNext(),b));
	}
	else{
		headNew = b;
		headNew->setNext(merge(a, b->getNext()));
	}
	
	return headNew;
}

void mergeSort(StudentRecord &s1, Student **node){
	Student* head = *node;
	Student* a = NULL;
	Student* b = NULL;
	
	if((head == NULL || head->getNext() == NULL)){
		return;
	}
	
	partition(head, &a, &b);
	
	//if(a == NULL){
	//std::cout << "merge1  " << std::endl;
	
	mergeSort(s1, &a);
	
	//std::cout << "merge2" << std::endl;
	
	mergeSort(s1, &b);
	
	//Student* temp = merge(a, b);
	//s1.setHead(temp);
	
		*node = merge(a, b);
	//std::cout << "merge3" << std::endl;
	//print(&temp);

	s1.printRecord();
	std::cout << "\n" << std::endl;
}

Student* returnLast(Student* headNew){
	Student* head1 = headNew;
	if(head1 == NULL){
		return NULL;}
	else{
		while(head1->getNext() != NULL){
			head1 = head1->getNext();
		}
		return head1;
	}
}

void partition1(StudentRecord &s1, Student** start, Student** end, Student** lhsStart, Student** lhsEnd, Student** rhsStart, Student** rhsEnd){
	Student* start1 = *start;
	
	Student* pivot = *end;
	
	Student* beforeStart = s1.getHead();
	if(beforeStart == start1){
		beforeStart = NULL;
	}
	else{
		while(beforeStart->getNext() != start1){
			beforeStart = beforeStart->getNext();
		}
	}
	
	Student* afterEnd = (*end)->getNext();
	Student* pivotOriginal = pivot;
	pivot->setNext(NULL);
	
	int i = 0;
	
	while(start1 != pivotOriginal){
		if(start1->getScore() != pivot->getScore()){
			if(start1->getScore() < pivot->getScore()){
				Student* temp = start1->getNext();
				start1->setNext(*lhsStart);
				*lhsStart = start1;
				start1 = temp;
			}
			else{
				Student* temp = start1->getNext();
				start1->setNext(*rhsStart);
				*rhsStart = start1;
				start1 = temp;
			}
		}
		else{
			Student* temp = start1->getNext();
			start1->setNext(pivot);
			pivot = start1;
			start1 = temp;
		}
		
		std::cout << "The 2nd loop is running for the " << ++i << "th time" << std::endl;
	}
	
	print(lhsStart);
	print(&pivot);
	print(rhsStart);
	
	*lhsEnd = returnLast(*lhsStart);
	Student* pivotEnd = returnLast(pivot);
	*rhsEnd = returnLast(*rhsStart);
	
	if(*lhsStart == NULL && *rhsStart == NULL){
		if(beforeStart == NULL){
			s1.setHead(pivot);
		}
		else{
			beforeStart->setNext(pivot);
		}
		pivotEnd->setNext(afterEnd);
	}
	else if(*lhsStart == NULL){
		if(beforeStart == NULL){
			s1.setHead(pivot);
		}
		else{
			beforeStart->setNext(pivot);
		}
		pivotEnd->setNext(*rhsStart);
		(*rhsEnd)->setNext(afterEnd);
	}
	else if(*rhsStart == NULL){
		if(beforeStart == NULL){
			s1.setHead(*lhsStart);
		}
		else{
			beforeStart->setNext(*lhsStart);
		}
		(*lhsEnd)->setNext(pivot);
		pivotEnd->setNext(afterEnd);
	}
	else{
		if(beforeStart == NULL){
			s1.setHead(*lhsStart);
		}
		else{
			beforeStart->setNext(*lhsStart);
		}
		
		(*lhsEnd)->setNext(pivot);
		pivotEnd->setNext(*rhsStart);
		(*rhsEnd)->setNext(afterEnd);
	}
	
	pivot= NULL; afterEnd = NULL; start1 = NULL; beforeStart = NULL; pivotOriginal = NULL; pivotEnd = NULL;
}

void quicksortRecur(StudentRecord &s1, Student** start, Student** end){
	
	Student *lhsStart = NULL, *lhsEnd = NULL, *rhsStart = NULL, *rhsEnd = NULL;
	
	if(*start == *end)
		return;
	partition1(s1, start, end, &lhsStart, &lhsEnd, &rhsStart, &rhsEnd);
	
	//if(start != end){
		quicksortRecur(s1, &lhsStart, &lhsEnd);
		quicksortRecur(s1, &rhsStart, &rhsEnd);
	//}
	
	return;
}

void quicksort(StudentRecord &s1){
	Student* head = s1.getHead();
	Student* tail = s1.getLastStudent();
	quicksortRecur(s1, &head, &tail);
}
#endif
