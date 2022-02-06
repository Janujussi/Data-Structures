// 	Name: 				Jan Morrison

//	FILE: DailyTemps.h
//	CLASS PROVIDED: DailyTemps
//
//	CONSTRUCTORS for the DailyTemps class:
//		DailyTemps()
//			Postcondition: an object created for the
//			temperatures within a week.
//
//	METHODS for the DailyTemps class:
//		void setTemp(string day)
//			Precondition: temperature for day is not changed.
//			Postcondition: temperature for selected day
//			changed.
//
//		int Freezing()
//			Postcondition: amount of freezing days within the week
//			is printed.
//
//		string Warmest()
//			Postcondition: the warmest day of the week is printed.
//
//		void printTemps()
//			Postcondition: temperatures for the week are printed.

#ifndef DAILYTEMPS_H
#define DAILYTEMPS_H

#include <string>
#include <iostream>

using namespace std;

class DailyTemps
{
	public:
		//	CONSTRUCTORS
		DailyTemps();

		//	METHODS
		void setTemp(string day);
		int Freezing();
		string Warmest();
		void printTemps();

	private:
		string days[7] = {
			"Monday",
			"Tuesday",
			"Wednesday",
			"Thursday",
			"Friday",
			"Saturday",
			"Sunday"
		};
		double temperatures[7];
};

#endif	//	DAILYTEMPS_H