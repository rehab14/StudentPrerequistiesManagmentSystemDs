#include "Admin.h"
using namespace std;

Admin::Admin()
{

}

Admin::~Admin()
{

}



void Admin::setName(string name)
{
	this->name = name;
}

void Admin::setPassword(string password)
{
	this->password = password;
}

string Admin::getName()
{
	return name;
}

string Admin::getPassword()
{
	return password;
}

string Admin::logIn(unordered_map<string, Admin> admin)
{
	string user, pass;
	cout << "\t\t\t\t LOGIN PAGE ...\n\n\n\n";
	cout << "\tEnter Username :: ";
	cin.ignore();
	getline(cin, user);
	cout << "\n\tEnter Password :: ";
	cin >> pass;

	unordered_map <string, Admin> ::iterator it;
	it = admin.find(user);
	while (admin[user].getPassword() != pass || it == admin.end())
	{

		cout << "Wrong Username or Password ... please try again" << endl;
		cout << "***********************************************" << endl;
		cout << "please, Enter your name: " << endl;
		cin >> user;
		cout << "please, Enter your password: " << endl;
		cin >> pass;
		it = admin.find(user);

	}
	return user;
}

void Admin::addNewStudent(unordered_map<string, Student> &student)
{
	int num=0, valueint=0;
	string value , name;
	unordered_map <string, Student>::iterator it;
	cout << "Please , Enter the Name Of Student:";
	cin >> value;
	name = value;
	it = student.find(name);
	if (it == student.end())
	{
		student[name].requistesCourse.push_back("null");
		student[name].setName(value);
		cout << "Please , Enter A Password :";
		cin >> value;
		student[name].setPassword(value);
		value = "";
		cout << "Please , Enter Id :";
		cin >> value;
		student[name].setId(value);
		value = "";
		cout << "Please , Enter the Academic Year :";
		cin >> valueint;
		student[name].setAcademicYear(valueint);
		cout << " the num of Fininshed courses :";
		cin >> num;
		if (num == 0)
		{
			student[name].addFinishedCourse("null");
		}
		else
		{
			for (int i = 0; i < num; i++)
			{
				string item;
				cout << "please , enter the Name of course :";
				cin >> item;
				student[name].addFinishedCourse(item);
			}
		}
		num = 0;
		cout << " the num of Current courses :";
		cin >> num;
		if (num == 0)
		{
			student[name].addNewCourseInProgress("null");
		
		}
		else
		{
			for (int i = 1 ; i <= num; i++)
			{
				cout << "Please , Enter course that progress: ";
				string item;
				cin >> item;
				student[name].addNewCourseInProgress(item);
			}
			cout << endl << endl;
		}
	cout << "\t**** Adding Done Successfully ...***\n";
	cout << "__________________________________________\n\n";
	}
	else
	{
		cout << " the Student is allready exist ...... \n\n\n";
	}
}

void Admin::addNewCourse(unordered_map<string, Course>& course)
{
	int num;
	Course newCourse;
	unordered_map <string, Course>::iterator it;
	cout << "please , Enter the name of course : ";
	cin >> newCourse.name;
	string name = newCourse.name;
	it = course.find(newCourse.name);
	if (it == course.end())
	{
		cout << "please , enter the code of course : ";
		cin >> newCourse.code;
		cout << "please , enter the max number of student in this course : ";
		cin >> newCourse.maxOfStudent;
		cout << "please , enter the number of hours of course : ";
		cin >> newCourse.hours;
		cout << " the num of prerequisties of this course : ";
		cin >> num;
		if (num == 0)
		{
			string itemnull = "null";
			newCourse.addListOfPrerequisties(itemnull);
			
		}
		else
		{
			for (int i = 0; i < num; i++)
			{
				string item;
				cout << "please , enter the prerequisties of course :";
				cin >> item;
				newCourse.addListOfPrerequisties(item);
			}
			cout << endl << endl ;

		}
		course[name] = newCourse;
		cout << "\t**** Adding Done Successfully ...***\n";
		cout << "__________________________________________\n\n";

	}
	else
	{
		cout << "the course is allready exist " << endl;
	}
}

void Admin::enterCoursePrerequisite(unordered_map<string, Course> &course)
{

	string nameOfCourse;
	unordered_map <string, Course>::iterator it;
	cout << "\t\t\t\t\t Adding Prerequistes in Specific Course  ..\n";
	cout << "\t\t\t---------------------------------------------------------\n\n";
	cout << "Please , Enter The Name of Course : ";
	cin >> nameOfCourse;
	it = course.find(nameOfCourse);
	if (it != course.end())
	{
		int num = 0;
		cout << "Enter THe Number Of Prerequistes Of This Course : ";
		cin >> num;
		course[nameOfCourse].listOfPrerequists.clear();
		for (int i = 0; i < num; i++)
		{
			string item;
			cout << "please , enter the prerequisties of course : ";
			cin >> item;
			course[nameOfCourse].addListOfPrerequisties(item);
		}
		cout << "\n\n\n\t\t**** Adding Done Successfully ...***\n";
		cout << "__________________________________________\n\n";
		cout << endl ;
	}
	else
	{
		cout << "This Course Not Found... " << endl << endl;
	}
}

