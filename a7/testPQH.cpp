// Name: Jan Morrison
// Class: CS 3305/Section#3
// Term: Fall 2021
// Instructor: Dr. Haddad
// Assignment: 7

// FILE: testPQH.cpp
//	This program creates a priority queue and lets the user
//	modify the elements of the queue and view characteristics of
//	the queue.

#include <iostream>		// Provides input and output
#include <cstdio>		// Provides printf
#include <string>		// Provides string
#include <vector>		// Provides vector STL
#include "PQ_Heap.h"	// Provides priority queue class

using namespace std;

// MAIN
int main() {
	int menuLoop = 0;
	char userOption;
	string dataType;
	priority_queue_heap<int> iPQ;
	priority_queue_heap<string> sPQ;

	printf("This is testPQH.cpp\n");

	// Force user to select data type for queue
	cout << "Enter data type for queue (int or string): ";
	cin >> dataType;
	cout << "\nSelected priority queue of type " << dataType << endl;

	// Input is invalid
	while (dataType != "int" && dataType != "string") {
		cout << endl << "Invalid input, enter int or string: ";
		cin >> dataType;
	}

	// Menu loop. Exits when user enters '8'
	while (!menuLoop) {
		printf(
			"\n-----MAIN MENU-----\n"
			"0. Enter Queue Type\n"
			"1. Enqueue Element\n"
			"2. Dequeue Element\n"
			"3. Check is_Full\n"
			"4. Check is_Empty\n"
			"5. Print Queue Size\n"
			"6. Display Front Element\n"
			"7. Print Queue Elements\n"
			"8. Exit program\n"
			"\nEnter option number: "
		);
		cin >> userOption;

		if (userOption > 52) {
			userOption = tolower(userOption);
		}

		// Invalid character
		while (userOption < 48 ||  userOption > 56) {
			printf("\nInvalid input, enter new input: ");
			cin >> userOption;
		}

		switch(userOption) {

			// Select queue type
			case '0':
				cout << "Enter data type for queue (int or string): ";
				cin >> dataType;
				cout << endl << "Selected priority queue of type " << dataType << endl;

				// Input is invalid
				while (dataType != "int" && dataType != "string") {
					cout << endl << "Invalid input, enter int or string: ";
					cin >> dataType;
				}

				// Integer queue
				if (dataType == "int") {
					while (!iPQ.is_empty()) {
						iPQ.dequeue();
					}

					break;
				}

				// String queue
				while (!sPQ.is_empty()) {
					sPQ.dequeue();
				}

				break;

			// Enqueue element
			case '1': {
				// Integer queue
				if (dataType == "int") {
					int enqueue;

					cout << "\nElement to enqueue: ";
					cin >> enqueue;

					iPQ.enqueue(enqueue);

					break;
				}

				// String queue
				string enqueue;

				cout << "\nElement to enqueue: ";
				cin >> enqueue;

				sPQ.enqueue(enqueue);

				break;
			}

			// Dequeue element
			case '2':
				// Integer queue
				if (dataType == "int") {
					cout << "\nElement dequeued: " << iPQ.dequeue() << endl;

					break;
				}

				// String queue
				cout << "\nElement dequeued: " << sPQ.dequeue() << endl;

				break;

			// Is queue full
			case '3':
				// Integer queue
				if (dataType == "int") {
					if (iPQ.is_full()) {								// If queue is full
						cout << "\nPriority queue is full" << endl;

						break;
					}
					cout << "\nPriority queue is not full" << endl;		// If queue is not full

					break;
				}

				// String queue
				if (sPQ.is_full()) {
					cout << "\nPriority queue is full" << endl;

					break;
				}
				cout << "\nPriority queue is not full" << endl;

				break;

			case '4':
				// Integer queue
				if (dataType == "int") {
					if (iPQ.is_empty()) {								// If queue is empty
						cout << "\nPriority queue is empty" << endl;

						break;
					}
					cout << "\nPriority queue is not empty" << endl;	// If queue is not empty

					break;
				}

				// String queue
				if (sPQ.is_empty()) {
					cout << "\nPriority queue is empty" << endl;

					break;
				}
				cout << "\nPriority queue is not empty" << endl;

				break;

			case '5':
				// Integer queue
				if (dataType == "int") {
					cout << "\nQueue size is: " << iPQ.size() << endl;

					break;
				}

				// String queue
				cout << "\nQueue size is: " << sPQ.size() << endl;

				break;

			case '6':
				// Integer queue
				if (dataType == "int") {
					cout << "\nFront element is: " << iPQ.front();

					break;
				}

				// String queue
				cout << "\nFront element is: " << sPQ.front();

				break;

			case '7':
				// Integer queue
				if (dataType == "int") {
					iPQ.get_root()->check_heap();

					break;
				}

				// String queue
				sPQ.get_root()->check_heap();

				break;

			// Exit program
			case '8': {
				menuLoop = 1;
				printf("\nProgram exited.");

				break;
			}
		}
	}

	return 0;
}