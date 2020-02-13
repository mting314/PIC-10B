#include "Complex.h"
#include <ostream>
#include <iomanip>

	Complex::Complex(double _real, double _imaginary) : real(_real), imaginary(_imaginary)
	{

	}


	Complex Complex::operator + (const Complex& other) const
	{
		Complex c(real + other.real, imaginary + other.imaginary);
		return c;
	}

	Complex Complex::operator - (const Complex& other) const
	{
		Complex c(real - other.real, imaginary - other.imaginary);
		return c;
	}

	Complex Complex::operator * (const Complex& other) const
	{
		//(a+bi)*(c+di) = (ab-cd) + i(cb+ad)
		Complex c(real * other.real - imaginary * other.imaginary, imaginary * other.real + real * other.imaginary);
		return c;
	}

	Complex Complex::operator / (const Complex& other) const
	{
		Complex c((real * other.real + imaginary * other.imaginary) / (other.real * other.real + other.imaginary * other.imaginary), (imaginary * other.real - real * other.imaginary) / (other.real * other.real + other.imaginary * other.imaginary));
		return c;
	}

	//
	std::ostream& operator << (std::ostream& out, Complex c)
	{
		out << std::setw(5) << c.real;

		if (c.imaginary < 0) out << " - ";
		else out << " + ";

		out << std::setw(5) << abs(c.imaginary) << "i ";

		return out;
	}