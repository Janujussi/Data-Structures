// Name: Jan Morrison

// FILE: node1_Test_New.cpp

#include <iostream>		// Provides input and output
#include <cstdio>			// Provides printf
#include "node1_New.h"		// Provides the class node1

using namespace std;
using namespace main_savitch_5;

int main() {
	char continueLoop = 'Y';		// Value for which the menu will keep running
	int menuOption;							// The option from the menu to run DailyTemp's methods
	double initValue;						// Initial value to initialize the list with
	node* grades = NULL;								// Head pointer
	node* curNode = NULL;							// Used for extending list
	node* list2 = NULL;

	// The list is empty at first, asking for a value to initialize the first node
	printf(
		"Your list is empty, what should the value of your\n"
		"first node be: "
	);
	cin >> initValue;
	grades = new node(initValue, NULL);

	// Menu loop
	while (continueLoop != 'N' && continueLoop != 'n') {
		curNode = grades;

		// Menu
		printf(
			"------------- MAIN MENU ------------------\n"
			"1. Test function std::size_list_length\n"
			"2. Test function void list_head_insert\n"
			"3. Test function void list_insert\n"
			"4. Test function node *list_search\n"
			"5. Test function const node *list_search\n"
			"6. Test function node *list_locate\n"
			"7. Test function const node *list_locate\n"
			"8. Test function void list_head_remove\n"
			"9. Test function void list_remove\n"
			"10. Test function void list_clear\n"
			"11. Test function void list_copy\n"
			"12. Display List\n"
			"13. Test function delete_reps\n"
			"14. Test function sort_list\n"
			"15. Test function split_list\n"
			"16. Exit program\n"
			"Enter option number: \n"
		);
		cin >> menuOption;
		cout << endl;

		// Menu cases
		switch(menuOption) {
			// Display length of list
			case 1:
				printf("length of list: %lu", list_length(grades));
				break;

			// Insert number to front of list
			case 2:
				double entry;
				printf("insert new value: ");
				cin >> entry;

				list_head_insert(grades, entry);

				printf(
					"new entry of %f has been inserted to the front"
					" of the list",
					entry
					);
				break;

			// Insert number to list
			case 3:
				int position, entry3;
				double value;
				curNode = grades;

				printf("What index do you want to insert: ");
				cin >> position;
				printf("What value do you want to insert: ");
				cin >> entry3;
				value = entry3;

				for (int i = 0; i < position - 1; i++) {
					if (curNode->link() == NULL) {
						list_insert(curNode, 0);
					}
					curNode = curNode->link();
				}

				list_insert(curNode, entry3);

				printf("Value %f entered at index %d\n", value, position);
				break;

			// Gives position in memory of data value
			case 4:
				double targetValue;
				printf("What value do you want to search for: ");
				cin >> targetValue;

				cout << "The node was found at address " << list_search(grades, targetValue) << endl;
				break;

			// Gives position in memory of data value
			case 5:
				double targetValue5;
				printf("What value do you want to search for: ");
				cin >> targetValue5;

				cout << "The node was found at address " << list_search(grades, targetValue5) << endl;
				break;

			// Gives position in memory of node
			case 6:
				size_t position6;
				printf("Which index in list do you want to find the memory address of: ");
				cin >> position6;

				printf("Located at: %X.", list_locate(grades, position6 + 1));
				break;

			// Gives position in memory of node
			case 7:
				size_t position7;
				printf("Which index in list do you want to find the memory address of: ");
				cin >> position7;

				printf("Located at: %X.", list_locate(grades, position7 + 1));

				break;

			// Remove first node in list
			case 8:
				printf("Removing first element of list.");
				list_head_remove(grades);
				break;

			// Remove value in list
			case 9:
				size_t position9;
				curNode = grades;
				printf("Which index do you want to remove: ");
				cin >> position9;

				for (int i = 0; i < position9 - 1; i++) {
					curNode = curNode->link();
				}

				list_remove(curNode);
				printf("Element at position %d removed", position9);
				break;

			// Clears list
			case 10:
				list_clear(grades);
				printf("List cleared!");
				break;

			// Copies list
			case 11:
				node* copy;
				copy = NULL;
				curNode = NULL;

				list_copy(grades, copy, curNode);

				printf("The list has been copied!\n");
				for (node* currentNode = grades; currentNode != NULL; currentNode = currentNode->link()) {
					printf("%f-", currentNode->data());
				}

				break;

			// Displays list
			case 12:
				for (node* currentNode = grades; currentNode != NULL; currentNode = currentNode->link()) {
					if (currentNode->link() == NULL) {
						printf("%f", currentNode->data());
					} else {
					printf("%f->", currentNode->data());
					}
				}

				break;

			// Deletes repeated values
			case 13:
				delete_reps(grades);
				printf("Repeated values deleted!");

				break;

			case 14:
				sort_list(grades);
				printf("List has been sorted!");

				break;

			case 15:
				double split;
				split = 0;
				printf("Value to be split at: ");
				cin >> split;
				split_list(grades, list2, split);

				break;

			// Exits program
			case 16:
				printf("Program exited.");
				return 0;
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