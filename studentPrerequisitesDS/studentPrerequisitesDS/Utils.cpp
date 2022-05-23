#include "Utils.h"
using namespace std;


Utils::Utils()
{
}


Utils* Utils::instance = 0;

Utils* Utils::getinstance() {
	if (instance == NULL)
	{
		instance = new Utils;
	}
	return instance;
}

vector<string> Utils::getVectorFromLine(string line)
{
	// VECTOR SHOULD BE LIKE THAT!!!! -> [i,,,]
	line.pop_back();
	line.erase(line.begin());
	string item = "";
	vector<string> items;
	for (int i = 0; i < line.size(); i++) {
		
		if (line[i] == ',') {
			items.push_back(item);
			item = "";
		}
		else {
			item += line[i];   
		}
		if (i == line.size()-1)
		{
			items.push_back(item);
			break;
		}
	}
	return items;
}

string Utils::getLineFromVector(vector<string> vectorcourse)
{
	vector<string> ::iterator it;
	string line = "";
	for ( it = vectorcourse.begin(); it != vectorcourse.end(); it++)
	{
		line += *it;
		line += ",";
	}
	line.pop_back();
	return line ;
}


void Utils::mappingCourseLineToObj(unordered_map<string, Course>& course)
{
	ifstream input(DATABASE_PATH + "courses.txt");
	string line;
	while (getline(input, line)) {
		int lineSize = line.size();
		Course currentCourse;
		string nameOfCourse;
		int dataMemberCnt = 0;
		string currentDataMember = "";
		//Oop | CIS250 | 1300 | [Introduction, StructuredProgramming] | 3
		for (int i = 0; i < lineSize; i++) {
			if (line[i] == '|') {
				dataMemberCnt++; 
				switch (dataMemberCnt) {
				case 1: {
					currentCourse.name = currentDataMember;
					nameOfCourse = currentDataMember;
					currentDataMember = "";
					break;
				}
				case 2: {
					currentCourse.code = currentDataMember;
					currentDataMember = "";
					break;
				}
				case 3: {
					currentCourse.maxOfStudent = stoi(currentDataMember);
					currentDataMember = "";
					break;
				}
				case 4: {

					currentCourse.listOfPrerequists = getVectorFromLine(currentDataMember);
					currentDataMember = "";
					break;
				}
				case 5: {
					currentCourse.hours = stoi(currentDataMember);
					currentDataMember = "";
					break;
				}
				}
			
			}
			else {
				if (i == lineSize - 1)
				{
					currentDataMember += line[i];
					currentCourse.hours = stoi(currentDataMember);
					currentDataMember = "";
				}
				else
				{
					currentDataMember += line[i];
				}

			}
		}
		course[nameOfCourse] = currentCourse;
	}
}

void Utils::mappingStudentLineToObj(unordered_map<string, Student>& Stud)
{

	ifstream input(DATABASE_PATH + "students.txt");
	string line;
	while (getline(input, line)) {
		int lineSize = line.size();
		int dataMemberCnt = 0;
		string userName;
		string currentDataMember = "";
		for (int i = 0; i < lineSize; i++) {
			if (line[i] == '|') {
				dataMemberCnt++;
				switch (dataMemberCnt) {
				case 1: {
					userName = currentDataMember;
					Stud[userName].setName(currentDataMember);
					currentDataMember = "";
					break;
				}
				case 2: {

					Stud[userName].setId(currentDataMember);
					currentDataMember = "";
					break;
				}
				case 3: {

					Stud[userName].setPassword(currentDataMember);
					currentDataMember = "";
					break;
				}
				case 4: {

					Stud[userName].setFinishedCourses(getVectorFromLine(currentDataMember));
					currentDataMember = "";
					break;
				}
				case 5: {

					Stud[userName].setCoursesInProgress(getVectorFromLine(currentDataMember));
					currentDataMember = "";
					break;
				}
				case 6: { ///////// 

					Stud[userName].requistesCourse = getVectorFromLine(currentDataMember);
					currentDataMember = "";
					break;

				}//////
				}

			}
			else {
				if (i == lineSize - 1) {
					currentDataMember += line[i];
					Stud[userName].setAcademicYear(stoi(currentDataMember));
					currentDataMember = "";
				}
				else {
					currentDataMember += line[i];
				}
			}
		}
	}
}

