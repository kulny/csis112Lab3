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

Scores::Scores(int val)
{
	if (val < 0)
	{
		std::cout << "Error: scores cannot be negative." << std::endl;
	}
	for (int i = 0; i < 100; i++)
	{
		scoreArray[i] = val;
	}
}

void Scores::AddValue(int val)
{
	if (val < 0)
	{
		std::cout << "Inputs must be positive." << std::endl;
		return;
	}
	else
	{
		scoreArray[index] = val;
		index++; // keeps track of location where next added value should go
	}
}

void Scores::SortArray()
{
	for (int i = 1; i < arrayLength; i++)
	{
		int placeholder = scoreArray[i];
		int indexCheck = i;

		while (indexCheck > 0 && scoreArray[indexCheck - 1] > placeholder)
		{
			scoreArray[indexCheck] = scoreArray[indexCheck - 1];
			indexCheck--;
		}
		scoreArray[indexCheck] = placeholder;
	}
}

double Scores::ComputeAvg()
{
	double avg = 0;
	for (int i = 0; i < arrayLength; i++)
	{
		avg += scoreArray[i];
	}
	return avg / double(arrayLength); 
}

void Scores::DisplayScores()
{
	SortArray();
	std::cout << "The scores are: " << std::endl;

	for (int i = 0; i < arrayLength; i++)
	{
		std::cout << scoreArray[i] << std::endl; // lists all scores
	}
	std::cout << "The average of the scores is: " << ComputeAvg() << std::endl; // lists score avg
}

void Scores::SetArrayLength(int length)
{
	arrayLength = length;
}

