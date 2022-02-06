// Name: Jan Morrison

// FILE: hashFunctions.cpp
//	This program passes the given array of keys through 4
//	hash functions and maps them to a hash table. The number
//	of probes each key takes is printed.

// FUNCTIONS:
//	void runHF1(int** hash_tablel, const int* keys, size_t arraySize)
//		Precondition: Empty hash table.
//		Postcondition: The division method is implemented with linear probing
//			for collision resolution.
//
//	void runHF2(int** hash_table, const int* keys, size_t arraySize)
//		Precondition: Empty hash table.
//		Postcondition: The division method is implemented with quadratic probing
//			for collision resolution.
//
//	void runHF3(int** hash_table, const int* keys, size_t arraySize)
//		Precondition: Empty hash table.
//		Postcondition: The division method is implemented with double hashing
//			for collision resolution.
//
//	void runHF4(int** hash_table, const int* keys, size_t arraySize)
//		Precondition: Empty hash table.
//		Postcondition: The division method is implemented with quadratic probing
//			multiplied by 2 for collision resolution.
//
//	int HF2(int key)
//		Postcondition: Key is hashed and added to original hash.
//
//	void printHT(int** hash_table, size_t arraySize)
//		Postcondition: Hash table is printed.

#include <iostream>		// Provides input and output
#include <math.h>		// Provides pow function

using namespace std;

// FUNCTION DECLARATIONS
void runHF1(int** hash_tablel, const int* keys, size_t arraySize);
void runHF2(int** hash_table, const int* keys, size_t arraySize);
void runHF3(int** hash_table, const int* keys, size_t arraySize);
void runHF4(int** hash_table, const int* keys, size_t arraySize);
int HF2(int key);
void printHT(int** hash_table, size_t arraySize);

// MAIN
int main() {
	const int keys[] = {	// Array of keys
		1234, 8234, 7867, 1009, 5438, 4312, 3420, 9487, 5418, 5299,
		5078, 8239, 1208, 5098, 5195, 5329, 4543, 3344, 7698, 5412,
		5567, 5672, 7934, 1254, 6091, 8732, 3095, 1975, 3843, 5589,
		5439, 8907, 4097, 3096, 4310, 5298, 9156, 3895, 6673, 7871,
		5787, 9289, 4553, 7822, 8755, 3398, 6774, 8289, 7665, 5523
	};
	size_t keysSize = sizeof(keys) / sizeof(keys[0]);	// Amount of keys there are

	// Initialize hash table.
	int** Table	= new int* [keysSize];
	for (int i = 0; i < 50; i++) {
		Table[i] = new int[2];
	}

	int menuLoop = 0;
	char userOption;

	printf("This is hashFunctions.cpp\n");

	// Menu loop. Exits when user enters '5'
	while (!menuLoop) {
		printf(
			"\n-----MAIN MENU--------------------------------------\n"
			"1 - Run HF1 (Division method with Linear Probing)\n"
			"2 - Run HF2 (Division method with Quadratic Probing)\n"
			"3 - Run HF3 (Division method with Double Hashing)\n"
			"4 - Run HF4 (Student Designed HF)\n"
			"5 - Exit Program\n"
			"Enter option number: "
		);
		cin >> userOption;
		cout << endl;

		// Invalid character
		while (userOption < 49 ||  userOption > 53) {
			printf("\nInvalid input, enter new input: ");
			cin >> userOption;
		}

		// Menu option definitions
		switch(userOption) {

			// Runs hash function 1
			case '1':
				// Delete previous table and initialize new table with 0s
				delete[] Table;
				Table = new int* [keysSize]{0};
				for (int i = 0; i < keysSize; i++) {
					Table[i] = new int[2]{0};
				}

				runHF1(Table, keys, keysSize);	// Run hash function 1
				cout << "Hash table resulted from HF1: " << endl;
				printHT(Table, keysSize);		// Print hash table

				break;

			// Runs hash function 2
			case '2':
				delete[] Table;
				Table = new int* [keysSize]{0};
				for (int i = 0; i < keysSize; i++) {
					Table[i] = new int[2]{0};
				}

				runHF2(Table, keys, keysSize);
				cout << "Hash table resulted from HF2: " << endl;
				printHT(Table, keysSize);

				break;

			// Runs hash function 3
			case '3':
				delete[] Table;
				Table = new int* [keysSize]{0};
				for (int i = 0; i < keysSize; i++) {
					Table[i] = new int[2]{0};
				}

				cout << "Hash table resulted from HF3: " << endl << endl;
				runHF3(Table, keys, keysSize);
				printHT(Table, keysSize);

				break;

			// Runs hash function 4
			case '4':
				delete[] Table;
				Table = new int* [keysSize]{0};
				for (int i = 0; i < keysSize; i++) {
					Table[i] = new int[2]{0};
				}

				cout << "Hash table resulted from HF4: " << endl << endl;
				runHF4(Table, keys, keysSize);
				printHT(Table, keysSize);

				break;

			// Exit program
			case '5':
				menuLoop = 1;
				printf("\nProgram exited.");

				break;
		}
	}

	return 0;
}

