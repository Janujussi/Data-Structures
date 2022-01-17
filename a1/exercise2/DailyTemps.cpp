// 	Name: 				Jan Morrison
// 	Class: 			CS 3305/Section#03
// 	Term: 				Fall 2021
// 	Instructor: 	Dr. Haddad
// 	Assignment: 	1

//	FILE: DailyTemps.cpp
//	CLASS IMPLEMENTED: DailyTemps (see DailyTemps.h for documentation)

#include "DailyTemps.h"

using namespace std;

DailyTemps::DailyTemps()
{
	for (int i = 0; i < 7; i++) {
		printf("Enter the temperature for %s: ",
			this->days[i].c_str()
		);
		cin >> this->temperatures[i];
	}
}

void DailyTemps::setTemp(string day)
{
	printf("Please enter new temp for %s: ", day.c_str());
	for (int i = 0; i < 7; i++) {
		if (this->days[i] == day) {
			double newTemp;
			cin >> newTemp;
			this->temperatures[i] = newTemp;
		}
	}
}

int DailyTemps::Freezing()
{
	int freezingTemps;
	for (int i = 0; i < 7; i++) {
		if (this->temperatures[i] < 32) {
			freezingTemps++;
		}
	}
	return freezingTemps;
}

string DailyTemps::Warmest()
{
	double warmestDay = 0;
	string warmestDayPos;
	for (int i = 0; i < 7; i++) {
		if (this->temperatures[i] > warmestDay) {
			warmestDay = this->temperatures[i];
			warmestDayPos = this->days[i];
		}
	}
	return warmestDayPos;
}

void DailyTemps::printTemps()
{
	for (int i = 0; i < 7; i++) {
		printf("%s %5f\n",
			this->days[i].c_str(),
			this->temperatures[i]
		);
	}
}