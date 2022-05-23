#pragma once
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include<unordered_map>
#include "Student.h"

using namespace std;


class Admin
{
private:

	string name;
	string password;

public:

	Admin();
    ~Admin();

	void setName(string name);
	void setPassword(string password);
	string getName();
	string getPassword();

	string logIn(unordered_map <string, Admin> admin);
	void addNewStudent(unordered_map<string, Student> &student);
	void addNewCourse(unordered_map<string, Course>& course);
	void enterCoursePrerequisite(unordered_map<string, Course> &course);
	void viewListOfStudInSpecificCourse(unordered_map<string, Course> course , unordered_map<string, Student> student);
	void viewListOfCourseInSpecificStudent(unordered_map<string, Student> student);  // finished and progressed
	void editAllCourseData(unordered_map<string, Course>& course);
	void AcceptTheRegisterOfCourse(unordered_map<string, Student>& student, unordered_map<string, Course> course);
};

