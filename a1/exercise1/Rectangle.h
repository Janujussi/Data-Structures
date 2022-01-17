// Name: 				Jan Morrison
// Class: 			CS 3305/Section#03
// Term: 				Fall 2021
// Instructor: 	Dr. Haddad
// Assignment: 	1


// FILE: Rectangle.h
// CLASS PROVIDED: Rectangle
//
// CONSTRUCTORS for the Rectangle class:
//	Rectangle()
//		Postcondition: a rectangle object has been
//		created with default parameters 1.00 x 1.00.
//
//	Rectangle(double height, double width)
//		Postcondition: a rectangle object has been
//		created with user defined values.
//
// NON-CONSTANT MEMBER FUNCTIONS for the Rectangle class:
//	double getHeight()
//		Postcondition: rectangle's height is retrieved.
//
//	double getWidth()
//		Postcondition: rectangle's width is retrieved.
//
//	double getArea()
//		Postcondition: rectangle's area is retrieved.
//
//	double getPerimeter()
//		Postcondition: rectangle's perimeter is retrieved.
//
//	void printRectangle(string objectName)
//		Postcondition: rectangle's attributes are printed.

#include <string>

using std::string;

class Rectangle
{
  public:
		// CONSTRUCTORS
    Rectangle()
    {
      this->height = 1.00;
      this->width = 1.00;
    }

    Rectangle(double height, double width)
    {
    	this->height = height;
      this->width = width;
    }

		// NON-CONSTANT MEMBER FUNCTIONS
		double getHeight()
		{
			return this->height;
		}

		double getWidth()
		{
			return this->width;
		}

    double getArea()
    {
    	return this->height * this->width;
    }

		double getPerimeter()
		{
			return 2 * (this->height + this->width);
		}

		void printRectangle(string objectName)
		{
			printf(
				"Rectangle %s is %f units wide and %f units high.\n",
				objectName.c_str(),
				this->getWidth(),
				this->getHeight()
			);
		}

  private:
    double height;
    double width;
};