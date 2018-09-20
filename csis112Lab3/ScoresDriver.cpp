//Sort Scores -- sorts scores in an array
//CSIS 112-2
//<Sources if necessary>


//Include statements
#include <iostream>
#include <string>
#include "stdafx.h"
#include <fstream>
#include "Scores.h"
#include <string>


using namespace std;

//Global declarations: Constants and type definitions only -- NO variables

//Function prototypes
bool CheckFileExists(const string& filename);
bool FilenameInputCheck();


int main()
{
	//In cout statement below substitute your name and lab number
	cout << "Cody Moore -- Lab Number 3" << endl << endl;

	//Variable declarations

	ifstream in;

	//Program logic

	// get file name for scores in
	// compute avg
	// display avg



	//Closing program statements
	system("pause");
	return 0;
}

//Function definitions

bool CheckFileExists(const string & filename)
{
	ifstream in(filename.c_str()); 
	return in.good(); // tries to open filename, returns bool according to the files existence
}

bool FilenameInputCheck()
{
	string s;
	cout << "Please input the name of the file with your scores. Example: Scores.txt" << endl;
	getline(cin, s, '\n'); // gets input

	if (CheckFileExists(s)) // checks file
	{
		return true;
	}
	else
	{
		return false;
	}
}
