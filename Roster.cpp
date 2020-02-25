#include "Roster.h"
#include "securityStudent.h"
#include "networkStudent.h"
#include "softwareStudent.h"
#include <sstream>
#include <vector>



void Roster::add(
	std::string studentID,
	std::string firstName,
	std::string lastName,
	std::string emailAddress,
	int age,
	int daysInCourse1,
	int daysInCourse2,
	int daysInCourse3,
	degree degree_program) {

	Student* myStudent = NULL;

	if (degree_program == SOFTWARE)
	{
		myStudent = new softwareStudent();
	}
	else if (degree_program == NETWORK)
	{
		myStudent = new networkStudent();
	}
	else
	{
		myStudent = new securityStudent();
	}

	myStudent->set_ID(studentID);
	myStudent->set_First_Name(firstName);
	myStudent->set_Last_Name(lastName);
	myStudent->set_Email_Address(emailAddress);
	myStudent->set_Age(age);
	myStudent->set_Days_In_Course(daysInCourse1, daysInCourse2, daysInCourse3);
	myStudent->set_Degree_Type(degree_program);
	
	
	// Add to list
	classRosterArray.push_back(myStudent);

}

// Printing all student data
void Roster::printAll()
{

	for (std::vector<Student*>::iterator iter = classRosterArray.begin();
		iter != classRosterArray.end();
		iter++)
	{
		Student* student = (Student*) *iter;

		student->print();
		
	}
}

// Printing invalid emails
void Roster::printInvalidEmails() {
	std::cout << "\nDisplaying invalid emails:" << "\n";
	for (int i = 0; i < 5; i++) {
		bool foundCharAt = false;
		bool foundCharPeriod = false;
		bool foundCharSpace = false;
		std::string email = "";
		email = (*classRosterArray[i]).get_Email_Address();
		for (char& c : email) {
			if (c == '@') {
				foundCharAt = true;
			}
			if (c == '.') {
				foundCharPeriod = true;
			}
			if (c == ' ') {
				foundCharSpace = true;
			}
		}
		if (foundCharAt == false || foundCharPeriod == false || foundCharSpace == true) {
			std::cout << (*classRosterArray[i]).get_Email_Address() << "\n";
		}
	}
	std::cout << "\n";
}

// Printing average number of days to complete courses
void Roster::printAverageDaysInCourse(std::string studentID) {
	for (int i = 0; i < 5; i++) {
		if ((*classRosterArray[i]).get_ID() == studentID) {
			int avg = 0;
			avg = ((*classRosterArray[i]).get_Days_In_Course()[0] + (*classRosterArray[i]).get_Days_In_Course()[1]
				+ (*classRosterArray[i]).get_Days_In_Course()[2]) / 3;
			std::cout << "Student " << studentID << " has taken an average of " << avg << " days to complete three courses. \n";
		}
	}
	std::cout << "\n";
}

// Printing students by degree program
void Roster::printByDegreeProgram(degree degreeType) {
	degree givenDeg = degree::SOFTWARE;
	if (degreeType == SECURITY) {
		givenDeg = degree::SECURITY;
		std::cout << "Security degree students: \n";
	}
	if (degreeType == NETWORK) {
		givenDeg = degree::NETWORK;
		std::cout << "Network degree students: \n";
	}
	if (degreeType == SOFTWARE) {
		givenDeg = degree::SOFTWARE;
		std::cout << "Software degree students: \n";
	}

	for (int i = 0; i < 5; i++) {
		if (givenDeg == (*classRosterArray[i]).get_Degree_Type()) {
			(*classRosterArray[i]).print();
		}
	}
	std::cout << "\n";
}

// Removing a student and reporting back if double removal is attempted
void Roster::remove(std::string studentID) {
	bool removed = false;
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != NULL) {
			if (studentID == classRosterArray[i]->get_ID()) {
				classRosterArray[i] = nullptr;
				removed = true;
			}
		}
	}
	if (!removed) {
		std::cout << "ERROR! Student not found\n";
	}
}


//Deconstructor
Roster::~Roster() {}



int main() {

	const std::string studentData[] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Jordan,Pappas,jpappa8@wgu.edu,26,30,27,26,SOFTWARE" };

	//Instantiation of myRoster
	Roster classRoster;


	//Instantiation of myDegree
	degree myDegree;

	// adding each student to the classRoster
	for (int i = 0; i < 5; i++) {
		std::stringstream ss(studentData[i]);

		std::vector<std::string> result;

		while (ss.good()) {
			std::string substr;
			getline(ss, substr, ',');
			result.push_back(substr);
		}
		if (result[8] == "SECURITY") {
			myDegree = degree::SECURITY;
		}
		else if (result[8] == "SOFTWARE") {
			myDegree = degree::SOFTWARE;
		}
		else {
			myDegree = degree::NETWORK;
		}
		classRoster.add(result[0], result[1], result[2], result[3], stoi(result[4]), stoi(result[5]),
			stoi(result[6]), stoi(result[7]), myDegree);
	}



	//Personal Info 
	std::cout << "Scripting and Programming - Applications C867" << "\n";
	std::cout << "C++" << "\n";
	std::cout << "Student ID# 001213798" << "\n";
	std::cout << "Jordan Pappas" << "\n";
	std::cout << "\n";

	// Printing ALL()
	classRoster.printAll();

	classRoster.printInvalidEmails();
	
	classRoster.printAverageDaysInCourse("A1");

	classRoster.printByDegreeProgram(SOFTWARE);
	
	classRoster.remove("A3");

	classRoster.remove("A3");

	


}



