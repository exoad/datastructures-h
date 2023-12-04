#pragma once

#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

// This macro converts from radians to degrees
#define RAD_TO_DEG(rad) rad*180.0/M_PI

/// @brief A Complex Number representation
class Complex
{
      private:
            /// @brief Represents the real part of the complex number
            double a;
            /// @brief Represents the imaginary part of the complex number
            double b;

      public:
            /// @brief Assign the default values for a complex number (a+bi)
            /// @param a The real part
            /// @param b The imaginary part
            Complex(double a, double b);

            /// @brief Computes the complex conjugate of a+bi which is just a-bi
            /// @return The complex conjugate
            Complex conjugate();

            /// @brief Magnitude, norm of the complex number???
            /// @return Norm (magnitude)
            double norm();

            /// @brief Returns the real part of the complex number; the "a" in a+bi
            /// @return The real part
            double real();
            
            /// @brief Returns the not real part of the complex number; the "b" in a+bi
            /// @return The imaginary part
            double imag();

            /// @brief Computes the dot product between complex numebrs
            /// @param other The other complex number
            /// @return The dot product
            double dotProduct(Complex other);

            /// @brief Scales this complex number by a factor
            /// @param value The scale value
            /// @return This current complex number scaled up by "value"
            Complex scalarProduct(double value);

            /// @brief Calculates the angle between complex numbers
            /// @param other The other complex number
            /// @return The angle in degrees
            double angleBetween(Complex other);

            /// @brief The to_string conversion of this complex number using the "<<" operator
            /// @return The a+bi form
            friend std::ostream& operator<<(std::ostream& os, const Complex& obj);

            /// @brief Adds two complex numbers together using operator overloading
            /// @param complex The other complex number
            /// @return The resultant complex number
            Complex operator + (Complex const& complex);

            /// @brief Multiplies this complex number by a value thus applying the scalarProduct
            /// @param value The constant
            /// @return The scaled up complex number
            /// @ref Complex::scalarProduct(double)
            Complex operator * (double const& value);


            /// @brief Multiplies two complex numbers two get their dot product
            /// @param complex The other complex number
            /// @return The dot product of these two complex numbers
            Complex operator * (Complex const& complex);

            /// @brief Divides two complex numbers using operator overloading
            /// @param other The other complex number
            /// @return The resultant complex number
            Complex operator / (Complex const& other);

            /// @brief Divides this complex number by a constant
            /// @param value The constant
            /// @return The resultant complex number
            Complex operator / (double const& value);

            /// @brief Subtracts two vectors using operating overloading
            /// @param complex The other complex number
            /// @return The resultant complex vector after the subtraction
            Complex operator - (Complex const& complex);

            /// @brief Checks if two complex numbers are equal
            /// @param complex The other complex number
            /// @return True if they are equal, false otherwise
            bool operator == (Complex const& complex);
};

Complex::Complex(double a,double b) : a(a),b(b) {}

Complex Complex::conjugate() 
{
    return Complex(Complex::a, -Complex::b);
}

double Complex::norm()
{
    return sqrt(Complex::a*Complex::a+Complex::b*Complex::b);
}

double Complex::real()
{
    return Complex::a;
}

double Complex::imag()
{
    return Complex::b;
}

double Complex::dotProduct(Complex other)
{
    return Complex::a*other.a+Complex::b*other.b;
}

Complex Complex::scalarProduct(double value)
{
    Complex::a*=value;
    Complex::b*=value;
    return *this;
}

double Complex::angleBetween(Complex other)
{
    return RAD_TO_DEG(acos(Complex::dotProduct(other)/(Complex::norm()*other.norm())));
}

ostream& operator<<(ostream& os,Complex const& obj)
{
    os << obj.a << (obj.b < 0 ? "-" : "+") << abs(obj.b) << "i";
    return os;
}

Complex Complex::operator+(Complex const& complex)
{
    return Complex(complex.a+Complex::a, complex.b+Complex::b);
}

Complex Complex::operator*(double const& value)
{
    return Complex::scalarProduct(value);
}

Complex Complex::operator*(Complex const& complex)
{
    return Complex(
                                Complex::a*complex.a-Complex::b*complex.b, 
                                Complex::a*complex.b+Complex::b*complex.a
                  );
}

Complex Complex::operator/(Complex const& other)
{
     return Complex(
                              ((Complex::a*other.a)+(Complex::b*other.b))/((other.a*other.a)+(other.b*other.b)),
                              ((Complex::b*other.a)-(Complex::a*other.b))/((other.a*other.a)+(other.b*other.b))
                  );
}

Complex Complex::operator/(double const& value)
{
    Complex::a/=value;
    Complex::b/=value;
    return *this;
}

Complex Complex::operator-(Complex const& complex)
{
    return Complex(Complex::a-complex.a,Complex::b-complex.b);
}

bool Complex::operator==(Complex const& complex)
{
    return Complex::a==complex.a &&Complex::b==complex.b;
}
