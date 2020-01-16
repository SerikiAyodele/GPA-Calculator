//Driver.cpp
#include <iostream>
#include <iomanip>  /*/ -----v------
//For formatting of output(used in the GPA to display 2 decimal places)*/
#include "GPA.h"
using namespace std; /*/INDICATES WHERE THE STANDARD LIBRARY IS*/

int main()
{
	char name[100];  //Name as single entity
	int NoOfCourse = 0;

	char coursecode[100][6];
	/*  Here, coursecode is made as an array
	    with two dimensions. The first ([100]) holds the number of courses
		that's attempted and the second ([6]) holds the characters that make
		up the name itsesf as a "course code".

	*/
	int courseunit[100];
	char grade[100];
	
	GetDetails(name, &NoOfCourse, coursecode, courseunit, grade);
	CalcGP(&NoOfCourse, coursecode, courseunit, grade);
	PrintResult(name, &NoOfCourse, coursecode, courseunit, grade);
	
	cout << endl << endl;
	system("pause");
	return 0; 
}
//na wa o