#include "Course.h"






Course::Course()
{
	hours = 0;
	maxOfStudent =0;
}

Course::~Course()
{

}

string Course::toString()
{
	return string();
}

void Course::addListOfPrerequisties(string prerquistiesOfCourse)
{
	listOfPrerequists.push_back(prerquistiesOfCourse);
}
