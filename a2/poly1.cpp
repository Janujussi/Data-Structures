// Name: Jan Morrison
// Class: CS 3305/Section#3
// Term: Fall 2021
// Instructor: Dr. Haddad
// Assignment: 2

// File: poly1.cpp
// CLASS IMPLEMENTED: poly.h (see poly.h for documentation)

#include "poly1.h"	// Provides the poly1 class definition
#include <cmath>		// Provides maths functions used

using namespace std;

// CONSTRUCTORS AND DESTRUCTOR
main_savitch_3::polynomial::polynomial()
{	// Initializes polynomial to degree 0
	this->coef = new double [1];
	this->current_array_size = 1;
}

main_savitch_3::polynomial::polynomial(double a0)
{	// The parameter initializes the polynomial degree 0
	this->coef = new double [1];
	this->current_array_size = 1;
	this->coef[0] = a0;
}

main_savitch_3::polynomial::polynomial(const polynomial& source)
{	// Copy of polynomial created
	this->coef = source.coef;
	this->current_array_size = source.current_array_size;
}

main_savitch_3::polynomial::~polynomial()
{
	delete [] this->coef;
	this->coef = NULL;
	this->current_array_size = 0;
}

// MODIFICATION MEMBER FUNCTIONS
void main_savitch_3::polynomial:: add_to_coef(double amount, unsigned int k)
{	// Add amount to coefficient of degree k
	this->coef[k] += amount;
}

void main_savitch_3::polynomial::assign_coef(double coefficient, unsigned int k)
{	// Assigns coefficient to degree
	this->coef[k] = coefficient;
}

void main_savitch_3::polynomial::clear()
{	// All coefficients are zero
	for (size_t i = 0; i < this->current_array_size; i++) {
		this->coef[i] = 0;
	}
}

void main_savitch_3::polynomial::reserve(size_t number)
{	// Resizing polynomial
	if (number == this->current_array_size) {
		printf("No change needed.");
		return;
	}

	size_t minSize = this->current_array_size;

	for (; minSize >= 1 && this->coef[minSize - 1] == 0; minSize--) {	// Finds highest nonzero degree
	}

	if (number < minSize) {
		printf("The number you entered is too small.");
		return;
	}

	double* tempArr = new double [minSize];
	memcpy(tempArr, this->coef, minSize);
	delete [] this->coef;

	this->coef = new double [number];
	memcpy(this->coef, tempArr, minSize);
	this->current_array_size = number;
	for (int i = minSize; i < number; i++) {
		this->coef[i] = 0;
	}

	delete [] tempArr;
	tempArr = NULL;
}

// CONSTANT MEMBER FUNCTIONS
double main_savitch_3::polynomial::coefficient(unsigned int k) const
{	// Return coefficient of degree
	return this->coef[k];
}

unsigned int main_savitch_3::polynomial::degree() const
{	// Returns value of largest degree coefficient
	size_t degree = this->current_array_size - 1;

	while (this->coef[degree] == 0 && degree != 0) {
		degree--;
	}

	return degree;
}

unsigned int main_savitch_3::polynomial::next_term(unsigned int k) const
{	// Return next nonzero coefficient
	size_t next = k + 1;

	while (this->coef[next] == 0) {
		next++;
	}

	return this->coef[next];
}

// MODIFICATION OPERATORS
main_savitch_3::polynomial& main_savitch_3::polynomial::operator=(const polynomial& source)
{
	return *this;
}

// EVALUATION MEMBER FUNCTIONS
double main_savitch_3::polynomial::eval(double x) const
{	// Evaluates the polynoimial
	double eval = 0;

	for (int i = 0; i < this->current_array_size; i++) {
		eval += (coef[i] * pow(x, i));
	}

	return eval;
}

// NON-MEMBER BINARY OPERATORS
main_savitch_3::polynomial main_savitch_3::operator-(const main_savitch_3::polynomial& p1, const main_savitch_3::polynomial& p2)
{
	main_savitch_3::polynomial diffPoly;

	if (p1.degree() > p2.degree()) {
		diffPoly.reserve(p1.degree() + 1);
	} else {
		diffPoly.reserve(p2.degree() + 1);
	}

	for (int i = 0; i < diffPoly.degree() + 1; i++) {
		if ((p1.coefficient(i) < 0 && p2.coefficient(i) < 0) || (p1.coefficient(i) < 0 && p2.coefficient(i) > 0)) {
			diffPoly.assign_coef((p1.coefficient(i)) - (p2.coefficient(i)), i);
		} else {
			diffPoly.assign_coef(abs(p1.coefficient(i)) + abs(p2.coefficient(i)), i);
		}
	}
	return diffPoly;
}

main_savitch_3::polynomial main_savitch_3::operator+(const main_savitch_3::polynomial& p1, const main_savitch_3::polynomial& p2)
{
	main_savitch_3::polynomial sumPoly;

	if (p1.degree() > p2.degree()) {
		sumPoly.reserve(p1.degree() + 1);
	} else {
		sumPoly.reserve(p2.degree() + 1);
	}

	for (int i = 0; i < sumPoly.degree() + 1; i++) {
		sumPoly.assign_coef(p1.coefficient(i) + p2.coefficient(i), i);
	}

	return sumPoly;
}
