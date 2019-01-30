#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <random>
#include <string>
#include <exception>
//#include "start2.h"
//#include "student.h"
#include "sort.cpp"

int main(){
	std::fstream myfile;
	myfile.open("record.txt");
	
	/*
	myfile.open("record.txt", std::ios::out | std::ios::trunc);
	
	if(myfile.is_open()){s
		std::default_random_engine generator;
		std::default_random_engine generator1;
		std::uniform_int_distribution<int> distribution(0,100);
		std::uniform_int_distribution<int> distribution1(10000,99999);
		for(int i = 0; i < 50; ++i){

			myfile << "name" << i << "\n"
				   << distribution1(generator1) << "\n"
				   << distribution(generator) << "\n";
		}
	}
	*/

	//This entire block of code extracts information from the file and inputs it into a Student Record.
	/*
	 * The file format goes as follows:
	 * Student name
	 * Student id number
	 * Student score
	 * The above fields represent one student. Since there are multiple students, the same format is simply repeated for each student on a new line.
	 */
	StudentRecord s1;
	if(myfile.is_open()){
		while(!myfile.eof()){
			std::string name;
			std::string id;
			std::string sc;
			
			//This line of code extracts name of the student
			std::getline(myfile, name);
			
			//This stanza of code extracts the id number of the student
			std::getline(myfile, id);
			int idnum;
			std::istringstream convert(id);
			if(!(convert >> idnum))
				break;
			
			//This stanza of code extracts the score of the student
			std::getline(myfile, sc);
			int score;
			std::istringstream convert1(sc);
			if(!(convert1 >> score));			
			
			//This line takes the extracted data and inputs into a Student Record
			s1.enrollStudent(score, idnum, name);
		}
		s1.printRecord();
		
		//std::cout << "the program will now attempt a selection sort.\n" << std::endl;
		//selectionSort(s1);
		
		//std::cout << "the program will now attempt a insertion sort.\n" << std::endl;
		//insertionSort(s1);
		
		//std::cout << "The program will now attempt a bubble sort" << std::endl;
		//bubbleSort(s1);
		
		//std::cout << "The program will now attempt a merge sort" << std::endl;
		//Student* a = s1.getHead();
		//mergeSort(s1, &a);
		//s1.setHead(a);
		
		std::cout << "The program will now attempt a quicksort" << std::endl;
		quicksort(s1);
		
		s1.printRecord();
	}
		
	else std::cout << "The file could not be opened" << std::endl;
	
	myfile.close();
}
