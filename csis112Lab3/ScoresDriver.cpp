//Sort Scores -- sorts scores in an array
//CSIS 112-2
//array sort from insertion array sort example


//Include statements
#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include "Scores.h"
#include <string>


using namespace std;

//Global declarations: Constants and type definitions only -- NO variables

//Function prototypes
bool CheckFileExists(const string& filename);
bool FilenameInputCheck(const string& s);
string Input();
bool ArrayInputCheck(ifstream& fileIn, string filename);
bool IsDoubleCheck(string s);
bool IsPositiveCheck(string s);


int main()
{
	//In cout statement below substitute your name and lab number
	cout << "Cody Moore -- Lab Number 3" << endl << endl;

	//Variable declarations
	string filename;
	ifstream in;
	Scores score; // inits vals to 0

	//Program logic

	// get file name for scores in

	filename = Input();
	
	if (FilenameInputCheck(filename) && ArrayInputCheck(in, filename)) // error check conditions each with their own err statements
	{
		in.open(filename);
		
		int length;
		in >> length;
		score.SetArrayLength(length); // provides the class with total length of array

		while (!in.eof())
		{
			int arrayFeed;
			in >> arrayFeed;
			score.AddValue(arrayFeed);
		}
		score.DisplayScores();
	}


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

bool FilenameInputCheck(const string& s)
{
	if (CheckFileExists(s)) // checks file
	{
		return true;
	}
	else
	{
		cout << "File could not be read. Please make sure your filename is correct." << endl;
		return false;
	}
}

string Input()
{
	string s;
	cout << "Please input the name of the file with your scores. Example: Scores.txt" << endl;

	getline(cin, s, '\n'); // gets input, deposits in s

	return s;

}

bool ArrayInputCheck(ifstream& fileIn, string filename) // checks all inputs from file, checks if is number and is positive, else returns input is bad
{
	string s;
	bool ArrayIsGood = true;

	fileIn.open(filename);
	while (!fileIn.eof())
	{
		fileIn >> s;
		
		if (!IsDoubleCheck(s) || !IsPositiveCheck(s))
		{
			ArrayIsGood = false;
			break;
		}
	}
	fileIn.close();
	return ArrayIsGood;
}

bool IsDoubleCheck(string s) // checks if double by trying to convert s to double, catches exception if it cannot, prints err statement
{
	bool error;
	try
	{
		stod(s);
		error = false;
	}
	catch (const invalid_argument)
	{
		cout << "Non-numeric input encountered." << endl;
		error = true;
	}
	return !error; // returns opposite, to enhance readability - if error is caught, this function is understandable, but if not, then when called is easily understood that it is indeed a double
}

bool IsPositiveCheck(string s) // converts s to double, checks if positive, prints err if not
{
	if (stod(s) > 0)
	{
		return true;
	}
	else
	{
		cout << "Invalid score entered: " << s << endl;
		return false;
	}

}
