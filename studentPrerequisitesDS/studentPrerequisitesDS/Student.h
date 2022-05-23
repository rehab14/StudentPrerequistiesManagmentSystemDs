#pragma once
#include<iostream>
#include<cstdlib>
#include <string>
#include <unordered_map>
#include <iterator>
#include<vector>
#include <conio.h>
#include "Course.h"


using namespace std;


class Student
{
 
private:
	string name;
	string id;
	string password;
	vector <string> finishedCourses;
	vector <string> coursesInProgress;
    int academicYear; 

public:
	Student();
	~Student();
	vector <string> requistesCourse; ////
public:
	void setName(string name);
	void setId(string id);
	void setPassword(string password);
	void setFinishedCourses(vector<string> finishedCourses);
	void setCoursesInProgress(vector<string> coursesInProgress);
	void addFinishedCourse(string courseFinished);
	void addNewCourseInProgress(string courseInProgress);
	void setAcademicYear(int academicYear);
public:
	string getName();
	string getId();
	string getPassword();
	vector<string> getFinishedCourses();
	vector<string> getCoursesInProgress();
	int getAcademicYear();
public:
	string logInStudent(unordered_map<string, Student> student);
	void viewListOfAllAvailableCourses(unordered_map<string, Course> course, Student stud);
	void viewDetailsOfSpecificCourse(unordered_map<string, Course> course);
	void registForCourse(unordered_map<string, Course> course, string username , unordered_map<string, Student> &student);
	void viewOwnCourse(unordered_map<string, Student> student , string username);
	void editOwnData(string nameOfUser, unordered_map<string, Student>& stud);
	bool theAvailableCourse(Course curCourse  , Student stud);


};

