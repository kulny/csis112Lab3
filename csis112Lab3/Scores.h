#pragma once
class Scores
{
public:
	Scores(); // init scores at 0
	Scores(int val);	// init scores at val

	// Public operations
	void AddValue(int val); // add value to array
	void DisplayScores(); // displays all scores and avg
	void SetArrayLength(int length); // sets index for avg, etc

private:
	// vars
	int scoreArray[100];
	int index = 0; // used to add values to array by iteration and used to keep track of how many grades added to array for avg purposes
	int arrayLength = 0;

	// Operations and other
	void SortArray(); // sorts array
	double ComputeAvg(); // finds avg of all added scores
};

