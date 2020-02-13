#include <iostream>
#include <vector>

#include "Complex.h"

#pragma once
#ifndef ComplexVector_h
#define ComplexVector_h


class ComplexVector
{
private:
	std::vector <Complex> elements;

	friend std::ostream& operator << (std::ostream& out, ComplexVector v);

public:
	ComplexVector(std::vector <Complex>& _elements);

	ComplexVector operator + (const ComplexVector& other) const;

	ComplexVector operator - (const ComplexVector& other) const;

	ComplexVector operator * (const ComplexVector& other) const;

	ComplexVector operator / (const ComplexVector& other) const;
};

#endif