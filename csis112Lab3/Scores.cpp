#include "stdafx.h"
#include "Scores.h"
#include <iostream>



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

double Scores::ComputeAvg()
{
	double avg;
	for (int i = 0; i < 100; i++)
	{
		avg += scoreArray[i];
	}
	return avg / (index == 0 ? 100 : index); // divides by 100 if no values have been added (for example, all grades init to some val)
}

void Scores::DisplayScores()
{
	for (int i = 0; i <= index; i++)
	{
		std::cout << scoreArray[i];
	}
	std::cout << ComputeAvg();
}
