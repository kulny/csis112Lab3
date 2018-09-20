#pragma once
class Scores
{
public:
	Scores(); // init scores at 0
	Scores(double val);	// init scores at val
	void AddValue(double val); // add value to array

private:
	// vars
	double scoreArray[100];
	int index = 0; // used to add values to array by iteration 
	int index = 0; // used to keep track of how many grades added to array for avg purposes

	// Operations and other
	void SortArray();
	double ComputeAvg();
	void DisplayScores();
	// sort array in ascending order
	// computer average of scores
	// display scores 
};

