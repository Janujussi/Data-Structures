// Name: 				Jan Morrison

// FILE: TestRectangle.cpp
// CLASS IMPLEMENTED: Rectangle (see Rectangle.h for documentation)

#include <iostream>			// Provides cin
#include "Rectangle.h"	// Provides the Rectangle class definition

using namespace std;

void print_rectangle_data(string objectName, Rectangle rectangle);

int main() {
	double height, width;																		// Height and width variables for user created rectangle

	// User enters values for their rectangle
	printf("Enter height: ");
	cin >> height;
	printf("Enter width: ");
	cin >> width;

	Rectangle myRectangle, yourRectangle(height, width);		// Default rectangle and user created rectangle

	// Check function documentation
	print_rectangle_data("myRectangle", myRectangle);
	print_rectangle_data("yourRectangle", yourRectangle);
}

void print_rectangle_data(string objectName, Rectangle rectangle) {
	// Prints the data table and rectangle information
	printf("\n%s:\
		\n------------\
		\nWidth: %14f\
		\nHeight: %13f\
		\nArea: %15f\
		\nPerimeter: %10f\n\n",
		objectName.c_str(),
		rectangle.getWidth(),
		rectangle.getHeight(),
		rectangle.getArea(),
		rectangle.getPerimeter()
	);
	rectangle.printRectangle(objectName);
}