void Utils::mappingAdminLineToObj(unordered_map<string, Admin>& admin)
{
	ifstream input(DATABASE_PATH + "admins.txt");
	string line;
	while (getline(input, line)) {
		int lineSize = line.size();
		Admin currentAdmin;
		string adminName;
		int dataMemberCnt = 0;
		string currentDataMember = "";
		for (int i = 0; i < lineSize; i++)
		{
			if (line[i] == '|') {
				dataMemberCnt++;
				switch (dataMemberCnt) {
				case 1: {
					currentAdmin.setName(currentDataMember);
					adminName = currentDataMember;
					currentDataMember = "";
					break;
				}
				case 2: {
					currentAdmin.setPassword(currentDataMember);
					currentDataMember = "";
					break;
				}
				}
				currentDataMember = "";
			}
			else {
				if (i == lineSize - 1)
				{
					currentDataMember += line[i];
					currentAdmin.setPassword(currentDataMember);
					currentDataMember = "";

				}
				else {
					currentDataMember += line[i];
				}
			}
		}
		admin[adminName] = currentAdmin;
	}
}

void Utils::mappingObjToAdminLine(unordered_map<string, Admin> newAdmin)
{
	ifstream fileOpen(DATABASE_PATH + "admins.txt");
	fileOpen.clear();
	unordered_map <string, Admin>::iterator it;
	ofstream update(DATABASE_PATH + "admins.txt");
	for (it = newAdmin.begin(); it != newAdmin.end(); it++)
	{
		Admin admin = it->second;
		update << admin.getName() << "|" << admin.getPassword() << endl;
	}
	update.close();
}

void Utils::mappingObjToCourseLine(unordered_map<string, Course> newcourse)
{

	ifstream fileOpen(DATABASE_PATH + "courses.txt");
	fileOpen.clear();
	unordered_map <string, Course>::iterator it;
	vector <string>::iterator it2;
	ofstream update(DATABASE_PATH + "courses.txt");

	for (it = newcourse.begin(); it != newcourse.end(); it++)
	{
		update << it->second.name << "|" << it->second.code << "|" << it->second.maxOfStudent << "|[";
		string line ;
		for (it2 = it->second.listOfPrerequists.begin(); it2 != it->second.listOfPrerequists.end(); it2++)
		{
			if (*it2 == "null")
			{
				line += "null,";
				break;
			}
			else
			{
				line += *it2;
				line += ",";
			}
		}
		line.pop_back();
		update << line <<"]|" << it->second.hours << endl;
	}
	update.close();
}

void Utils::mappingObjToStudentLine(unordered_map<string, Student> newStudent)
{
	ifstream fileOpen(DATABASE_PATH + "students.txt");
	fileOpen.clear();
	unordered_map <string, Student>::iterator it;
	ofstream update(DATABASE_PATH + "students.txt");
	for (it = newStudent.begin(); it != newStudent.end(); it++)
	{
		
		update << it->second.getName() << "|" << it->second.getId() << "|" << it->second.getPassword() << "|[";
		string line, line2 , line3;
		line = getLineFromVector(it->second.getFinishedCourses());
		update << line << "]|[";
		line2 = getLineFromVector(it->second.getCoursesInProgress());
		update << line2 << "]|[" ;                            //////////////
		line3 = getLineFromVector(it->second.requistesCourse); //////////////
		update << line3 << "]|" << it->second.getAcademicYear() << endl;
	}
	update.close();

}

int Utils::loginChoice()
{
	int choice;
	cout << "\tEnter the Number Of Choice That you Want" << endl;
	cout << "\t__________________________________________________" << endl;
	cout << "\t__________________________________________________" << endl;
	cout << "\t1- Enter As ADMIN\n";
	cout << "\t2- Enter As Student\n";
	cout << "\t3- Exit the programme\n";
	cout << endl << "----------> ";
	cin >> choice;
	return choice;
}

int Utils::adminOperation()
{
	int choiceOfOperation;
	cout << "Enter the Number Of operation That you Want" << endl;
	cout << "*******************************************" << endl;
	cout << "\t1- Add New Student\n\n";
	cout << "\t2- Add New Course\n\n";
	cout << "\t3- Edit All Course Data\n\n";
	cout << "\t4- Enter Course Prerequisite\n\n";
	cout << "\t5- View List Of All Course In A Specific Student\n\n";
	cout << "\t6- View List Of All Student In A Specific Course\n\n";
	cout << "\t7- Accepting Courses\n\n";
	cout << "\t0- Exit\n\n";
	cout << endl << "----------> ";
	cin >> choiceOfOperation;
	return choiceOfOperation;
}

int Utils::studentOperation()
{
	int choiceOfOperation;
	cout << "Enter the Number Of operation That you Want" << endl;
	cout << "*******************************************\n\n" << endl;
	cout << "\t1- View List Of All Available Courses\n\n";
	cout << "\t2- View Details Of A Specific Course\n\n";
	cout << "\t3- Register For A Course \n\n";
	cout << "\t4- View Your Course\n\n";
	cout << "\t5- Edit Your Data\n\n";
	cout << "\t0- Exit\n\n";
	cout << endl << "----------> ";
	cin >> choiceOfOperation;
	return choiceOfOperation;
}

