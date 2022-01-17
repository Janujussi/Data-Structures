// Name: Jan Morrison
// Class: CS 3305/Section#3
// Term: Fall 2021
// Instructor: Dr. Haddad
// Assignment: 6

// FILE: myTestBST.cpp
//	This program sorts the given array of words into a binary tree.
//	The depth of the tree and the tree itself are printed. Next, the
//	root is removed and replaced with a new root. The new tree's
//	depth and structure get printed after.

// FUNCTIONS:
//	void buildTree(binary_search_tree<string>& tree, vector<string> words)
//		Precondition: The tree holds values it had been assigned.
//		Postcondition: The tree is appended with the new values fed into the
//			function.

#include <iostream>		// Provides input output
#include <string>		// Provides string library
#include <vector>		// Provides dynamic array
#include "bst.h"		// Provides binary search tree library

using namespace std;

// FUNCTIONS DECLARATIONS
void buildTree(binary_search_tree<string>& tree, vector<string> words);

// MAIN
int main() {
	vector<string> bstToInsert = {							// Array of all strings to be inserted to BST
		"After",
		"Also",
		"any",
		"back",
		"because",
		"come",
		"day",
		"even",
		"first",
		"give",
		"how",
		"its",
		"look",
		"most",
		"new",
		"now",
		"only",
		"other",
		"our",
		"over",
		"than",
		"then",
		"these",
		"think",
		"two",
		"us",
		"use",
		"want",
		"way",
		"well",
		"work"
		};
	binary_search_tree<string> bst;							// The binary search tree used for this exercise

	// Building the tree with the original set of values
	buildTree(bst, bstToInsert);
	cout << "Tree depth: " << bst.is_balanced() << endl;	// Tree depth
	print(bst.get_root(), 0);								// Tree structure

	// Removing the root of the tree
	cout << endl << endl << "This is the root: " << bst.get_root()->data() << endl;
	cout << "Deleting the root... " << endl << endl;
	bst.remove(bst.get_root()->data());						// Removes the root of the tree
	cout << "Tree depth: " << bst.is_balanced() << endl;
	print(bst.get_root(), 0);

	return 0;
}

// FUNCTION
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

	// Insert middle value to tree
	tree.insert(middleItem);

	// Recursively call this function as long as the left and right sides of
	// the middle index are not empty
	if (!leftList.empty()) {
		buildTree(tree, leftList);
	}

	if (!rightList.empty()) {
		buildTree(tree, rightList);
	}
}