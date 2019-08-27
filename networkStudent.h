#pragma once
#include "student.h"

class NetworkStudent : public Student { //NetworkStudent is a subclass of base class Student
public:
	virtual Degree getDegreeProgram();  //override of Student getDegreeProgram()
	using Student::Student;
private:
	Degree DegreeType = NETWORKING;		// data member to hold enumerated type
};