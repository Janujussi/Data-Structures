// Name: Jan Morrison

// FILE: testPalindrome.cpp
// 	This program runs a menu loop which lets the user
//	insert a string and check whether it is a palindrome
//	character by character or word by word.

// FUNCTIONS:
//	string characterPalindrome(string input)
//		Postcondition: judgement of the input string's
//			palindrome status character by character is returned.
//
//	string wordPalindrome(string input)
//		Postcondition: judgement of the input string's
//			palindrome status word for word is returned.

#include <iostream>		// Provides input and output
#include <cstdio>			// Provides c input and output
#include <stack>			// Provides stack
#include <queue>			// Provides queue
#include <string>			// Provides string

using namespace std;

// FUNCTION DECLARATIONS
string characterPalindrome(string input);
string wordPalindrome(string input);

// MAIN
int main() {
	int menuLoop = 0;
	char userOption;

	printf("This is testStack.cpp\n");

	// Menu loop. Exits when user enters 's'
	while (!menuLoop) {
		printf(
			"\n-----MAIN MENU-----\n"
			"1. Test character-by-charater palindrome\n"
			"2. Test word-by-word palindrome\n"
			"s. Exit program\n"
			"\nEnter option number: "
		);
		cin >> userOption;

		// Any letter becomes lowercase
		if (userOption > 52) {
			userOption = tolower(userOption);
		}

		// Invalid character
		while (userOption < 49 || (userOption != 115 && userOption > 50)) {
			printf("\nInvalid input, enter new input: ");
			cin >> userOption;
		}

		// Case statements for each function
		switch(userOption) {

			// Testing characterPalindrome function
			case '1': {
				string userString;
				printf(
					"\n"
					"You selected option 1\n"
					"Input string to check palindrome: "
				);
				getline(cin >> ws, userString);

				cout << "\nYou entered:   " << userString << endl;
				cout << "Judgement:     " << characterPalindrome(userString) << endl;

				break;
			}

			// Testing wordPalindrome function
			case '2': {
				string userString;
				printf(
					"\n"
					"You selected option 2\n"
					"Input string to check palindrome: "
				);
				getline(cin >> ws, userString);

				cout << "\nYou entered:   " << userString << endl;
				cout << "Judgement:     " << wordPalindrome(userString) << endl;

				break;
			}

			case 's': {
				menuLoop = 1;
				printf("\nProgram exited.");

				break;
			}
		}
	}
}

// FUNCTIONS
// Returns whether string is palindrome
string characterPalindrome(string input) {
	queue<char> palQueue;
	stack<char> palStack;

	for (size_t i = 0; i < input.length(); i++) {
		// Ignore non-letters
		if (input[i] < 65 || (input[i] > 90 && input[i] < 97) || input[i] > 122) {
			continue;
		}

		// Push character to queue and stack
		palQueue.push(tolower(input[i]));
		palStack.push(tolower(input[i]));
	}

	// Check if palindrome or not
	while (!palQueue.empty()) {
		if (palQueue.front() != palStack.top()) {
			return "Not Palindrome";
		}

		palQueue.pop();
		palStack.pop();
	}

	return "Palindrome";
}

// Returns whether string is palindrome
string wordPalindrome(string input) {
	queue<string> palQueue;
	stack<string> palStack;
	string stringToPush;

	for (size_t i = 0; i < input.length(); i++) {
		// Push word onto stack and queue if end word
		if (input[i] == ' ') {
			palQueue.push(stringToPush);
			palStack.push(stringToPush);
			stringToPush = "";
			continue;
		}

		// Ignore non-letters
		if (input[i] < 65 || (input[i] > 90 && input[i] < 97) || input[i] > 122) {
			continue;
		}

		stringToPush += tolower(input[i]);
	}

	// Push last word to stack and queue
	palQueue.push(stringToPush);
	palStack.push(stringToPush);

	// Check if palindrome or not
	while (!palQueue.empty()) {
		if (palQueue.front() != palStack.top()) {
			return "Not Palindrome";
		}

		palQueue.pop();
		palStack.pop();
	}

	return "Palindrome";
}