void Admin::viewListOfStudInSpecificCourse(unordered_map<string, Course> course , unordered_map<string, Student> student)
{
	unordered_map<string, Student>::iterator itS;
	unordered_map<string, Course>::iterator itC;
	string nameOfCourse;
	int counter = 0;
	cout << "\t\t\t\t\t The List Of Student Page ..\n";
	cout << "\t\t\t---------------------------------------------------------\n\n";
	cout << "\nPlease , Enter the Name Of Course That You Want : ";
	cin >> nameOfCourse;
	itC = course.find(nameOfCourse);
	if(itC != course.end())
	{ 
		cout << "\nThe List of ALL Student in ' " << nameOfCourse << " ' Course is : " << endl << endl;
		cout << "-----------------------------------------------------------------------\n";
		
		for ( itS = student.begin(); itS != student.end(); itS++)
		{
			bool flag = false;
			for (int i = 0; i < itS->second.getCoursesInProgress().size(); i++)
			{
				if (itS->second.getCoursesInProgress()[i] == nameOfCourse)
				{
					flag = true;
					break;
				}
			}
			if (flag)
			{
				counter++;
				cout << counter << " - " <<  itS->second.getName()  << " -------->  ID :" << itS->second.getId()  << " -------->  Academic Year : " << itS->second.getAcademicYear() << endl << endl;
			}
		}
		if (counter == 0)
		{
			cout << "\n\n Sorry , No Student Availabel IN This Course.... ";
		}
	}
	else
	{
		cout << "\n\n Sorry , Course not found.... ";
	}
	cout << "\n\n\n";
}

void Admin::viewListOfCourseInSpecificStudent(unordered_map<string, Student> student )
{
	unordered_map<string, Student>::iterator it;
	string nameOfStudent;
	int counter = 0;
	cout << "\t\t\t\t\t The List Of Course Page ..\n";
	cout << "\t\t\t---------------------------------------------------------\n\n";
	cout << "\nPlease , Enter the Name Of Student That You Want : ";
	cin >> nameOfStudent;
	it = student.find(nameOfStudent);
	if (it != student.end())
	{
		cout << "\nFinished course of Student ' " << nameOfStudent << " ' is : " << endl << endl;
		cout << "-----------------------------------------------\n";
		for (int i = 0 ; i < student[nameOfStudent].getFinishedCourses().size(); i++)
		{
			counter++;
			cout << counter << " - " << student[nameOfStudent].getFinishedCourses()[i] << endl;
		}
		cout << "\n\n\n*************************************************************************\n\n\n";
		counter = 0;
		cout << "The Current Courses of Student ' " << nameOfStudent << " ' is : " << endl << endl;
		cout << "-----------------------------------------------\n";
		for (int i = 0; i < student[nameOfStudent].getCoursesInProgress().size(); i++)
		{
			counter++;
			cout << counter << " - " << student[nameOfStudent].getCoursesInProgress()[i] << endl;
		}

	}
	else
	{
		cout << " Sorry , Student not found.... \n";
	}
	cout << "\n\n\n";
}

void Admin::editAllCourseData(unordered_map<string, Course>& course)
{
	unordered_map<string, Course>::iterator it;
	string nameOfCourse;
	cout << "What is the course that you want : ";
	cin >> nameOfCourse;
	it = course.find(nameOfCourse);
	if (it != course.end())
	{
	Change_menu:
		int choice, value;;
		string changeValue;
		cout << "Please , Enter the num of data that you want to change it : " << endl;
		cout << "-----------------------------------------------------------" << endl;
		cout << "1- Name Of Course \n";
		cout << "2- Code Of Course \n";
		cout << "3- Max Number Of Student \n";
		cout << "4- Hour Of Course \n";
		cout << "5- list Of Prerequisites Of Course \n";

		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Please , Enter Your Change :  ";
			course[nameOfCourse].name.clear();
			cin >> changeValue;
			course[nameOfCourse].name = changeValue;
			changeValue = "";
			cout << "**** Your Change Done Successfully .... ****\n\n\n";
			cout << "~~~~~> Press enter key to go back to menu of operation.";
			_getch();
			system("CLS");
			goto Change_menu;
			break;
		case 2:
			cout << "Please , Enter Your Change :  ";
			cin >> changeValue;
			course[nameOfCourse].code = changeValue;
			cout << "**** Your Change Done Successfully .... ****\n\n\n";
			cout << "~~~~~> Press enter key to go back to menu of operation.";
			_getch();
			system("CLS");
			goto Change_menu;
			break;
		case 3:
			cout << "Please , Enter Your Change :  ";
			cin >> value;
			course[nameOfCourse].maxOfStudent = value;
			value = 0;
			cout << "**** Your Change Done Successfully .... ****\n\n\n";
			cout << "~~~~~> Press enter key to go back to menu of operation.";
			_getch();
			system("CLS");
			goto Change_menu;
			break;
		case 4:
			cout << "Please , Enter Your Change :  ";
			cin >> value;
			course[nameOfCourse].hours = value;
			cout << "**** Your Change Done Successfully .... ****\n\n\n";
			cout << "~~~~~> Press enter key to go back to menu of operation.";
			_getch();
			system("CLS");
			goto Change_menu;
			break;

		default:
			cout << "~~~~~> Press enter key to go back to menu of operation.";
			_getch();
			system("CLS");
			break;
		}
	}
	else
	{
		cout << " Sorry , course not found.... \n";
	}
}

