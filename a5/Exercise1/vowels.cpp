// Name: Jan Morrison
// Class: CS 3305/Section#3
// Term: Fall 2021
// Instructor: Dr. Haddad
// Assignment: 5

// FILE: vowels.cpp
// 	This program runs a menu loop which lets the user
//	enter a string and count how many vowels there are.

// FUNCTIONS:
// 	string inputString()
//		Postcondition: A user entered string is saved
//			to the program.
//
// 	size_t countVowels(vector<char> thisString)
//		Postcondition: Number of vowels in user entered
//			string is displayed.

#include <iostream>		// Provides input and output
#include <cstdio>		// Provides printf
#include <string>		// Provides string
#include <vector>		// Provides vector STL

using namespace std;

// FUNCTION DECLARATIONS
string inputString();
size_t countVowels(vector<char> thisString);

// MAIN
int main() {
	int menuLoop = 0;
	char userOption;
	string readString;

	printf("This is vowels.cpp\n");

	// Menu loop. Exits when user enters 's'
	while (!menuLoop) {
		printf(
			"\n-----MAIN MENU-----\n"
			"1. Read input string\n"
			"2. Compute number of vowels\n"
			"s. Exit program\n"
			"\nEnter option number: "
		);
		cin >> userOption;

		if (userOption > 52) {
			userOption = tolower(userOption);
		}

		// Invalid character
		while (userOption < 49 || (userOption != 115 && userOption > 50)) {
			printf("\nInvalid input, enter new input: ");
			cin >> userOption;
		}

		switch(userOption) {

			// User inputs string
			case '1':
				readString = inputString();

				printf("\nYou entered \"%s\"\n", readString.c_str());

				break;

			// Returns number of vowels in user entered string
			case '2': {
				vector<char> lowerString;

				for (int i = 0; i < readString.length(); i++) {		// Turn string to lowercase
					lowerString.push_back(tolower(readString[i]));
				}

				printf("\nYou entered string: %s\n", readString.c_str());
				printf("Number of vowels:   %d\n", countVowels(lowerString));

				break;
			}

			// Exit program
			case 's': {
				menuLoop = 1;
				printf("\nProgram exited.");

				break;
			}
		}
	}
}

string inputString() {
	string readString = "";

	printf("Input string: ");
	getline(cin >> ws,  readString);

	return readString;
}

size_t countVowels(vector<char> thisString) {
	size_t vowelCount = 0;

	switch (thisString.back()) {
		case 'a':
			vowelCount++;

			break;
		case 'e':
			vowelCount++;

			break;
		case 'i':
			vowelCount++;

			break;
		case 'o':
			vowelCount++;

			break;
		case 'u':
			vowelCount++;

			break;
	}

	thisString.pop_back();

	if (!thisString.empty()) {
		vowelCount += countVowels(thisString);
	}

	return vowelCount;
}