// Name: Jan Morrison

// FILE: AverargeGardes.cpp
// 	This program runs a menu loop which lets the user
//	enter the size of a class and its grades, then it
//	calculates the average grade of the class.
//
// FUNCTIONS:
//	int classSize()
//		Postcondition: Size of the class is saved to
//			the program.
//
//	queue<int> fetchGrades(int classSize)
//		Postcondition: Grades of the class are entered.
//
//	double average(queue<int> someGrades)
//		Postcondition: Average of the class grades is returned.

#include <iostream>		// Provides input and output
#include <cstdio>		// Provides printf
#include <queue>		// Provides queue

using namespace std;

// FUNCTION DECLARATIONS
int classSize();
queue<int> fetchGrades(int classSize);
double average(queue<int> someGrades);

// MAIN
int main() {
	int menuLoop = 0;
	char userOption;
	int sizeClass = 0;
	queue<int> grades;

	printf("This is AverargeGardes.cpp\n");

	// Menu loop. Exits when user enters 's'
	while (!menuLoop) {
		printf(
			"\n-----MAIN MENU-----\n"
			"1. Read class size\n"
			"2. Read class grades\n"
			"3. Compute class average\n"
			"s. Exit program\n"
			"\nEnter option number: "
		);
		cin >> userOption;

		if (userOption > 52) {
			userOption = tolower(userOption);
		}

		// Invalid character
		while (userOption < 49 || (userOption != 115 && userOption > 51)) {
			printf("\nInvalid input, enter new input: ");
			cin >> userOption;
		}

		switch(userOption) {

			// User inputs class size
			case '1':
				sizeClass = classSize();

				break;

			// User inputs grades
			case '2':
				grades = fetchGrades(sizeClass);

				break;

			// Calculate class average
			case '3':
				printf("Class average: %f", average(grades));

				break;

			// Exit program
			case 's': {
				menuLoop = 1;
				printf("\nProgram exited.");

				break;
			}
		}
	}
}

int classSize() {
	int classSize = 0;

	printf("Input class size: ");
	cin >> classSize;
	cout << endl;

	return classSize;
}

queue<int> fetchGrades(int classSize) {
	queue<int> grades;
	int input;

	while (classSize > 0) {
		printf("Enter grade (%d needed): ", classSize);
		cin >> input;
		grades.push(input);
		classSize--;
	}

	return grades;
}

double average(queue<int> someGrades) {
	double x = 0;

	if (someGrades.size() == 1) {
		return someGrades.front();
	} else {
		x = someGrades.front();
		someGrades.pop();
		return double (x + someGrades.size() * average(someGrades)) / (someGrades.size() + 1);
	}
}