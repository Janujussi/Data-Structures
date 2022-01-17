// Name: Jan Morrison
// Class: CS 3305/Section#3
// Term: Fall 2021
// Instructor: Dr. Haddad
// Assignment: 2

// FILE: polytest1.cpp

#include "poly1.h"  // Provides the polynomial class
#include <cctype>   // Provides toupper
#include <cstdlib>  // Provides EXIT_SUCCESS
#include <iostream> // Provides cout and cin

using namespace std;
using namespace main_savitch_3;

const unsigned int MANY = 3; // Number of polynomials allowed in this test program.

// PROTOTYPES for functions used by this test program:
void print_menu();
// Postcondition: The menu has been written to cout.

size_t set_current();
// Postcondition: Return value is index for a new current polynomial.

char get_command();
// Postcondition: The user has been prompted for a character.
// The entered charatcer will be returned, translated to upper case.

void view_degree(const polynomial& test);
// Postcondition:  The polynomial passed has a degree.

void view_poly(const polynomial& test);
// Postcondition:  The polynomial passed has been sent to cout.

void view_all(const polynomial a[]);
// Postcondition:  All polynomials has been written to cout.

void test_add(polynomial& test);
// Postcondition: The user has been prompted for a coefficent and degree of
// the term added.  The resulting polynomial has been written to cout.

void test_assign(polynomial& test);
// Postcondition: The user has been prompted for the degree and the coeffinient
// to be set.  The resulting polynomial has been written to cout.

void test_clear(polynomial& test);
// Postcondition: test.clear( ) has been activated.
// to be set.  The resulting polynomial has been written to cout.

void test_eval(const polynomial& test);
// Post conditon:  The user has been prompted for the x value.  The evaluation
// of the polynomial is written to cout.

void test_next(const polynomial& test);
// Post conditon:  The user has been prompted for the e value.  The
// value of test.next_term(e) and test.previous_term(e) are written to cout.

int main()
{
	polynomial p[MANY];
	size_t current_index = 0;
	char command;
	size_t i;

	cout << "Polynomials ";
	for(i = 0; i < MANY; ++i)
			cout << char('A' + i) << ' ';
	cout << "have all been initialized." << endl;

	do {
			print_menu();
			command = toupper(get_command());

			switch(command) {
			case 'S':
					current_index = set_current();
					break;
			case '1':
					test_assign(p[current_index]);
					break;
			case '2':
					test_add(p[current_index]);
					break;
			case 'C':
					test_clear(p[current_index]);
					break;
			case 'D':
					view_degree(p[current_index]);
					break;
			case 'V':
					view_poly(p[current_index]);
					break;
			case 'A':
					view_all(p);
					break;
			case 'E':
					test_eval(p[current_index]);
					break;
			case 'N':
					test_next(p[current_index]);
					break;
			case '+':
					cout << "A + B: ";
					view_poly(p[0] + p[1]);
					break;
			case '-':
					cout << "A - B: ";
					view_poly(p[0] - p[1]);
					break;
			case 'Q': // Do nothing..
					break;
			default:
					cout << "Invalid command." << endl;
					break;
			}
	} while(command != 'Q');
	return (EXIT_SUCCESS);
}

void print_menu()
{
    cout << "\n----------------- The Commands -----------------" << endl;
    cout << "S - set the current Polynomial to work on" << endl;
    cout << "  -   -   -   -   -   -   -   -   -   -   -   -" << endl;
    cout << "1 - use the assign_coef function" << endl;
    cout << "2 - use the add_to_coef function" << endl;
    cout << "C - use the clear function" << endl;
    cout << "D - view the current polynomial degree" << endl;
    cout << "V - view the current polynomial" << endl;
    cout << "A - view all polynomials" << endl;
    cout << "E - evaluate current polynomial by using () op" << endl;
    cout << "N - use the next_term function" << endl;
    cout << "+ - view A + B" << endl;
    cout << "- - view A - B" << endl;
    cout << "  -   -   -   -   -   -   -   -   -   -   -   -" << endl;
    cout << "Q - quit this interactive test program" << endl;
    cout << "-------------------------------------------------" << endl;
}

char get_command()
{
    char command;

    cout << ">";
    cin >> command;

    return (toupper(command));
}

void view_poly(const polynomial& test)
{
	for (int i = test.degree(); i > 0; i--) {
		printf("(%f*x^%d) + ", test.coefficient(i), i);
	}

	printf("%f", test.coefficient(0));
}

void view_degree(const polynomial& test)
{
    // modify this function to view the polynomial degree
    cout << " (degree is " << test.degree() << ")" << endl;
}

size_t set_current()
{
    size_t i;
    char command;

    do {
        cout << "Polynomials ";
        for(i = 0; i < MANY; ++i)
            cout << char('A' + i) << ' ';
        cout << "." << endl;
        cout << "Enter the polynomial you want to work on: ";
        command = toupper(get_command());
    } while((command < 'A') || (command >= char('A' + MANY)));
    return command - 'A';
}

void test_add(polynomial& test)
{
    double coefficient;
    unsigned int exponent;

    cout << "Enter exponent: ";
    cin >> exponent;
    cout << "Enter coefficient: ";
    cin >> coefficient;

		if (exponent > test.degree()) {
			test.reserve(exponent + 1);
		}

    test.add_to_coef(coefficient, exponent);
    cout << "After adding: ";
    view_poly(test);
}

void test_assign(polynomial& test)
{
    double coefficient;
    unsigned int exponent;

    cout << "Enter exponent: ";
    cin >> exponent;
    cout << "Enter coefficient: ";
    cin >> coefficient;

		if (exponent > test.degree()) {
			test.reserve(exponent + 1);
		}

    test.assign_coef(coefficient, exponent);
    cout << "After assigning: ";
    view_poly(test);
}

void test_eval(const polynomial& test)
{
    double x_value;
    cout << "Enter the x value: ";
    cin >> x_value;

    cout << "For the poly: ";
    view_poly(test);
    cout << "\nThe evaluation returned is " << test(x_value) << endl;
}

void view_all(const polynomial p[])
{
    size_t i;

    cout << endl;

    for(i = 0; i < MANY; ++i) {
        cout << "\n" << char(i + 'A') << ": ";
        view_poly(p[i]);
    }
}

void test_clear(polynomial& test)
{
    test.clear();
    cout << "After clearing: ";
    view_poly(test);
}

void test_next(const polynomial& test)
{
    unsigned int exponent;

    cout << "Enter exponent: ";
    cin >> exponent;

    cout << "For polynomial: ";
    view_poly(test);
    cout << "\nnext_term(" << exponent << ") = " << test.next_term(exponent) << endl;
}