void Admin::AcceptTheRegisterOfCourse(unordered_map<string, Student> &student , unordered_map<string, Course> course)
{
	unordered_map<string, Student>::iterator itS;
	cout << "\nThe List of Requisties : " << endl << endl;
	cout << "-----------------------------------------------------------------------\n";
	int counter = 1 , counterr;
	for (itS = student.begin(); itS != student.end(); itS++)
	{
		for (int i = 0; i < itS->second.requistesCourse.size(); i++)
		{
			counterr = 0;
			if (itS->second.requistesCourse[i] == "null")
			{
				break;
			}
			bool flag = true;
			for (int j = 0; j < itS->second.getFinishedCourses().size(); j++)
			{
				if (itS->second.getFinishedCourses()[i] == "null")
				{
					break;
				}
				if (itS->second.requistesCourse[i] == itS->second.getFinishedCourses()[j])
				{
					
					flag = false;
					break;
				}
			}
			if(flag)
			{
				counterr++;
				cout << counter << " - " << itS->second.getName() << " { ID :" << itS->second.getId() << " } -------->  " << counterr << " - " << itS->second.requistesCourse[i] << endl << endl;
			}
		}
		counter++;
		
	}
	Accepting_course:
	string stud, sub;
	unordered_map<string, Student>::iterator it;
	unordered_map<string, Course>::iterator it2;
	cout << "\n---------------------------------------------------------------------------------------------\n";
	cout << "Please , Enter The Name Of Student That You Want From This List: ";
	cin >> stud;
	cout << "\n__________________________\n";
	it = student.find(stud);
	if ( it != student.end() )
	{
		cout << "Please , Enter The Name Of Course That Belongs to THis Student: ";
		cin >> sub;
		cout << "\n********************************************\n";
		it2 = course.find(sub);
		if (it2 != course.end())
		{
			int numofelement;
			bool flagOfList = false, flagOfFinished = false;
			for (int i = 0; i < it->second.requistesCourse.size(); i++)
			{
				if (it->second.requistesCourse[i] == it2->second.name)
				{
					
					numofelement = i;
					flagOfList = true;
					break;
				}
			}
			if (flagOfList)
			{
				flagOfFinished = false;
				for (int i = 0; i < it2->second.listOfPrerequists.size(); i++)
				{
					if (it2->second.listOfPrerequists[i] == "null")
					{
						flagOfList = true;
						flagOfFinished = true;
						break;
					}
					else
					{
						for (int j = 0; j < it->second.getFinishedCourses().size(); j++)
						{
							if (it->second.getFinishedCourses()[j] == "null")
							{
								flagOfFinished = true;
								break;
							}
							if (it2->second.listOfPrerequists[i] == it->second.getFinishedCourses()[j])
							{
								
								flagOfFinished = true;
							}
						}
					}
				
					
				}
				
			}
			if (flagOfFinished == true && flagOfList == true)
			{
				cout << "\n***This Coure Accepted***\n ";
				for (int i = 0; i < it->second.getCoursesInProgress().size(); i++)
				{
					if (it->second.getCoursesInProgress()[i] == "null")
					{
						it->second.getCoursesInProgress().pop_back();
						break;
					}
					else
						break;
				}
				it->second.addNewCourseInProgress(it2->second.name); 
				it->second.requistesCourse.erase(it->second.requistesCourse.begin() + numofelement);
				if (it->second.requistesCourse.empty())
				{
					it->second.requistesCourse.push_back("null");
				}
			}
			else
			{
				cout << "\nThis Coure Rigected .....\n";
				it->second.requistesCourse.erase(it->second.requistesCourse.begin() + numofelement);
				if (it->second.requistesCourse.empty())
				{
					it->second.requistesCourse.push_back("null");
				}

			}

		}
		else
		{
			cout << " Sorry , Course not found.... \n";
		}

	}
	else
	{
		cout << " Sorry , Student not found.... \n";
	}
	cout << "---------------------------------------------------\n";
	cout << endl ;
	cout << " Did you Want To Accept Another Course  \n";
	cout << " 1- YES \n";
	cout << " 2- No \n";
    int res;
	cin >> res;
	if (res == 1)
	{
		goto Accepting_course;
	}

}
