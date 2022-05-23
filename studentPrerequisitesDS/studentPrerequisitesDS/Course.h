#pragma once
#include <iostream>
#include<string.h>
#include<vector>

using namespace std;

class Course
{

public:
	string name;
	string code;
	int maxOfStudent;
	int hours;
	vector<string>listOfPrerequists;


	Course();
	~Course();
	string toString();

	void addListOfPrerequisties(string prerquistiesOfCourse);


};

