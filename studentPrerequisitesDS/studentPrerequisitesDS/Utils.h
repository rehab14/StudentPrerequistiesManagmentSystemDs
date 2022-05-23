#pragma once
#include <iostream>
#include <fstream>
#include<cstdlib>
#include <string>
#include <vector>
#include "Admin.h"
#include"Student.h"
#include"Course.h"

using namespace std;

class Utils
{

private:

	Utils();

public:

	static Utils* instance;
	static Utils* getinstance();

	string DATABASE_PATH = "C:/Users/AS/source/repos/studentPrerequisitesDS/studentPrerequisitesDS/databaseOfProject/";

	void mappingCourseLineToObj(unordered_map <string, Course>& course); //rahma
	void mappingStudentLineToObj(unordered_map<string, Student>& Stud);   /////zainab
	void mappingAdminLineToObj(unordered_map<string, Admin>& admin);  //mohamed

	void mappingObjToAdminLine(unordered_map<string, Admin> newAdmin); //mohamed
	void mappingObjToCourseLine(unordered_map<string, Course> newcourse); //rahma
	void mappingObjToStudentLine(unordered_map<string, Student> newStudent); ////zainab

	vector<string> getVectorFromLine(string line);
	string getLineFromVector(vector<string> vectorcourse);

	int loginChoice();
	int adminOperation();
	int studentOperation();

};

