#include <iostream>
#include "Complex.h"
#include "ComplexVector.h"
#include <vector>

ComplexVector::ComplexVector(std::vector <Complex>& _elements) : elements(_elements) { }

ComplexVector ComplexVector::operator + (const ComplexVector& other) const
{
	std::vector <Complex> new_elements;
	for (int i = 0; i < elements.size(); i++)
	{
		new_elements.push_back(elements[i] + other.elements[i]);
	}
	return (ComplexVector(new_elements));
}

ComplexVector ComplexVector::operator - (const ComplexVector& other) const
{
	std::vector <Complex> new_elements;
	for (int i = 0; i < elements.size(); i++)
	{
		new_elements.push_back(elements[i] - other.elements[i]);
	}
	return (ComplexVector(new_elements));
}

ComplexVector ComplexVector::operator * (const ComplexVector& other) const
{
	std::vector <Complex> new_elements;
	for (int i = 0; i < elements.size(); i++)
	{
		new_elements.push_back(elements[i] * other.elements[i]);
	}
	return (ComplexVector(new_elements));
}

ComplexVector ComplexVector::operator / (const ComplexVector& other) const
{
	std::vector <Complex> new_elements;
	for (int i = 0; i < elements.size(); i++)
	{
		new_elements.push_back(elements[i] / other.elements[i]);
	}
	return (ComplexVector(new_elements));
}

std::ostream& operator << (std::ostream& out, ComplexVector v)
{
	out << "{";
	for (int i = 0; i < v.elements.size(); i++)
	{
		out << v.elements[i];
		if (i == v.elements.size() - 1)
		{
			out << "}\n";
		}
		else out << ", ";
	}
	return out;
}
//operator overrider for ostream, friended to ComplexVector class to access its elements vector
