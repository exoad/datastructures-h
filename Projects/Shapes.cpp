/// \file Shapes.cpp
/// \author Jack Meng
/// \brief Demonstrate inheritance and stuffs through shapes classes
/// \date 2023-10-18

#include <iostream>
#include <cstring>

using namespace std;

// This macro just prints a new line :/
#define nl cout << endl;
// This macro declares a variable and reads value into it from the console
#define gl(STR, TYPE, VAR) TYPE VAR;    \
                          cout << STR;\
                          cin >> VAR;
// This macro does not declare a variable and reads a pre-existing value from the console
#define sl(STR, VAR) cout << STR;      \
                    cin >> VAR;
#define LOOP for(;;) // macro for just a while(true) but less characters

/// @brief  This is the class inherited by Rectangle and Triangle to represent their base
/// attributes, such as width and height.
class Polygon
{
      protected: // using protected so only inheriting classes can access it
            int width; // width variable
            int height; // height variable

      public:
            /// @brief Our constructor similar \ref setValues(int,int)
            /// @param width the width parameter
            /// @param height the height parameter
            Polygon(int width, int height) : width(width), height(height) {} // constructor uses an initializer list to init all variables

            /// @brief Master setter method
            /// @param a The width parameter to set to (this is the new width to become)
            /// @param b The height parameter to set to (this is the new height to become)
            void setValues(int a, int b)
            {
                  this->width = a; // assignment to this instance's data width
                  this->height = b; // assignment to this instance's data height
            }
};

// a base class for producing output and to be inherited by
// polygon subclasses to print necessary information
class Output
{
      public:
            virtual ~Output() = default; // this is a compliance in that because this is inherited from, pointers to an instance of a derived can cause undef behavior and leaks, etc.
            virtual void print() = 0; // we write the necessary method for the output class and make it virtual so inheriting classes must override it and provide implementation
};

// a four sided polygon that inherits from polygon and output
class Rectangle : public Polygon, public Output
{
      public:
      // a polygin with a base and height ( rectangle) then we pass it to the parent/base constructor
            Rectangle(int width, int height) : Polygon(width, height) {}

            /// @brief Get area
            /// @return The area
            float area()
            {
                  // read the triangle's area() to see common on static_cast
                  return static_cast<float>(Polygon::height * Polygon::width); // calculate the area of this polygon using the base*height for an area of a rectangle
            }

            void print() override
            { // prints the necessary components of this polygon with all of its required information
                  cout << "Rectangle:\nWidth: " << Polygon::width << "\nHeight:" << Polygon::height << "\nArea: " << area();
            }
};

// a 3 sided polygon that inherits from polygon and output
class Triangle : public Polygon, public Output
{
      public:
      // a polygon with a base and height ( triangle) then we pass it to the parent/base constructor
            Triangle(int width, int height) : Polygon(width, height) {}

            /// @brief Get area
            /// @return The area
            float area()
            {
                  // we use a static cast because it is better than the C-style in that it performs compile time checking as compared to guessing with traditional c-style casts
                  return 0.5F * static_cast<float>(Polygon::height * Polygon::width); // calculate the area of a triangle in the form of 1/2*b*h
            }

            void print() override
            { // prints the necessary components of this polygon with all of its required informations
                  cout << "Triangle:\nBase: " << Polygon::width << "\nHeight: " << Polygon::height << "\nArea: " << area();
            }
};

int main(void)
{
      // user controlls the input, we use this to continuously if we want to exit or not
      string n;
      LOOP
      {
            // ask what kind of polygon they want so we can get the right information
            gl("What kind of polygon do you want?\n1. Rectangle\n2. Triangle\n", int, polygonType)
            // next we get the required properties of the polygon because rectangle and triangle
            // have the same parameters
            gl("Enter the width: ", int, polygonWidth)
            gl("Enter the height: ", int, polygonHeight)
            // we see what they chose and return the proper output of the object they have selected
            polygonType == 1 ? Rectangle(polygonWidth, polygonHeight).print() : Triangle(polygonWidth, polygonHeight).print();
            nl
            sl("Do another? (y/n): ", n) // ask the user if they want to do something else
            if(n != "Y" || n != "y") break;
      }
}