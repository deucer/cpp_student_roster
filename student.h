#pragma once
#include <iostream>
#include <string>
#include "degree.h"
using namespace std;

class Student {
public:
	
	//getters
	int getAge();
	int* getDays();
	string getEmail();
	string getFirstName();
	string getLastName();
	string getStudentID();
	Degree getDegreeType();
	
	//setters
	void setAge(int);
	void setDaysInCourse(int*);
	void setEmail(string);
	void setFirstName(string);
	void setLastName(string);
	void setStudentID(string);
	void setDegreeType(Degree);
	
	//additional methods
	virtual void print();
	virtual Degree getDegreeProgram();
	
	//constructor
	Student(int, int[3], string, string, string, string, Degree);
	
	//destructor
	~Student();

private:
	int Age;
	int DaysInCourse[3];
	string FirstName, LastName, StudentID, Email;
	Degree DegreeType;
};