#pragma once
class Scores
{
public:
	Scores(); // init scores at 0
	Scores(double val);	// init scores at val
	void AddValue(double val); // add value to array
	void DisplayScores(); // displays all scores and avg

private:
	// vars
	double scoreArray[100];
	int index = 0; // used to add values to array by iteration and used to keep track of how many grades added to array for avg purposes

	// Operations and other
	void SortArray();
	double ComputeAvg(); // finds avg of all added scores
};

