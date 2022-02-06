// Name: Jan Morrison

// FILE: Reachability_Matrix.cpp
//	This program lets user create an adjacency matrix and
//	print out information about it.

// FUNCTIONS
// 	void multiplyMatrices(int** firstMatrix, int** secondMatrix, int** &mult, int rowFirst, int columnFirst, int rowSecond, int columnSecond)
//		Precondition: product matrix is empty.
//		Postcondition: product matrix is the product of first and second matrices.
//
//	 size_t enterData(int** &graph)
//		Postcondition: passed in 2d array of user defined size holds adjacency matrix
//			and returns size of matrix.
//
//	 void printInputMatrix(int** adjMatrix, size_t size)
//		Postcondition: printed input matrix.
//
//	 void printReachabilityMatrix(int** A1, int** A2, int** A3, int** A4, int** A5, size_t size)
//		Postcondition: printed reachability matrix of the input matrix.
//
//	 void printInDegree(int** A1, size_t size)
//		Postcondition: printed in-degrees of each node in input matrix.
//
//	 void printOutDegree(int** A1, size_t size)
//		Postcondition: printed out-degrees of each node in input matrix.
//
//	 void printSelfLoops(int** A1, size_t size)
//		Postcondition: printed number of self loops in input matrix.
//
// 	void printNumberCyclesLN(int** A1, size_t size)
//		Postcondition: printed number of cycles of length matrix size n.
//
//	 void printNumberPathsL1(int** A1, size_t size)
//		Postcondition: printed number of paths in total.
//
// 	void printNumberPathsLN(int** A1, size_t size)
//		Postcondition: printed number of paths of length size of matrix n.
//
//	 void printNumberPathsL1N(int** A1, int** A2, int** A3, int** A4, int** A5, size_t size)
//		Postcondition: printed all paths possible in matrix.
//
//	 void printNumberCyclesL1N(int** A1, size_t size)
//		Postcondition: printed all cycles possible in matrix.

#include <iostream>		// Provides input and output
#include <stack>		// Provides stack STL

using namespace std;

// FUNCTION DECLARATIONS
void multiplyMatrices(int** firstMatrix, int** secondMatrix, int** &mult, int rowFirst, int columnFirst, int rowSecond, int columnSecond);
size_t enterData(int** &graph);
void printInputMatrix(int** adjMatrix, size_t size);
void printReachabilityMatrix(int** A1, int** A2, int** A3, int** A4, int** A5, size_t size);
void printInDegree(int** A1, size_t size);
void printOutDegree(int** A1, size_t size);
void printSelfLoops(int** A1, size_t size);
void printNumberCyclesLN(int** A1, size_t size);
void printNumberPathsL1(int** A1, size_t size);
void printNumberPathsLN(int** A1, size_t size);
void printNumberPathsL1N(int** A1, int** A2, int** A3, int** A4, int** A5, size_t size);
void printNumberCyclesL1N(int** A1, size_t size);

