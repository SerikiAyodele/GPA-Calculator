//GPA.cpp
#include <iostream>
#include <iomanip>  
#include "GPA.h"
using namespace std;



//Global variables made for the GP parameters
int GP;              // Integer variable declared for Grade Point
int UA = 0;       // Unit Attempted
int UP = 0;       // Unit Passed
int cWS = 0;      // Weighted score that's not constant during caculation
int WS = 0;       // Weighted Score
float GPA;        // Graded Point Average

void GetDetails(char name[], int *NoOfCourse, char coursecode[][6],int courseunit[], char grade[])
{
	cout << "Enter your name " << endl;
	cin.getline(name, 100); // So that first name and other names are permitted
	cout << endl;

	cout << "Enter the number of courses you registered for " << endl;
	cin >> *NoOfCourse;
	cout << endl;

	cout << "Enter the following details(leave space(s) in between)" << endl;
	cout << "\nCOURSE CODE\tCOURSE UNIT\tGRADE\n";

	//Loop created for result required details
	for (int i = 0; i < *NoOfCourse; i++)
	{
		cin >> coursecode[i] >> courseunit[i] >> grade[i];
	}
}

void CalcGP(int *NoOfCourse, char coursecode[][6],int courseunit[], char grade[])
{
	//Loop created for weightted score calculations
	for (int i = 0; i < *NoOfCourse; i++)
	{
		if (grade[i] == 'A' || grade[i] == 'a')
		{
			GP = 5;                  
			cWS = GP*courseunit[i]; 
			UP+=courseunit[i];
		}
		else if (grade[i] == 'B' || grade[i] == 'b')
		{
			GP = 4;
			cWS = GP*courseunit[i];
			UP+=courseunit[i];
		}
		else if (grade[i] == 'C' || grade[i] == 'c')
		{
			GP = 3;
			cWS = GP*courseunit[i];
			UP+=courseunit[i];
		}
		else if (grade[i] == 'D' || grade[i] == 'd')
		{
			GP = 2;
			cWS = GP*courseunit[i];
			UP+=courseunit[i];
		}
		else if (grade[i] == 'E' || grade[i] == 'e')
		{
			GP = 1;
			cWS = GP*courseunit[i];
				UP+=courseunit[i];
		}
		else if (grade[i] == 'F' || grade[i] == 'f')
		{
			GP = 0;
			cWS = GP*courseunit[i];
			UP = UP;    // Failure! The current course unit won't be
			            // added to the overall unit passed
		}
		
		WS += cWS;
		UA +=courseunit[i]; 
	}


	GPA = (float)WS/(float)UA;  
	/* GPA is the quotient of weighted score
	   and units attempted
	*/

}

void PrintResult(char name[], int *NoOfCourse, char coursecode[][6],int courseunit[], char grade[])
{
	//Result layout
	cout << endl << endl;
	cout << "\tRESULTS" << endl;
	cout << "\t=======" << endl;
	cout << name << endl;
	cout << "\nCourse Code\tUnit\tGrade\n";
	for (int j = 0; j < *NoOfCourse; j++)
	{
		for(int k = 0; k < 6; k++)
			cout << coursecode[j][k];
		cout << "       \t" << courseunit[j] << "   \t" << grade[j] <<endl;
	}
	cout << endl;
	cout << "UA: "<< UA << endl;
	cout << "UP: " << UP << endl;
	cout << "WS: "<< WS <<endl << endl;
	cout << setiosflags(ios::fixed) << setprecision(2);//to output the GPA in 2 dp
	cout << "GPA: " << GPA << endl;
}