// Name: Jan Morrison
// Class: CS 3305/Section#3
// Term: Fall 2021
// Instructor: Dr. Haddad
// Assignment: 6

// FILE: removeDouplicates.cpp
//	This program takes a user input and inserts each word
//	into a BST. It then outputs the processed text without
//	the duplicated words and in ASCII order.

// FUNCTIONS:
//	void buildTree(binary_search_tree<string>& tree, vector<string> words)
//		Precondition: The tree holds values it had been assigned.
//		Postcondition: The tree is appended with the new values fed into the
//			function.
//
//	void printValue(string rootNodeData)
//		Postcondition: Value of the node being traversed printed.

#include <iostream>		// Provides input output
#include <vector>		// Provides dynamic array
#include <algorithm>	// Provides sort algorithm used
#include "bst.h"		// Provides binary search tree

using namespace std;

// FUNCTION DECLARATIONS
void buildTree(binary_search_tree<string>& tree, vector<string> words);
void printValue(string rootNodeData);

// MAIN
int main() {
	string userString = "";
	string stringSplit = "";
	vector<string> words = {};
	binary_search_tree<string> userEnteredBST;

	while (1) {
		// User string as input
		cout << endl << "Insert string, type exit to quit program: ";
		getline(cin >> ws, userString);

		if (userString == "exit") {
			break;
		}

		cout << endl << endl;

		// Print original text
		cout << "Original Text:" << endl;
		cout << userString << endl << endl;

		// Split string up into words to feed into build tree function
		for (int i = 0; i < userString.length(); i++) {
			if (userString[i] == ' ') {
				words.push_back(stringSplit);
				stringSplit = "";
				continue;
			}

			stringSplit += userString[i];
		}

		// Insert last word to list of words
		words.push_back(stringSplit);
		stringSplit = "";

		// Sort words for optimal BST
		sort(words.begin(), words.end(), greater<string>());

		// Insert words to the tree
		buildTree(userEnteredBST, words);

		// Print processed text
		cout << "Processed Text:" << endl;
		inorder(printValue, userEnteredBST.get_root());

		// Clear tree for next insertion of words
		words = {};
		userEnteredBST.~binary_search_tree();
		cout << endl;
	}

	cout << endl << "Program exited.";

	return 0;
}

// FUNCTIONS
void buildTree(binary_search_tree<string>& tree, vector<string> words) {
	size_t len = words.size();								// Length of the array of values
	int middleIndex = (len / 2);							// Middle index of the array of values
	string middleItem = words[middleIndex]; 				// Middle value of the array of values
	vector<string> leftList;
	vector<string> rightList;

	// Splitting the array into lists for the left of middle value and the right
	for (int i = 0; i < len / 2; i++) {
		leftList.push_back(words[i]);
		rightList.push_back(words[len - (1 + i)]);
	}

	// Insert middle value to tree if it doesn't exist yet
	if (tree.search(middleItem) == NULL) {
		tree.insert(middleItem);
	}

	// Recursively call this function as long as the left and right sides of
	// the middle index are not empty
	if (!leftList.empty()) {
		buildTree(tree, leftList);
	}

	if (!rightList.empty()) {
		buildTree(tree, rightList);
	}
}

void printValue(string rootNodeData) {
	cout << rootNodeData << ' ';
}