// MAIN
int main() {
	int** A1 = NULL;		// All paths of length 1 edge
	int** A2 = NULL;		// All paths of length 2 edge
	int** A3 = NULL;		// All paths of length 3 edge
	int** A4 = NULL;		// All paths of length 4 edge
	int** A5 = NULL;		// All paths of length 5 edge
	size_t matrixSize;		// Size of adjacency matrix
	int menuLoop = 0;		// Loop to keep menu going
	char userOption;		// User menu option

	printf("This is Reachability_Matrix.cpp\n");

	// Menu loop. Exits when user enters '3'
	while (!menuLoop) {
		printf(
			"\n-----MAIN MENU--------------------------------------\n"
			"1 - Enter Graph Data\n"
			"2 - Print Outputs\n"
			"3 - Exit Program\n"
			"Enter option number: "
		);
		cin >> userOption;
		cout << endl;

		// Invalid character
		while (userOption < 49 ||  userOption > 51) {
			printf("\nInvalid input, enter new input: ");
			cin >> userOption;
		}

		// Menu option definitions
		switch(userOption) {
			case '1':
				// Initialize matrix A1 to user defined size and inputs
				matrixSize = enterData(A1);

				// Initialize matrices based off of matrix size
				switch(matrixSize) {
					case 1:
						break;

					case 2:
						A2 = new int* [matrixSize];				//	Dynamically allocate memory to matrix
						for (int i = 0; i < matrixSize; i++) {
							A2[i] = new int [matrixSize];
						}
						multiplyMatrices(A1, A1, A2, matrixSize, matrixSize, matrixSize, matrixSize);		// Initialize values

						break;

					case 3:
						A2 = new int* [matrixSize];
						for (int i = 0; i < matrixSize; i++) {
							A2[i] = new int [matrixSize];
						}
						multiplyMatrices(A1, A1, A2, matrixSize, matrixSize, matrixSize, matrixSize);

						A3 = new int* [matrixSize];
						for (int i = 0; i < matrixSize; i++) {
							A3[i] = new int [matrixSize];
						}
						multiplyMatrices(A2, A1, A3, matrixSize, matrixSize, matrixSize, matrixSize);

						break;

					case 4:
						A2 = new int* [matrixSize];
						for (int i = 0; i < matrixSize; i++) {
							A2[i] = new int [matrixSize];
						}
						multiplyMatrices(A1, A1, A2, matrixSize, matrixSize, matrixSize, matrixSize);

						A3 = new int* [matrixSize];
						for (int i = 0; i < matrixSize; i++) {
							A3[i] = new int [matrixSize];
						}
						multiplyMatrices(A2, A1, A3, matrixSize, matrixSize, matrixSize, matrixSize);

						A4 = new int* [matrixSize];
						for (int i = 0; i < matrixSize; i++) {
							A4[i] = new int [matrixSize];
						}
						multiplyMatrices(A3, A1, A4, matrixSize, matrixSize, matrixSize, matrixSize);

						break;

					case 5:
						A2 = new int* [matrixSize];
						for (int i = 0; i < matrixSize; i++) {
							A2[i] = new int [matrixSize];
						}
						multiplyMatrices(A1, A1, A2, matrixSize, matrixSize, matrixSize, matrixSize);

						A3 = new int* [matrixSize];
						for (int i = 0; i < matrixSize; i++) {
							A3[i] = new int [matrixSize];
						}
						multiplyMatrices(A2, A1, A3, matrixSize, matrixSize, matrixSize, matrixSize);

						A4 = new int* [matrixSize];
						for (int i = 0; i < matrixSize; i++) {
							A4[i] = new int [matrixSize];
						}
						multiplyMatrices(A3, A1, A4, matrixSize, matrixSize, matrixSize, matrixSize);

						A5 = new int* [matrixSize];
						for (int i = 0; i < matrixSize; i++) {
							A5[i] = new int [matrixSize];
						}
						multiplyMatrices(A4, A1, A5, matrixSize, matrixSize, matrixSize, matrixSize);

						break;
				}

				break;

			case '2':
				// If matrix uninitialized then error must choose option 1 first
				if (A1 == NULL) {
					cout << "Error. Please choose option 1 first." << endl;
					break;
				}

				// Printing data out
				printInputMatrix(A1, matrixSize);
				cout << endl;
				printReachabilityMatrix(A1, A2, A3, A4, A5, matrixSize);
				cout << endl;
				printInDegree(A1, matrixSize);
				cout << endl;
				printOutDegree(A1, matrixSize);
				cout << endl;
				printSelfLoops(A1, matrixSize);
				printNumberCyclesLN(A1, matrixSize);
				printNumberPathsL1(A1, matrixSize);
				printNumberPathsLN(A1, matrixSize);
				printNumberPathsL1N(A1, A2, A3, A4, A5, matrixSize);
				printNumberCyclesL1N(A1, matrixSize);

				break;

			case '3':		// Exit program
				menuLoop = 1;
				printf("\nProgram exited.");

				break;
		}
	}

	return 0;
}

