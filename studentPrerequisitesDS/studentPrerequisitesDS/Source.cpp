#include <iostream>
#include <fstream>
#include <unordered_map>
#include <conio.h>
#include <windows.h>
#include<cstdlib>
#include "Utils.h"
#include "Admin.h"
#include "Student.h"
#include "Course.h"


using namespace std;

int main()
{


	cout << "\t\t----------------------------------------------------------------------------------------" << endl;
	cout << "\t\t\t\t\tStudent prereqisites Subjects Management System\t\t" << endl;
	cout << "\t\t----------------------------------------------------------------------------------------\n\n" << endl;

	Utils* utils = Utils::getinstance();

	Admin newAdmin;
	Student newStudent;


	unordered_map<string, Admin> admin;
	unordered_map<string, Course> course;
	unordered_map<string, Student> student;

	utils->mappingStudentLineToObj(student);
	utils->mappingCourseLineToObj(course);
	utils->mappingAdminLineToObj(admin);

	int choiceOfMenue, numOfOperation;
	string logIn;

Top_menu: choiceOfMenue = utils->loginChoice();

	if (choiceOfMenue == 1)
	{
		system("CLS");
		logIn = newAdmin.logIn(admin);
	Admin_Menu:
		system("CLS");
		numOfOperation = utils->adminOperation();
		if (numOfOperation == 1)
		{
			system("CLS");
			admin[logIn].addNewStudent(student);
			utils->mappingObjToStudentLine(student);
			cout << "~~~~~> Press enter key to go back to menu of operation." << endl;
			_getch();
			system("CLS");
			goto Admin_Menu;
		}
		if (numOfOperation == 2)
		{
			system("CLS");
			admin[logIn].addNewCourse(course);
			utils->mappingObjToCourseLine(course);
			cout << "~~~~~> Press enter key to go back to menu of operation." << endl;
			_getch();
			system("CLS");
			goto Admin_Menu;
		}
		if (numOfOperation == 3)
		{
			system("CLS");
			admin[logIn].editAllCourseData(course);
			utils->mappingObjToCourseLine(course);
			cout << "~~~~~> Press enter key to go back to menu of operation." << endl;
			_getch();
			system("CLS");
			goto Admin_Menu;
		}
		if (numOfOperation == 4)
		{
			system("CLS");
			admin[logIn].enterCoursePrerequisite(course);
			utils->mappingObjToCourseLine(course);
			cout << "~~~~~> Press enter key to go back to menu of operation." << endl;
			_getch();
			system("CLS");
			goto Admin_Menu;
		}
		if (numOfOperation == 5)
		{
			system("CLS");
			admin[logIn].viewListOfCourseInSpecificStudent(student);
			utils->mappingObjToCourseLine(course);
			cout << "~~~~~> Press enter key to go back to menu of operation." << endl;
			_getch();
			system("CLS");
			goto Admin_Menu;
		}
		if (numOfOperation == 6)
		{
			system("CLS");
			admin[logIn].viewListOfStudInSpecificCourse(course , student);
			utils->mappingObjToCourseLine(course);
			cout << "~~~~~> Press enter key to go back to menu of operation." << endl;
			_getch();
			system("CLS");
			goto Admin_Menu;
		}
		if (numOfOperation == 7)
		{
			system("CLS");
			admin[logIn].AcceptTheRegisterOfCourse(student,course);
			utils->mappingObjToStudentLine(student);
			cout << "~~~~~> Press enter key to go back to menu of operation." << endl;
			_getch();
			system("CLS");
			goto Admin_Menu;
		}
		else
		{
			utils->mappingObjToStudentLine(student);
			utils->mappingObjToCourseLine(course);
			utils->mappingObjToAdminLine(admin);
			system("CLS");
			goto Top_menu;
		}
	}
    else if (choiceOfMenue == 2)
	{
		system("CLS");
		logIn = newStudent.logInStudent(student);
	Student_Menu:
		system("CLS");
		numOfOperation = utils->studentOperation();
		if (numOfOperation == 1)
		{
			system("CLS");
			student[logIn].viewListOfAllAvailableCourses(course, student[logIn]);
			cout << "~~~~~> Press enter key to go back to menu of operation.";
			_getch();
			system("CLS");
			goto Student_Menu;
		}
		if (numOfOperation == 2)
		{
			system("CLS");
			student[logIn].viewDetailsOfSpecificCourse(course);
			cout << "~~~~~> Press enter key to go back to menu of operation.";
			_getch();
			system("CLS");
			goto Student_Menu;
		}
		if (numOfOperation == 3)
		{
			system("CLS");
			student[logIn].registForCourse(course , logIn , student);
			utils->mappingObjToStudentLine(student);
			cout << "~~~~~> Press enter key to go back to menu of operation.";
			_getch();
			system("CLS");
			goto Student_Menu;
		}
		if (numOfOperation == 4)
		{
			system("CLS");
			student[logIn].viewOwnCourse(student , logIn);
			cout << "~~~~~> Press enter key to go back to menu of operation.";
			_getch();
			system("CLS");
			goto Student_Menu;
		}
		if (numOfOperation == 5)
		{
			system("CLS");
			student[logIn].editOwnData(logIn, student);
			utils->mappingObjToStudentLine(student);
			cout << "~~~~~> Press enter key to go back to menu of operation.";
			_getch();
			system("CLS");
			goto Student_Menu;
		}
		
		else
		{
			utils->mappingObjToStudentLine(student);
			utils->mappingObjToCourseLine(course);
			utils->mappingObjToAdminLine(admin);
			system("CLS");
			goto Top_menu;
		}
	}
	else
	{
		utils->mappingObjToStudentLine(student);
		utils->mappingObjToCourseLine(course);
		utils->mappingObjToAdminLine(admin);
		exit(0);
	}



	////student.insert({ newStudent.getId(),newStudent});
	//string line1 , line2;
	//unordered_map<string, Student>::iterator it;
	//for (it = student.begin(); it != student.end(); it++)
	//{
	//	
	//	cout << "Name Of student : " << it->second.getName() << "  , the password :" << it->second.getPassword() << endl;
	//	cout << "  list of finished :\n\n";
	//	line1 =utils->getLineFromVector(it->second.getFinishedCourses());
	//	cout << line1 << endl;
	//	cout << "  list of progress :\n\n";
	//	line2 = utils->getLineFromVector(it->second.getCoursesInProgress());
	//	cout << line2 << endl << "---------------------------------------------------" << endl;
	//}
 //   utils->mappingObjToStudentLine(student);

}