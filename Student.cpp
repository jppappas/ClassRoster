#include "Student.h"
#include <iostream>
#include "Roster.h"


Student::Student()
{
	m_Days_In_Course.push_back(0);
	m_Days_In_Course.push_back(0);
	m_Days_In_Course.push_back(0);
}

// Set/Get ID
void Student::set_ID(std::string ID) {

	m_ID = ID;

}

std::string Student::get_ID() {

	return m_ID;
}

// Set/Get First Name
void Student::set_First_Name(std::string first_name) {

	m_First_Name = first_name;

}

std::string Student::get_First_Name() {

	return m_First_Name;
}

// Set/Get Last Name
void Student::set_Last_Name(std::string last_name) {

	m_Last_Name = last_name;

}

std::string Student::get_Last_Name() {

	return m_Last_Name;
}

// Set/Get Email Address
void Student::set_Email_Address(std::string email) {

	m_Email_Address = email;

}

std::string Student::get_Email_Address() {

	return m_Email_Address;
}

// Set/Get Age
void Student::set_Age(unsigned int Age) {

	m_Age = Age;

}

unsigned int Student::get_Age() {

	return m_Age;
}

// definintion for array in Student.H
void Student::set_Days_In_Course(int Day1, int Day2, int Day3) {

	m_Days_In_Course[0] = Day1;
	m_Days_In_Course[1] = Day2;
	m_Days_In_Course[2] = Day3;

}
void Student::set_Days_In_Course(const std::vector<int>& input_vector) {

	if (input_vector.size() == 3) {
		m_Days_In_Course = input_vector;
	}

}

const std::vector<int>& Student::get_Days_In_Course() {

	return m_Days_In_Course;

}

// Set/ Get Degree Type
void Student::set_Degree_Type(degree degree_program)
{

	m_Degree_Type = degree_program;
	
}

degree Student::get_Degree_Type() {
	return m_Degree_Type;
	
	/*if (m_Degree_Type == 0) {
		return SOFTWARE;
	}
	else if (m_Degree_Type == 1) {
		return SECURITY;
	}
	else if (m_Degree_Type == 2) {
		return NETWORK;
	}
	*/
}


void Student::print()
{
	std::cout << m_ID << ", " << m_First_Name << "  " << m_Last_Name << ", " << m_Email_Address << ", "
		      << m_Age << ", " << m_Days_In_Course[0] << ", " << m_Days_In_Course[1] << ", " << m_Days_In_Course[2]
			  << ", " << m_Degree_Type << "\n";
}
