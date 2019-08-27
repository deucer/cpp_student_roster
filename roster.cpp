#pragma once
#include <iostream>
#include <sstream>
#include "roster.h"

using namespace std;

int main() {
	cout << "Course Title: \t C867 - Scripting and Programming - Applications\n";
	cout << "Language: \t C++11x \n";
	cout << "Student ID: \t 000912592 \n";
	cout << "Student Name: \t Jeremy Crantek\n\n";

	Roster classRoster;

	const string studentData[5] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Jeremy,Crantek,jcrant3@wgu.edu,40,52,16,12,SOFTWARE"
	};

	//populate the class roster array
	for (int i = 0; i < sizeof(studentData) / sizeof(studentData[i]); i++) {
		string input = studentData[i];
		istringstream ss(input);
		string token;
		string placeholder[9];

		int x = 0;
		while (getline(ss, token, ',')) {
			placeholder[x] = token;
			x += 1;
		}

		Degree studentDegree;
		if (placeholder[8] == "NETWORK") {
			studentDegree = NETWORKING;
		}
		else if (placeholder[8] == "SECURITY") {
			studentDegree = SECURITY;
		}
		else if (placeholder[8] == "SOFTWARE") {
			studentDegree = SOFTWARE;
		}
		else {
			studentDegree = OTHER;
		}

		classRoster.add(placeholder[0], placeholder[1], placeholder[2], placeholder[3], std::stoi(placeholder[4]), std::stoi(placeholder[5]), std::stoi(placeholder[6]), std::stoi(placeholder[7]), studentDegree);
	}
	cout << "Print student roster...\n";
	classRoster.printAll();
	cout << "\n";

	cout << "Printing invalid emails...\n";
	classRoster.printInvalidEmails();
	cout << "\n";

	cout << "Printing average days (rounded up) of each course...\n";
	for (int i = 0; i < sizeof(classRoster.classRosterArray) / sizeof(classRoster.classRosterArray[i]); i++) {
		classRoster.printDaysInCourse((classRoster.classRosterArray[i]->getStudentID()));
	}
	cout << "\n";

	cout << "Printing by software degree (SOFTWARE)...\n";
	classRoster.printByDegreeProgram(SOFTWARE);
	cout << "\n";

	cout << "Removing Student ID (A3)...\n";
	string A3 = studentData[2];
	cout << A3 << "\n";
	classRoster.remove("A3");
	cout << "\n";

	cout << "Removing Student ID (A3 again)...\n";
	classRoster.remove("A3");
	cout << "\n";

	/* Show remaining students in classRoster
	string A1 = studentData[0];
	string A2 = studentData[1];
	string A4 = studentData[3];
	string A5 = studentData[4];
	cout << A1 << "\n";
	cout << A2 << "\n";
	cout << A4 << "\n";
	cout << A5 << "\n";
	*/
	return 0;
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram)
{
	int courseDays[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
		if (classRosterArray[i] == nullptr) {
			if (degreeProgram == NETWORKING) {
				classRosterArray[i] = new NetworkStudent(age, courseDays, studentID, emailAddress, firstName, lastName, degreeProgram); //creates new NetworkStudent
			}
			else if (degreeProgram == SECURITY) {
				classRosterArray[i] = new SecurityStudent(age, courseDays, studentID, emailAddress, firstName, lastName, degreeProgram); //creates new SecurityStudent
			}
			else if (degreeProgram == SOFTWARE) {
				classRosterArray[i] = new SoftwareStudent(age, courseDays, studentID, emailAddress, firstName, lastName, degreeProgram); //creates new SoftwareStudent
			}
			else {
				classRosterArray[i] = new Student(age, courseDays, studentID, emailAddress, firstName, lastName, degreeProgram);
			}

			break;
		}
	}
}

void Roster::printAll()
{
	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
		classRosterArray[i]->print();
	}
}

void Roster::printByDegreeProgram(int degreeProgram)
{
	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
		if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			classRosterArray[i]->print();
		}
	}
}

void Roster::printDaysInCourse(string studentID)
{
	float avg = 0;
	int max = 3;
	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
		if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {
			int* daysInCourse = classRosterArray[i]->getDays();
			for (int x = 0; x < max; x++) {
				avg += daysInCourse[x];
			}

			cout << "Student " << classRosterArray[i]->getStudentID() << "'s average number of days in each of the three courses is " << ceil((avg / max)) << "\n";
			break;
		}
	}
}

void Roster::printInvalidEmails()
{
	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
		string email = classRosterArray[i]->getEmail();
		bool isValid = false;

		size_t found = email.find("@");
		if (found != string::npos) {
			found = email.find(".");
			if (found != string::npos) {
				found = email.find(" ");
				if (found == string::npos) {
					isValid = true;
				}
			}
		}

		if (!isValid) {
			cout << email << " is not a valid email address. \n";
		}
	}
}

void Roster::remove(string studentID)
{
	bool studentRemoved = false;
	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
		if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {
			classRosterArray[i] = nullptr;
			studentRemoved = true;
			break;
		}
	}

	if (studentRemoved == false) {
		cout << "Student ID '" << studentID << "' does not exist. Try again. \n";
	}
}

Roster::~Roster()
{
	delete[] *classRosterArray;
}