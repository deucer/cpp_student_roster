#pragma once
#include "student.h"

class SecurityStudent : public Student { //SecurityStudent is a subclass of base class Student
public:
	virtual Degree getDegreeProgram();	//override of Student getDegreeProgram()
	using Student::Student;
private:
	Degree DegreeType = SECURITY;       // data member to hold enumerated type
};