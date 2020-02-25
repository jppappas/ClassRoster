#pragma once
#include <iostream>
#include <vector>
#include "degree.h"
class Student
{
private:

	std::string m_ID;
	std::string m_First_Name;
	std::string m_Last_Name;
	std::string m_Email_Address;
	unsigned int m_Age;
	std::vector<int> m_Days_In_Course;
	degree m_Degree_Type;

public:
	Student();

	//Setting and Getting methods for variables
	void set_ID(std::string ID);
	std::string get_ID();

	void set_First_Name(std::string First_Name);
	std::string get_First_Name();

	void set_Last_Name(std::string Last_Name);
	std::string get_Last_Name();

	void set_Email_Address(std::string Email_Address);
	std::string get_Email_Address();

	void set_Age(unsigned int Age);
	unsigned int get_Age();

	void set_Days_In_Course(int Day1, int Day2, int Day3);
	void set_Days_In_Course(const std::vector<int>& input_vector);
	const std::vector<int>& get_Days_In_Course();

	virtual void print();
	
	
	void set_Degree_Type(degree degree_type);
	virtual degree get_Degree_Type() = 0;

};

