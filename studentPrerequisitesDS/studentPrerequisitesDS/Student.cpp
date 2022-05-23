#include "Student.h"
using namespace std;

Student::Student()
{
}

Student::~Student()
{
}

void Student::setName(string name)
{
	this->name = name;
}

void Student::setId(string id)
{

	this->id = id;
}

void Student::setPassword(string password)
{
	this->password = password;
}

void Student::setFinishedCourses(vector<string> finishedCourses)
{
	this->finishedCourses = finishedCourses;

}

void Student::setCoursesInProgress(vector<string> coursesInProgress)
{
	this->coursesInProgress = coursesInProgress;
}

void Student::addFinishedCourse(string courseFinished)
{
	finishedCourses.push_back(courseFinished);
	
}

void Student::addNewCourseInProgress(string courseInProgress)
{
	coursesInProgress.push_back(courseInProgress);
}

void Student::setAcademicYear(int academicYear)
{
	this->academicYear = academicYear;
}

string Student::getName()
{
	return name;
}

string Student::getId()
{
	return id;
}

string Student::getPassword()
{
	return password;
}

vector<string> Student::getFinishedCourses()
{
	return finishedCourses;
}

vector<string> Student::getCoursesInProgress()
{
	return coursesInProgress;
}

int Student::getAcademicYear()
{
	return academicYear;
}

string Student::logInStudent(unordered_map<string, Student> student)
{
	string user, pass;
	unordered_map <string, Student> ::iterator it;
	cout << "\t\t\t\t LOGIN PAGE ...\n\n\n\n";
	cout << "\tEnter Username :: ";
	cin.ignore();
	getline(cin, user);
	cout << "\n\tEnter Password :: ";
	cin >> pass;

	it = student.find(user);
	
	while (student[user].getPassword() != pass || it == student.end())
	{
		system("CLS");
		cout << "\t Wrong Username Or Password , Please try again ....\n\n";
		cout << "******************************************************\n\n";
		cout << "\tEnter Username :: ";
		cin >> user;
		cout << "\n\tEnter Password :: ";
		cin >> pass;

	  it = student.find(user);
	}
	
	return user;
}

void Student::viewListOfAllAvailableCourses(unordered_map<string, Course> course, Student stud)
{
	bool flag = true;
	int counter = 0;
	unordered_map <string, Course> ::iterator listOfCourse= course.begin();
	system("CLS");
	cout << "\n\n\t\t THE List Of Available Courses is \n" << endl;
	cout << "_________________________________________________________________\n" << endl;
	for (; listOfCourse != course.end(); listOfCourse++)
	{
		flag = theAvailableCourse(listOfCourse->second, stud);
		Course currCourse = listOfCourse->second;
		for(int i = 0 ; i < stud.getFinishedCourses().size();i++  )
		{
			if (listOfCourse->second.name == stud.getFinishedCourses()[i])
			{
				flag = false;
				break;
			}
		}
		for (int i = 0; i < stud.getCoursesInProgress().size(); i++)
		{
			if (listOfCourse->second.name == stud.getCoursesInProgress()[i])
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			counter++;
			cout << counter << " ---->  Name of Course : " << currCourse.name << " , Code : " << currCourse.code << " , Hours : " << currCourse.hours << endl << endl;
		}
	}
	
	if (counter == 0)
	{
		cout << "there Is No Available Course \n" << endl;
	}
	cout << endl << endl << "______________________________________________________________\n\n";
}

void Student::viewDetailsOfSpecificCourse(unordered_map<string, Course> course)
{
	string nameOfCourse;
	int counter = 0;
	unordered_map<string, Course>::iterator it;
	vector<string>::iterator itv;
	std::cout << "Enter the name of course that you search for : ";
	std::cin >> nameOfCourse;
	cout << endl << "*****************************************************\n\n\n";
	it = course.find(nameOfCourse);
	if (it != course.end())
	{
		std::cout << " the Name Of Course Is :  " << it->second.name << endl << endl;
		std::cout << " the Code Of Course Is :  " << it->second.code << endl << endl;
		std::cout << " the Number Of Course's Hours Is :  " << it->second.hours << endl << endl;
		std::cout << " the list of Course's Preriquistes Is : " << endl;
		cout << "__________________________________________\n\n";
		for (itv = it->second.listOfPrerequists.begin(); itv != it->second.listOfPrerequists.end(); itv++)
		{
			if(*itv == "null")
			{
				cout << " There is NO prerequisites for this Course \n\n" << endl ;
				break;
			}
			else
			{
				counter++;
				std::cout << counter << " - " << *itv << endl << endl;
			}
		}
			
	}
	else
	{
		std::cout << "\n\n -X- course Not Found.... \n" << endl;
	}
}

void Student::registForCourse(unordered_map<string, Course> course, string username , unordered_map<string, Student> &student)
{
	unordered_map<string, Course> :: iterator it;
	cout << "\t\t\t\t\t Register Page ..\n";
	cout << "________________________________________________________________\n\n\n";

	cout << " Enter The Name of Courses that You Want ... \n";
	cout << "____________________________________________\n" << endl;
	string text;
	cin.ignore();
	getline(cin, text);
    it = course.find(text);
		if (it != course.end())
		{
			student[username].requistesCourse.clear();
			student[username].requistesCourse.push_back(text);
		}
		else
		{
		    cout << "\n\nthe Course is Not Found .... \n\n";
		}
	
}

