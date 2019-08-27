#pragma once
#include "student.h"

class SoftwareStudent : public Student { //SoftwareStudent is a subclass of base class Student
public:
	virtual Degree getDegreeProgram();	 //override of Student getDegreeProgram()
	using Student::Student;
private:
	Degree DegreeType = SOFTWARE;		 // data member to hold enumerated type
};