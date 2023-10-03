/*
Write a class called Circle that
computes the area and
circumference using the radius that
is supplied to the class as a
parameter at the time of
instantiation. Pi should be contained
in a constant private member that
cannot be accessed from outside the
circle. Your main function must
create and display the information
on a minimum of 3 circles.
*/

#include <iostream>
#include <cmath>

using namespace std;

class Circle 
{
    private:
        const double radius;
        const double PI = M_PI;
    public:
        Circle(double radius) : radius(radius)
        {}
    
        double area()
        {
            return PI * radius * radius;
        }
        
        double circumference()
        {
            return 2 * PI * radius;
        }
};

int main(void)
{
    Circle* c1 = new Circle(3.0);
    Circle* c2 = new Circle(5.0);
    Circle* c3 = new Circle(12.0);
    cout << "Circle1 Area: " << c1->area() << "\nCircle1 Circumference: " << c1->circumference() << "\nCircle2 Area: " << c2->area() << "\nCircle2 Circumference: " << c2->circumference() << "\nCircle3 Area: " << c3->area() << "\nCircle3 Circumference: " << c3->circumference();
}
