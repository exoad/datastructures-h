/*
Create the special quadrilaterals as a
sequence of Base and Derived
classes, being sure to solve any
multiple inheritance issues.
*/

class Quadrilateral 
{
    public: 
        Quadrilateral() = default;
};

class Trapezoid : public Quadrilateral 
{
    public:
        Trapezoid() : Quadrilateral() {}
};

class Kite : public Quadrilateral 
{
    public:
        Kite() : Quadrilateral() {}
};

class Parallelogram : public Trapezoid 
{
    public:
        Parallelogram() : Trapezoid() {}
};

class IsoscelesTrapezoid : public Trapezoid
{
    public:
        IsoscelesTrapezoid() : Trapezoid() {}
};

class Rhombus : public Kite, public Parallelogram
{
    public:
        Rhombus() : Kite(), Parallelogram() {}
};

class Rectangle : public Parallelogram, public IsoscelesTrapezoid
{
    public:
        Rectangle() : Parallelogram(), IsoscelesTrapezoid() {}
};

class Square : public Rhombus, public Rectangle 
{
    public:
        Square() : Rhombus(), Rectangle() {}
};

int main()
{
    
}