void multiplyMatrices(int** firstMatrix, int** secondMatrix, int** &mult, int rowFirst, int columnFirst, int rowSecond, int columnSecond) {
	int i, j, k;

	// Initializing elements of matrix to 0
	for(i = 0; i < rowFirst; ++i) {
		for(j = 0; j < columnSecond; ++j) {
			mult[i][j] = 0;
		}
	}

	// Multiplying matrix firstMatrix and secondMatrix and storing in array
	for(i = 0; i < rowFirst; ++i) {
		for(j = 0; j < columnSecond; ++j) {
			for(k = 0; k < columnFirst; ++k) {
				mult[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
			}
		}
	}
}

size_t enterData(int** &graph) {
	size_t matrixSize;

	// Size of matrix
	cout << "Matrix size: ";
	cin >> matrixSize;
	cout << endl;

	// Allocate memory to A1
	graph = new int* [matrixSize];
	for (int i = 0; i < matrixSize; i++) {
		graph[i] = new int [matrixSize];
	}

	// Initialize A1 with user values
	for (int i = 0; i < matrixSize; i++) {
		for (int j = 0; j < matrixSize; j++) {
			cout << "Enter A1[" << i << "," << j << "]: ";
			cin >> graph[i][j];
		}
	}

	// Return size of matrix
	return matrixSize;
}

void printInputMatrix(int** adjMatrix, size_t size) {
	cout << "Input Matrix:" << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << adjMatrix[i][j] << " ";
		}
		cout << endl;
	}
}

void printReachabilityMatrix(int** A1, int** A2, int** A3, int** A4, int** A5, size_t size) {
	// Create reachability matrix to hold values
	int **reachabilityMatrix = new int* [size];
	for (int i = 0; i < size; i++) {
		reachabilityMatrix[i] = new int [size];
	}

	// Initialize values to 0
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			reachabilityMatrix[i][j] = 0;
		}
	}

	// Reachability matrix based off of size of matrix
	switch(size) {
		case 1:
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					reachabilityMatrix[i][j] += A1[i][j];
				}
			}

			break;

		case 2:
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					reachabilityMatrix[i][j] += A1[i][j] + A2[i][j];
				}
			}

			break;

		case 3:
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					reachabilityMatrix[i][j] += A1[i][j] + A2[i][j] + A3[i][j];
				}
			}

			break;

		case 4:
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					reachabilityMatrix[i][j] += A1[i][j] + A2[i][j] + A3[i][j] + A4[i][j];
				}
			}

			break;

		case 5:
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					reachabilityMatrix[i][j] += A1[i][j] + A2[i][j] + A3[i][j] + A4[i][j] + A5[i][j];
				}
			}

			break;
	}

	// Print reachability matrix
	cout << "Reachability Matrix:" << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << reachabilityMatrix[i][j] << " ";
		}
		cout << endl;
	}
}

void printInDegree(int** A1, size_t size) {
	size_t inDegree = 0;

	cout << "In-degrees:" << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			inDegree += A1[j][i];
		}
		cout << "Node " << i + 1 << " in-degree is " << inDegree << endl;
		inDegree = 0;
	}
}

void printOutDegree(int** A1, size_t size) {
	size_t inDegree = 0;

	cout << "Out-degrees:" << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			inDegree += A1[i][j];
		}
		cout << "Node " << i + 1 << " out-degree is " << inDegree << endl;
		inDegree = 0;
	}
}

void printSelfLoops(int** A1, size_t size) {
	size_t selfLoops = 0;

	for (int i = 0; i < size; i++) {
		selfLoops += A1[i][i];
	}

	cout << "Total number of self-loops: " << selfLoops << endl;
}

void printNumberCyclesLN(int** A1, size_t size) {
	size_t numCycles = 0;

	// DFS
	for (int rootNode = 0; rootNode < size; rootNode++) {
		stack<int> dfsStack;		// Node stack
		stack<int> dfsSize;			// Length stack, use for running back length if not cycle
		dfsStack.push(rootNode);
		dfsSize.push(1);

		while (!dfsStack.empty()) {
			size_t currLength = dfsSize.top();
			dfsSize.pop();
			int currNode = dfsStack.top();
			dfsStack.pop();

			// Check adjacent nodes and if they cycle
			for (int nextNode = 0; nextNode < size; nextNode++) {
				int isConnected = A1[currNode][nextNode];
				size_t nextLength = currLength + 1;

				// If the nodes are not connected to each other, then continue to next iteration
				if (!isConnected) {
					continue;
				}

				// If length is size of matrix
				if (nextLength > size) {
					if (nextNode == rootNode) {
						numCycles++;
					}

					continue;
				}

				dfsStack.push(nextNode);
				dfsSize.push(nextLength);
			}
		}
	}

	cout << "Total number of cycles of length " << size << " edges: " << numCycles << endl;
}