void Student::viewOwnCourse(unordered_map<string, Student> student , string username)
{
	
	unordered_map<string,Student>::iterator it;
	it = student.find(username);
	if (it != student.end())
	{
		cout << " \tYour Fininshed Courses Is : \n\n";
		cout << "*********************************************" << endl;
		vector<string> vecFinished , vecCurrent;
		vecFinished = student[name].getFinishedCourses();
		for ( int i = 0; i < vecFinished.size()  ; i++)
		{
			if (vecFinished[i] == "null")
			{
				cout << "No Avaliable Courses yet " << endl;
				break;
			}
			else
			{
				cout << i + 1 << "----> " << vecFinished[i] << endl;
			}
			
		}

		cout << "\n\n____________________________________________________________________\n\n";
		cout << "\t Your Progress Courses Is : \n\n";
		cout << "*********************************************" << endl;
		vecCurrent = student[name].getCoursesInProgress();
		for (int i = 0; i < vecCurrent.size(); i++)
		{

			if (vecCurrent[i] == "null")
			{
				cout << "No Avaliable Courses yet " << endl;
				break;
			}
			else
			{
				cout << i + 1 << "----> " << vecCurrent[i] <<  "\n" <<endl;
			}
		}

	}
	else
	{
		cout << "the Student is Not Found .... ";
	}
}

void Student::editOwnData(string nameOfUser, unordered_map<string, Student> &stud)
{
Change_Menu:
	int choice, value;;
	string changeValue;
	cout << "Please , Enter the number of data that you want to change it : " << endl;
	cout << "-----------------------------------------------------------" << endl;
	cout << "1- Name \n";
	cout << "2- ID \n";
	cout << "3- Password \n";
	cout << "4- Academic Year \n";
	cout << "5- Student Operation Menu \n";
	cout << "\n ~~~~> ";
	cin >> choice;


	switch (choice)
	{
		stud[nameOfUser].requistesCourse.push_back("null");
	case 1:
		cout << "Please , Enter Your Change :  ";
		cin >> changeValue;
		stud[nameOfUser].setName(changeValue);
		cout << "**** Your Change Done Successfully .... ****\n\n\n" ;
		cout << "~~~~~> Press enter key to go back to menu of operation.";
		_getch();
		system("CLS");
		goto Change_Menu;
		break;
	case 2:
		cout << "Please , Enter Your Change :  ";
		cin >> changeValue;
		stud[nameOfUser].setId(changeValue);
		cout << "**** Your Change Done Successfully .... ****\n\n\n";
		cout << "~~~~~> Press enter key to go back to menu of operation.";
		_getch();
		system("CLS");
		goto Change_Menu;
		break;
	case 3:
		cout << "Please , Enter Your Change :  ";
		cin >> changeValue;
		stud[nameOfUser].setPassword(changeValue);
		cout << "**** Your Change Done Successfully .... ****\n\n\n";
		cout << "~~~~~> Press enter key to go back to menu of operation.";
		_getch();
		system("CLS");
		goto Change_Menu;
		break;
	case 4:
		cout << "Please , Enter Your Change :  ";
		cin >> value;
		stud[nameOfUser].setAcademicYear(value);
		cout << "**** Your Change Done Successfully .... ****\n\n\n";
		cout << "~~~~~> Press enter key to go back to menu of operation.";
		_getch();
		system("CLS");
		goto Change_Menu;
		break;
	case 5:
		return ;

	default:
		cout << "Unavailable Number , please try again  ";
		_getch();
		system("CLS");
		goto Change_Menu;
		break;
	}
}

bool Student::theAvailableCourse(Course curCourse , Student stud)
{
	bool flag = true , flag2 ;
	vector<string> :: iterator  listOfPrereq = curCourse.listOfPrerequists.begin() ;
	for ( ; listOfPrereq != curCourse.listOfPrerequists.end(); listOfPrereq++)  /// CALC1 , PHYS1
	{
		/*finishedCourse = stud.getFinishedCourses().begin();
		result = find(stud.getFinishedCourses().begin(), stud.getFinishedCourses().end(), *listOfPrereq);*/
		if (*listOfPrereq == "null" )
		{
			flag = true;
			break;
		}
		flag2 = false;
		for (int i = 0; i < stud.getFinishedCourses().size(); i++)
		{
			if (stud.getFinishedCourses()[i] == *listOfPrereq)
			{
				flag2 = true;
				break;
			}
		}
		/*for (finishedCourse = stud.getFinishedCourses().begin(); finishedCourse != stud.getFinishedCourses().end(); finishedCourse++) 
		{
			if (*finishedCourse == *listOfPrereq)
			{
				flag2 = true;
				break;
			}
		}*/
		if (flag2)
		{
			flag = true;
		}
		else
		{
			flag = false;
			break;
		}
		
	}
	return flag;
}
