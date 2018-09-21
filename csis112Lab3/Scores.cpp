#include "stdafx.h"
#include "Scores.h"
#include <iostream>

// general comments are in Scores.h, only implementation level comments will be here

Scores::Scores()
{
	for (int i = 0; i < 100; i++)
	{
		scoreArray[i] = 0;
	}
}

Scores::Scores(double val)
{
	for (int i = 0; i < 100; i++)
	{
		scoreArray[i] = val;
	}
}

void Scores::AddValue(double val)
{
	scoreArray[index] = val;
	index++; // keeps track of location where next added value should go
}

void Scores::SortArray()
{
	// start with second item
	// compare to first item
	// if smaller, swap, else continue comparisons with all others
	// placeholder var to hold swap val

}

double Scores::ComputeAvg()
{
	double avg = 0;
	for (int i = 0; i < 100; i++)
	{
		avg += scoreArray[i];
	}
	return avg / (index == 0 ? 100 : index); // divides by 100 if no values have been added (for example, all grades init to some val) 
	// ? operator for brevity
}

void Scores::DisplayScores()
{
	for (int i = 0; i <= index; i++)
	{
		std::cout << scoreArray[i]; // lists all scores
	}
	std::cout << ComputeAvg(); // lists score avg
}