// Hash function 1
void runHF1(int** hash_table, const int* keys, size_t arraySize) {
	size_t probes;
	int division = 50;
	int index;

	// Iterates through keys and inserts them to hash function
	for (size_t i = 0; i < arraySize; i++) {
		probes = 0;
		index = keys[i] % division;		// Initial index to insert key

		// If collision then probe
		while (hash_table[index][0] != 0) {
			index++;
			probes++;

			if (index == 50) {
				index = 0;
			}
		}
		// Insert key to table
		hash_table[index][0] = keys[i];
		hash_table[index][1] = probes;
	}
}

// Hash function 2
void runHF2(int** hash_table, const int* keys, size_t arraySize) {
	size_t probes;
	int division = 50;
	int index;
	int quadraticProbe;
	int ogIndex;

	// Iterates through keys and inserts them to hash function
	for (size_t i = 0; i < arraySize; i++) {
		quadraticProbe = 1;
		probes = 0;
		index = keys[i] % division;
		ogIndex = index;

		// If collision then probe
		while (hash_table[index][0] != 0) {
			index = ogIndex + pow(quadraticProbe, 2); // Quadratic probing
			probes++;
			quadraticProbe++;

			// Keep index within range
			if (index >= 50) {
				index %= 50;
			}
		}
		hash_table[index][0] = keys[i];
		hash_table[index][1] = probes;
	}
}

// Hash function 3
void runHF3(int** hash_table, const int* keys, size_t arraySize) {
	size_t probes;
	int division = 50;
	int index;
	int ogIndex;
	int j;
	int tries;

	// Iterates through keys and inserts them to hash function
	for (size_t i = 0; i < arraySize; i++) {
		probes = 0;
		index = keys[i] % division;
		ogIndex = index;
		j = 1;
		tries = 1;

		// If collision then probe
		while (hash_table[index][0] != 0) {
			index = ogIndex + j * HF2(keys[i]);
			probes++;
			j++;
			tries++;

			// If cannot hash within 50 tries, then it is unhashable
			if (tries > 50) {
				cout << "Unable to hash key " << keys[i] << " to the table" << endl;
				break;
			}

			// Keep index within range
			if (index >= 50) {
				index %= 50;
			}
		}
		if (tries <= 50) {
			hash_table[index][0] = keys[i];
			hash_table[index][1] = probes;
		}
	}
}

// Hash function 4
void runHF4(int** hash_table, const int* keys, size_t arraySize) {
	size_t probes;
	int division = 50;
	int index;
	int quadraticProbe;
	int ogIndex;
	int tries;

	// Iterates through keys and inserts them to hash function
	for (size_t i = 0; i < arraySize; i++) {
		quadraticProbe = 1;
		probes = 0;
		index = keys[i] % division;		// Using division method
		ogIndex = index;
		tries = 0;

		// If collision then probe
		while (hash_table[index][0] != 0) {
			index = ogIndex + pow(quadraticProbe, 2) * 2;	// Quadratic probing multiplied
															// by 2
			probes++;
			quadraticProbe++;
			tries++;

			// If cannot hash within 50 tries, then it is unhashable
			if (tries >= 50) {
				cout << "Unable to hash key " << keys[i] << " to the table" << endl;
				break;
			}

			// Keep index within range
			if (index >= 50) {
				index %= 50;
			}
		}
		if (tries < 50) {
			hash_table[index][0] = keys[i];
			hash_table[index][1] = probes;
		}
	}
}

// Second hash function for double hashing
int HF2(int key) {
	return 30 - key % 25;
}

// Print the hash table
void printHT(int** hash_table, size_t arraySize) {
	size_t sumProbes = 0;

	cout << endl << "Index\tKey\tprobes" << endl;
	cout << "------------------------" << endl;
	for (size_t i = 0; i < arraySize; i++) {
		cout << i << "\t" << hash_table[i][0] << "\t" << hash_table[i][1] << endl;
		sumProbes += hash_table[i][1];
	}
	cout << "------------------------" << endl;
	cout << endl << "Sum of probe values = " << sumProbes << " probes." << endl;
}