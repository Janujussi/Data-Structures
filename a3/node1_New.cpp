// Name: Jan Morrison

// FILE: node1_New.cxx
// IMPLEMENTS: The functions of the node class and the
// linked list toolkit (see node1.h for documentation).
// INVARIANT for the node class:
//   The data of a node is stored in data_field, and the link in link_field.

#include "node1_New.h"
#include <cassert> // Provides assert
#include <cstdlib> // Provides NULL and size_t
#include <cstdio>  // Provides printf
using namespace std;

namespace main_savitch_5
{
	size_t list_length(node *head_ptr)
	// Library facilities used: cstdlib
	{
		const node *cursor;
		size_t answer;

		answer = 0;
		for (cursor = head_ptr; cursor != NULL; cursor = cursor->link())
			++answer;

		return answer;
	}

	void list_head_insert(node *&head_ptr, const node::value_type &entry)
	{
		head_ptr = new node(entry, head_ptr);
	}

	void list_insert(node *previous_ptr, const node::value_type &entry)
	{
		node *insert_ptr;

		insert_ptr = new node(entry, previous_ptr->link());
		previous_ptr->set_link(insert_ptr);
	}

	node *list_search(node *head_ptr, const node::value_type &target)
	// Library facilities used: cstdlib
	{
		node *cursor;

		for (cursor = head_ptr; cursor != NULL; cursor = cursor->link())
			if (target == cursor->data())
				return cursor;
		return NULL;
	}

	const node *list_search(const node *head_ptr, const node::value_type &target)
	// Library facilities use d: cstdlib
	{
		const node *cursor;

		for (cursor = head_ptr; cursor != NULL; cursor = cursor->link())
			if (target == cursor->data())
				return cursor;
		return NULL;
	}

	node *list_locate(node *head_ptr, size_t position)
	// Library facilities used: cassert, cstdlib
	{
		node *cursor;
		size_t i;

		assert(0 < position);
		cursor = head_ptr;
		for (i = 1; (i < position) && (cursor != NULL); i++)
			cursor = cursor->link();
		return cursor;
	}

	const node *list_locate(const node *head_ptr, size_t position)
	// Library facilities used: cassert, cstdlib
	{
		const node *cursor;
		size_t i;

		assert(0 < position);
		cursor = head_ptr;
		for (i = 1; (i < position) && (cursor != NULL); i++)
			cursor = cursor->link();
		return cursor;
	}

	void list_head_remove(node *&head_ptr)
	{
		node *remove_ptr;

		remove_ptr = head_ptr;
		head_ptr = head_ptr->link();
		delete remove_ptr;
	}

	void list_remove(node *previous_ptr)
	{
		node *remove_ptr;

		remove_ptr = previous_ptr->link();
		previous_ptr->set_link(remove_ptr->link());
		delete remove_ptr;
	}

	void list_clear(node *&head_ptr)
	// Library facilities used: cstdlib
	{
		while (head_ptr != NULL)
			list_head_remove(head_ptr);
	}

	void list_copy(const node *source_ptr, node *&head_ptr, node *&tail_ptr)
	// Library facilities used: cstdlib
	{
		head_ptr = NULL;
		tail_ptr = NULL;

		// Handle the case of the empty list.
		if (source_ptr == NULL)
			return;

		// Make the head node for the newly created list, and put data in it.
		list_head_insert(head_ptr, source_ptr->data());
		tail_ptr = head_ptr;

		// Copy the rest of the nodes one at a time, adding at the tail of new list.
		source_ptr = source_ptr->link();
		while (source_ptr != NULL)
		{
			list_insert(tail_ptr, source_ptr->data());
			tail_ptr = tail_ptr->link();
			source_ptr = source_ptr->link();
		}
	}

	// Delete repeated values
	void delete_reps(node* &head_ptr)
	{
		node* currentNode = head_ptr;
		node* checkNode = NULL;
		double checkVal = 0;

		while (currentNode->link() != NULL) {
			checkVal = currentNode->data();
			checkNode = currentNode->link();

			while (checkNode->link() != NULL) {
				if (checkNode->link()->data() == checkVal) {
					list_remove(checkNode);
				} else {
					checkNode = checkNode->link();
				}
			}
			currentNode = currentNode->link();
		}
	}

	// Sorts the list
	void sort_list(node* &head_ptr)
	{
		list_head_insert(head_ptr, 0);
		node* newNode = new node(0, NULL);
		node* currentNode = NULL;
		node* nodeToDel = NULL;		// This holds the previous node for list_remove
															// 		nodeToDel deletes nodeToDel-link()
		double largestVal = 0;

		while (head_ptr->link() != NULL) {
			currentNode = head_ptr;
			largestVal = currentNode->data();

			// Finding largest value
			while (currentNode->link() != NULL) {
				if (currentNode->link()->data() > largestVal) {
					largestVal = currentNode->link()->data();
					nodeToDel = currentNode;
				}

				currentNode = currentNode->link();
			}

			// Moving largest value to new list
			list_head_insert(newNode, largestVal);
			list_remove(nodeToDel);
		}

		head_ptr = newNode;
		currentNode = head_ptr;

		while (currentNode->link()->link() != NULL) {
			currentNode = currentNode->link();
		}

		list_remove(currentNode);
	}

	// Splits the list
	void split_list(node* &head_ptr, node* &second_ptr, double splitValue)
	{
		node* tailPtr = second_ptr;
		list_head_insert(head_ptr, 0);
		node* splitNode = list_search(head_ptr, splitValue);
		node* printNode = NULL;
		node* delList = head_ptr;

		list_copy(splitNode, second_ptr, tailPtr);

		while (delList->link() != splitNode) {
			delList = delList->link();
		}

		for (int i = 0; i < list_length(second_ptr); i++) {
			list_remove(delList);
		}

		list_head_remove(head_ptr);
		printf("List 1: \n");

		for (printNode = head_ptr; printNode != NULL; printNode = printNode->link()) {
			if (printNode->link() == NULL) {
				printf("%f", printNode->data());
			} else {
			printf("%f->", printNode->data());
			}
		}

		printf("\n\nList 2: \n");

		for (printNode = second_ptr; printNode != NULL; printNode = printNode->link()) {
			if (printNode->link() == NULL) {
				printf("%f", printNode->data());
			} else {
			printf("%f->", printNode->data());
			}
		}
	}
}