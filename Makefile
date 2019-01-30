all: Student

CC= g++

CCFLAGS= -std=c++14

CCFLAGS1= -g -c -Wall

Student: start2.o
		 $(CC) start2.o -o Student
		  
#sort.o: sort.cpp
#		$(CC) $(CCFLAGS) $(CCFLAGS1) sort.cpp

start2.o: student.h start2.h sort.cpp start2.cpp
		  $(CC) $(CCFLAGS) $(CCFLAGS1) student.h start2.h sort.cpp start2.cpp
		
clean:
		  rm -rf *o Student