void printNumberPathsL1(int** A1, size_t size) {
	size_t numPaths = 0;

	// Count number of paths
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			numPaths += A1[i][j];
		}
	}

	cout << "Total number of paths of length 1 edge: " << numPaths << endl;
}

void printNumberPathsLN(int** A1, size_t size) {
	size_t numPaths = 0;

	// DFS
	for (int rootNode = 0; rootNode < size; rootNode++) {
		stack<int> dfsStack;
		stack<int> dfsSize;
		dfsStack.push(rootNode);
		dfsSize.push(1);

		while (!dfsStack.empty()) {
			size_t currLength = dfsSize.top();
			dfsSize.pop();
			int currNode = dfsStack.top();
			dfsStack.pop();

			// Check for adjacent nodes and put in stack
			for (int nextNode = 0; nextNode < size; nextNode++) {
				int isConnected = A1[currNode][nextNode];
				size_t nextLength = currLength + 1;

				if (!isConnected) {
					continue;
				}

				// If path is greater than N then add path
				if (nextLength > size) {
					numPaths++;

					continue;
				}

				dfsStack.push(nextNode);
				dfsSize.push(nextLength);
			}
		}
	}

	cout << "Total number of paths of length " << size << " edges: " << numPaths << endl;
}

void printNumberPathsL1N(int** A1, int** A2, int** A3, int** A4, int** A5, size_t size) {
	// Using reachability matrix to get all paths
	size_t numPaths = 0;
	int **reachabilityMatrix = new int* [size];
	for (int i = 0; i < size; i++) {
		reachabilityMatrix[i] = new int [size];
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			reachabilityMatrix[i][j] = 0;
		}
	}

	// Add number of paths based on size of matrix
	switch(size) {
		case 1:
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					reachabilityMatrix[i][j] += A1[i][j];
				}
			}

			break;

		case 2:
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					reachabilityMatrix[i][j] += A1[i][j] + A2[i][j];
				}
			}

			break;

		case 3:
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					reachabilityMatrix[i][j] += A1[i][j] + A2[i][j] + A3[i][j];
				}
			}

			break;

		case 4:
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					reachabilityMatrix[i][j] += A1[i][j] + A2[i][j] + A3[i][j] + A4[i][j];
				}
			}

			break;

		case 5:
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					reachabilityMatrix[i][j] += A1[i][j] + A2[i][j] + A3[i][j] + A4[i][j] + A5[i][j];
				}
			}

			break;
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			numPaths += reachabilityMatrix[i][j];
		}
	}

	cout << "Total number of paths of length 1 to " << size << " edges: " << numPaths << endl;
}

void printNumberCyclesL1N(int** A1, size_t size) {
	size_t numCycles = 0;

	// DFS
	for (int i = 0; i < size + 1; i++) { 		// Iterating over all sizes of cycles possible
		for (int rootNode = 0; rootNode < size; rootNode++) {
			stack<int> dfsStack;
			stack<int> dfsSize;
			dfsStack.push(rootNode);
			dfsSize.push(1);

			while (!dfsStack.empty()) {
				size_t currLength = dfsSize.top();
				dfsSize.pop();
				int currNode = dfsStack.top();
				dfsStack.pop();

				// Check for adjacent nodes and put in stack
				for (int nextNode = 0; nextNode < size; nextNode++) {
					int isConnected = A1[currNode][nextNode];
					size_t nextLength = currLength + 1;

					if (!isConnected) {
						continue;
					}

					if (nextLength > i) {
						if (nextNode == rootNode) {
							numCycles++;
						}

						continue;
					}

					dfsStack.push(nextNode);
					dfsSize.push(nextLength);
				}
			}
		}
	}

	cout << "Total number of cycles of length 1 to " << size << " edges: " << numCycles << endl;
}