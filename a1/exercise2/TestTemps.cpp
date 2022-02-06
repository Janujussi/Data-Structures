// 	Name: 				Jan Morrison

//	FILE: TestTemps.cpp
//	This program runs a menu loop and allows user to modify
//		temperatures on specific days and show information
//		about the forecast.

#include "DailyTemps.h"		//	Provides DailyTemps class definition

using namespace std;

int main() {
	char continueLoop = 'Y';		//	Value for which the menu will keep running
	int menuOption;							//	The option from the menu to run DailyTemp's methods

	//	Initialize DailyTemps object.
	printf("\nHello! Welcome to Jan Morrison's weather forecast!\n"
		"Enter this week's forecast!\n\n"
	);
	DailyTemps temps;
	printf("\nThank you!\n");

	//	Menu loop
	while (continueLoop != 'N' && continueLoop != 'n') {
		printf("\nWould you like to:\n\n"
			"1. Set a different temperature for a certain day\n"
			"2. Print how many days are freezing\n"
			"3. Print the warmest day of the week\n"
			"4. Print the temperatures for the week\n"
			"(Type 1, 2, 3, 4): "
		);
		cin >> menuOption;		//	User's menu choice
		cout << endl;

		//	Instructions for each menu option
		switch(menuOption) {
			case 1:		//	Set temperature
			{
				string day;
				printf("Which day would you like to edit?\n"
					"(Capitalize the first letter of the day!): "
				);
				cin >> day;
				cout << endl;
				temps.setTemp(day);
				break;
			}
			case 2:		//	Print number of freezing days
				printf("Number of freezing days is %d days.\n",
					temps.Freezing()
				);
				break;
			case 3:		//	Print the warmest day
				printf("The warmest day of the week is %s.\n",
					temps.Warmest().c_str()
				);
				break;
			case 4:		//	Print temperatures
				temps.printTemps();
				break;
		}

		//	Ask user if program keeps running
		printf("\nDo you want to continue?\n"
			"(Y/N): "
		);
		cin >> continueLoop;

		//	If user inputs invalid character
		while (continueLoop != 'Y' && continueLoop != 'N' && continueLoop != 'y' && continueLoop != 'n') {
			printf("Sorry, what was that?\n"
				"Enter Y or N..."
			);
			cin >> continueLoop;
		}
	}
}