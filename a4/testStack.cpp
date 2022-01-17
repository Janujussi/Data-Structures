// Name: Jan Morrison
// Class: CS 3305/Section#3
// Term: Fall 2021
// Instructor: Dr. Haddad
// Assignment: 4

// FILE: testStack.cpp
// 	This program runs a meny loop and lets the user create a stack
// 	within each function call to show the function's functionality.

// FUNCTIONS:
//	void topToBottom(stack<int> prStack)
//		Postcondition: the stack passed into the function is printed
//			from top to bottom.
//
//	void bottomToTop(stack<int> prStack)
//		Postcondition: the stack passed into the function is printed
//			from bottom to top.
//
//	void flipStack(stack<string>& flStack)
//		Precondition: the stack contains user inputs from bottom to top.
//		Postcondition: the stack contains user input from top to bottom.
//
//	bool searchStack(stack<int>seStack, int targetValue)
//		Postcondition: prints true if target value is within the stack,
//			false if not.

#include <stack>			// Provides stack
#include <iostream>		// Provides cpp input and output
#include <cstdio>			// Provides c input and output
#include <string>			// Provides string
#include <cctype>			// Provides string to int/float functions

using namespace std;

// FUNCTION DECKARATIONS
void topToBottom(stack<int> prStack);
void bottomToTop(stack<double> prStack);
void flipStack(stack<string>& flStack);
bool searchStack(stack<int> seStack, int targetValue);

// MAIN
int main() {
	int menuLoop = 0;
	char userOption;

	printf("This is testStack.cpp\n");

	// Menu loop. Exits when user enters 's'
	while (!menuLoop) {
		printf(
			"-----MAIN MENU-----\n"
			"1. Test function topToBottom with integer stack\n"
			"2. Test function bottomToTop with double stack\n"
			"3. Test function flipStack with string stack\n"
			"4. Test function searchStack with integer stack\n"
			"s. Exit program\n"
			"\nEnter option number: "
		);
		cin >> userOption;

		// Any letter becomes lowercase
		if (userOption > 52) {
			userOption = tolower(userOption);
		}

		// Invalid character
		while (userOption < 49 || (userOption != 115 && userOption > 52)) {
			printf("\nInvalid input, enter new input: ");
			cin >> userOption;
		}

		// Case statements for each function
		switch(userOption) {

			// Testing the topToBottom function
			case '1': {
				stack<int> c1Stack;
				stack<int> copy;
				string input;
				int value;

				// Input integers, insert 's' to stop
				while (1) {
					printf("Insert an integer to the stack, insert 's' to stop: ");
					cin >> input;

					if (input[0] == 115) {
						break;
					}

					value = stoi(input);
					c1Stack.push(value);
				}

				copy = c1Stack;

				// Printing the stack and function
				printf("\nTesting function topToBottom:\n");
				printf("Stack content:   ");

				while (!copy.empty()) {
					printf("%d  ", copy.top());
					copy.pop();
				}

				printf("\nFunction output: ");
				topToBottom(c1Stack);
				printf("\n\n");

				break;
			}

			// Testing the bottomToTop function
			case '2': {
				stack<double> c2Stack;
				stack<double> copy;
				string input;
				double value;

				// Input floats, insert 's' to stop
				while (1) {
					printf("Insert a float to the stack, insert 's' to stop: ");
					cin >> input;

					if (input[0] == 115) {
						break;
					}

					value = stof(input);
					c2Stack.push(value);
				}

				copy = c2Stack;

				// Printing the stack and function
				printf("\nTesting function bottomToTop:\n");
				printf("Stack content:   ");

				while (!copy.empty()) {
					printf("%f  ", copy.top());
					copy.pop();
				}

				printf("\nFunction output: ");
				bottomToTop(c2Stack);
				printf("\n\n");

				break;
			}

			// Testing the flipStack function
			case '3': {
				stack<string> c3Stack;
				stack<string> copy;
				string input;

				// Input strings, insert 's' to stop
				while (1) {
					printf("Insert a string to the stack, insert '0' to stop: ");
					cin >> input;

					if (input[0] == '0') {
						break;
					}

					c3Stack.push(input);
				}

				copy = c3Stack;

				// Printing the the stack before and after the function
				printf("\nTesting function flipStack:\n");
				printf("Stack content:   ");

				while (!copy.empty()) {
					printf("%s  ", copy.top().c_str());
					copy.pop();
				}

				printf("\nFunction output: ");
				flipStack(c3Stack);

				while (!c3Stack.empty()) {
					printf("%s  ", c3Stack.top().c_str());
					c3Stack.pop();
				}

				printf("\n\n");

				break;
			}

			// Testing the searchStack function
			case '4': {
				stack<int> c4Stack;
				stack<int> copy;
				string input;
				int value;

				// Input integers, insert 's' to stop
				while (1) {
					printf("Insert an integer to the stack, insert 's' to stop: ");
					cin >> input;

					if (input[0] == 115) {
						break;
					}

					value = stoi(input);
					c4Stack.push(value);
				}

				printf("\nWhat value to search for within stack?\n");
				cin >> value;
				copy = c4Stack;

				// Printing the stack and function
				printf("\nTesting function searchStack:\n");
				printf("Stack content:    ");

				while (!copy.empty()) {
					printf("%d  ", copy.top());
					copy.pop();
				}

				printf("\nTarget value:     %d\n", value);
				printf("Function output:  %s\n\n", searchStack(c4Stack, value) ? "true" : "false");

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

// FUNCTIONS
// Prints stack from top to bottom
void topToBottom(stack<int> prStack) {
	while (!prStack.empty()) {
		printf("%d  ", prStack.top());
		prStack.pop();
	}
}

// Prints stack from bottom to top
void bottomToTop(stack<double> prStack) {
	stack<double> bStack;

	while (!prStack.empty()) {
		bStack.push(prStack.top());
		prStack.pop();
	}

	while (!bStack.empty()) {
		printf("%f  ", bStack.top());
		bStack.pop();
	}
}

// Flips the stack
void flipStack(stack<string>& flStack) {
	stack<string> flippedStack;

	while (!flStack.empty()) {
		flippedStack.push(flStack.top());
		flStack.pop();
	}

	flStack = flippedStack;
}

// Searches the stack for target value
bool searchStack(stack<int> seStack, int targetValue) {
	while (!seStack.empty()) {
		if (targetValue == seStack.top()) {
			return true;
		}

		seStack.pop();
	}

	return false;
}