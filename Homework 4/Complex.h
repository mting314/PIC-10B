#include <ostream>
#pragma once
#ifndef Complex_h
#define Complex_h

class Complex
{
public:
	Complex(double _real, double _imaginary);

	Complex operator + (const Complex& other) const;

	Complex operator - (const Complex& other) const;

	Complex operator * (const Complex& other) const;

	Complex operator / (const Complex& other) const;


private:
	double real, imaginary;
	friend std::ostream& operator << (std::ostream& out, Complex c);
};

#endif