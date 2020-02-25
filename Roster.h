#pragma once
#include "Student.h"
#include <iostream>
class Roster
{
private:

	std::vector<Student*> classRosterArray;


public:

	void add(
		std::string studentID,
		std::string firstName,
		std::string lastName,
		std::string emailAddress,
		int age,
		int daysInCourse1,
		int daysInCourse2,
		int daysInCourse3,
		degree degree_program);

	void printAll();
	void printInvalidEmails();
	void printAverageDaysInCourse(std::string);
	void printByDegreeProgram(degree);
	void remove(std::string);
	~Roster();
};

