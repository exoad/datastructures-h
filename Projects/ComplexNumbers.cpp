/// \file ComplexNumbers.cpp
/// \author Jack Meng
/// \brief A program to test operator overloading with complex numbers
/// \date 2023-11-7


#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

// This macro just prints a new line :/
#define nl cout << endl;
// This macro declares a variable and reads value into it from the console
#define gl(STR, TYPE, VAR) TYPE VAR;   \
                           cout << STR;\
                           cin >> VAR;
// This macro does not declare a variable and reads a pre-existing value from the console
#define sl(STR, VAR) cout << STR;\
                     cin >> VAR;
// This macro converts from radians to degrees
#define RAD_TO_DEG(rad) rad*180.0/M_PI
// This macro redefines a while(true)
#define LOOP for(;;)
// This macro is for user controlled exit
#define USER_LOOP(CODE) string ___USERE;                                    \
                        LOOP                                                \
                        {                                                   \
                              CODE;                                         \
                  		nl                                            \
                  		sl("Do another? (y/n): ", ___USERE)           \
                  		if (___USERE != "Y" || ___USERE != "y") break;\
                        }

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
            Complex(double a, double b) : a(a), b(b)
            {}

            /// @brief Computes the complex conjugate of a+bi which is just a-bi
            /// @return The complex conjugate
            Complex conjugate()
            {
                  return Complex(a, -b);
            }

            /// @brief Magnitude, norm of the complex number???
            /// @return Norm (magnitude)
            double norm()
            {
                  return sqrt(a*a+b*b);
            }

            /// @brief Returns the real part of the complex number; the "a" in a+bi
            /// @return The real part
            double real()
            {
                  return a;
            }

            /// @brief Returns the not real part of the complex number; the "b" in a+bi
            /// @return The imaginary part
            double imag()
            {
                  return b;
            }

            /// @brief Computes the dot product between complex numebrs
            /// @param other The other complex number
            /// @return The dot product
            double dotProduct(Complex other)
            {
                  return a*other.a+b*other.b;
            }

            /// @brief Scales this complex number by a factor
            /// @param value The scale value
            /// @return This current complex number scaled up by "value"
            Complex scalarProduct(double value)
            {
                  a*=value;
                  b*=value;
                  return *this;
            }

            /// @brief Calculates the angle between complex numbers
            /// @param other The other complex number
            /// @return The angle in degrees
            double angleBetween(Complex other)
            {
                  // we have to call RAD_TO_DEG because all trig in c++ return in rads
                  return RAD_TO_DEG(acos(dotProduct(other)/(norm()*other.norm())));
            }

            /// @brief The to_string conversion of this complex number using the "<<" operator
            /// @return The a+bi form
            friend std::ostream& operator<<(std::ostream& os, const Complex& obj)
            {
                  os << obj.a << (obj.b < 0 ? "-" : "+") << obj.b << "i";
                  return os;
            }

            /// @brief Adds two complex numbers together using operator overloading
            /// @param complex The other complex number
            /// @return The resultant complex number
            Complex operator + (Complex const& complex)
            {
                  return Complex(complex.a+a, complex.b+b);
            }

            /// @brief Multiplies this complex number by a value thus applying the scalarProduct
            /// @param value The constant
            /// @return The scaled up complex number
            /// @ref Complex::scalarProduct(double)
            Complex operator * (double const& value)
            {
                  return scalarProduct(value);
            }


            /// @brief Multiplies two complex numbers two get their dot product
            /// @param complex The other complex number
            /// @return The dot product of these two complex numbers
            double operator * (Complex const& complex)
            {
                  return dotProduct(complex);
            }

            /// @brief Divides two complex numbers using operator overloading
            /// @param other The other complex number
            /// @return The resultant complex number
            Complex operator / (Complex const& other)
            {
                  return Complex(
                              ((a * other.a) + (b * other.b)) / ((other.a * other.a) + (other.b * other.b)),
                              ((b * other.a) - (a * other.b)) / ((other.a * other.a) + (other.b * other.b))
                  );
            }

            /// @brief Divides this complex number by a constant
            /// @param value The constant
            /// @return The resultant complex number
            Complex operator / (double const& value)
            {
                  a/=value;
                  b/=value;
                  return *this;
            }

            /// @brief Subtracts two vectors using operating overloading
            /// @param complex The other complex number
            /// @return The resultant complex vector after the subtraction
            Complex operator - (Complex const& complex)
            {
                  return Complex(a-complex.a, b-complex.b);
            }

            /// @brief Checks if two complex numbers are equal
            /// @param complex The other complex number
            /// @return True if they are equal, false otherwise
            bool operator == (Complex const& complex)
            {
                  return a==complex.a && b==complex.b;
            }
};

/// @brief Simple function ask the user to create a Complex number object without repetitive code
/// @return A complex number with a user's wanted values
inline Complex createObj()
{
      int a;
      int b;
      // get the user's inputs from the console
      sl("Create a complex number (a+bi):\nEnter the real part (\"a\"): ", a)
      sl("Enter the imaginary part (\"b\"): ", b)
      // create and return the final object
      return Complex(a, b);
}

/// @brief Handle user input i guess (i dont really know)
int main(void)
{
      // define the initial user controlled exit loop using a macro so i dont have to write the same code 90238490284023 times for this class
      USER_LOOP({
            auto initialNum = createObj();
            LOOP
            {
                  gl("Enter an operation:\n1. Dot product\n2. Scalar Product\n3. Add another complex number\n4. Subtract another complex number\n5. Divide by another complex number\n6. Divide by a constant\n7. View current value\nAll other numbers: Stop\n\nChoice: ", int, choice)
                  switch(choice)
                  {
                        case 1: // dot product
                        {
                              cout << "Dot Product\n";
                              auto other = createObj();
                              cout << "\nDot Product Result of " << initialNum << "*" << other << "\nResultant: " << (initialNum*other) << endl;
                              break;
                        }
                        case 2: // scalar product
                        {
                              cout << "Scalar Product\n";
                              gl("Enter the constant: ", double, k)
                              cout << "\nScalar Product Result of " << initialNum << "*" << k << "\nResultant: " << (initialNum*k) << endl;
                              break;
                        }
                        case 3: // add another complex number
                        {
                              cout << "Add another complex number\n";
                              auto other1 = createObj();
                              cout << "\nAddition of " << initialNum << "+" << other1 << "\nResultant: " << (initialNum+other1) << endl;
                              break;
                        }
                        case 4: // subtract another complex number
                        {
                              cout << "Subtract another complex number\n";
                              auto other3 = createObj();
                              cout << "\nSubtraction of " << initialNum << "-" << other3 << "\nResultant: " << (initialNum-other3) << endl;
                              break;
                        }
                        case 5: // divide by another complex number dotProduct(1/(other1))
                        {
                              cout << "Divide by another complex number\n";
                              auto other2 = createObj();
                              cout << "\nDivision of " << initialNum << "/" << other2 << "\nResultant: " << (initialNum/other2) << endl;
                              break;
                        }
                        case 6:
                        {
                              cout << "Divide by a constant\n";
                              gl("Enter the constant: ", double, k)
                              cout << "\nDivision of " << initialNum << "/" << k << "\nResultant: " << (initialNum/k) << endl;
                              break;
                        }
                        case 7: // displays the current value
                        {
                              cout << "Current value: " << initialNum << endl;
                              break;
                        }
                        default:
                              break;
                  }
            }
      })
}