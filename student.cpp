#pragma once
#include "student.h"

//getters
int Student::getAge() //function to get student age
{
	return Age;
}

int* Student::getDays() //pointer to array that holds DaysInCourse
{
	return DaysInCourse;
}

string Student::getEmail() //function to get student email address
{
	return Email;
}

string Student::getFirstName() //function to get student first name
{
	return FirstName;
}

string Student::getLastName() //function to get student last name
{
	return LastName;
}

string Student::getStudentID() //function to get student ID
{
	return StudentID;
}

Degree Student::getDegreeType()  //function to get student degree
{
	return Degree();
}


//setters
void Student::setAge(int age) // sends age to hold student age
{
	Age = age;
}

void Student::setDaysInCourse(int* daysInCourse) //sends pointer to hold 3 student days in course
{
	for (int i = 0; i < 3; i++) {
		DaysInCourse[i] = daysInCourse[i];
	}
}

void Student::setEmail(string email) // sends email to hold student email
{
	Email = email;
}

void Student::setFirstName(string firstName) //sends firstName to hold student firstname
{
	FirstName = firstName;
}

void Student::setLastName(string lastName) //sends lastName to hold student lastname
{
	LastName = lastName;
}

void Student::setStudentID(string studentId) //sends studentId to hold student ID
{
	StudentID = studentId;
}

void Student::setDegreeType(Degree degreeType) //sends degreeType to hold student degree
{
	DegreeType = degreeType;
}

//constructor overload - when new object is created setters are ran to populate variables
Student::Student(int age, int daysInCourse[3], string studentId, string email, string firstName, string lastName, Degree degreeType)
{
	setAge(age);
	setStudentID(studentId);
	setEmail(email);
	setFirstName(firstName);
	setLastName(lastName);
	setDegreeType(degreeType);
	setDaysInCourse(daysInCourse);
	setDegreeType(degreeType);
}

// print per E3c - format as in C846 requirements
void Student::print()
{
	int* daysInCourse = getDays();

	cout << getStudentID() << "\t"; //Student ID with no label
	cout << "First Name: " << getFirstName() << "\t"; // first name
	cout << "Last Name: " << getLastName() << "\t"; // last name
	cout << "Age: " << getAge() << "\t"; // age - for some reason tab isn't showing up in console window
	cout << "daysInCourse: {" << daysInCourse[0] << ", " << daysInCourse[1] << ", " << daysInCourse[2] << "}\t"; // displays each day in course through array

	cout << "Degree Program: ";
	switch (getDegreeProgram()) {
	case 0: cout << "Security"; //enum 0 - Security
		break;
	case 1: cout << "Networking"; //enum 1 - Networking
		break;
	case 2: cout << "Software"; //enum 2 - Software
		break;
	case 3: cout << "Other"; //enum 3 - Other
		break;
	}
	cout << "\n";
}

//getDegreeProgram left blank
Degree Student::getDegreeProgram()
{
	return OTHER; 
}

// destructor to delete contents of classRoster
Student::~Student()
{ 
}
