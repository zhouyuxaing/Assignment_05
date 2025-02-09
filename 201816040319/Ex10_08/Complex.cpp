#include "Complex.h"
#include <iostream>
using namespace std;
// Constructor
Complex::Complex( double realPart, double imaginaryPart )
   : real( realPart ),
   imaginary( imaginaryPart )
{
   // empty body
} // end Complex constructor
// addition operator
Complex Complex::operator+( const Complex &operand2 ) const
{
   return Complex( real + operand2.real,
      imaginary + operand2.imaginary );
} // end function operator+
// subtraction operator
Complex Complex::operator-( const Complex &operand2 ) const
{
   return Complex( real - operand2.real,
      imaginary - operand2.imaginary );
} // end function operator-
// Overloaded multiplication operator
Complex Complex::operator*( const Complex &operand2 ) const
{
   return Complex(
      ( real * operand2.real ) + ( imaginary * operand2.imaginary ),
      ( real * operand2.imaginary ) + ( imaginary * operand2.real ) );
} // end function operator*
// Overloaded = operator
bool Complex::operator==( const Complex &right ) const
{
   if( (right.real == real ) && ( right.imaginary == imaginary ))
      return true;
      else
        return false;
} // end function operator==
bool Complex::operator!=( const Complex &right ) const
{
   return !( *this == right );
} // end function operator!=
ostream& operator<<( ostream &output, const Complex &complex )
{
   output << "(" << complex.real << ", " << complex.imaginary << ")";
   return output;
} // end function operator<<
istream& operator>>( istream &input, Complex &complex )
{
   input.ignore(); // skip (
   input >> complex.real;
   input.ignore( 2 ); // skip ',' and space
   input >> complex.imaginary;
   input.ignore(); // skip )
   return input;
} // end function operator>>
