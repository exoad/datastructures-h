/*
Create classes Polygon, Triangle,
and Shape using proper inheritance
protocols. Have methods in each
that relate to the classes themselves.
Create an object in your main
function to test the implementation.
*/

#include <cstring>
#include <iostream>
#include <cmath>

using namespace std;

class Shape
{
      private:
            int sides;

      public:
            explicit Shape(int sides) : sides(sides) {}

            int get_sides() const
            {
                  return this->sides;
            }

            virtual ~Shape() = default;
            virtual string get_name() = 0;
};

class Polygon : public Shape
{
      private:
            string name;

      public:
            Polygon(int sides, string name): Shape(sides), name(name) {}

            string get_name() override
            {
                  return this->name;
            }

            virtual float perimeter() = 0;
            virtual float area() = 0;
};

class Triangle : public Polygon
{
      private:
            int b;
            int h;

      public:
            Triangle(int b, int h) : Polygon(3, "Triangle"), b(b), h(h) {}

            float perimeter() override
            {
                  return static_cast<float>(b + h + (sqrt(b * b + h * h)));
            }

            float area() override
            {
                  return 0.5F * static_cast<float>(b * h);
            }
};

int main(void)
{
      Triangle t(3, 4);
      cout << "Area: " << t.area() << "\nPerimeter: " << t.perimeter() << "\nName: " << t.get_name() << "\nSides: " << t.get_sides() << endl;
}
