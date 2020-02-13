/*
PIC 10B 2A, Homework 4
Purpose: Vector of complex number
Author: Michael Ting
Date: 11/16/2019
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

#include "Complex.h"
#include "ComplexVector.h"
using namespace std;

//recursive function that generates the nth value of the sequence
Complex sequence(const Complex& initial,const  int& depth)
{
	if (depth == 1) return initial;
	else
	{
		//next element is a multiple of previous, so create this multiplier based on current depth
		Complex multiplier = Complex(2 * (depth-1), 3 * (depth-1)) / Complex(7, 5 * (depth-1) * (depth-1));
		return sequence(multiplier * initial, depth - 1);
	}
}

int main()
{
	//initialize a first vector given by problem statement
	vector <Complex> holder = { Complex(2, 4), Complex(3, 5), Complex(-1, -3), Complex(8, 10) };
	ComplexVector v1(holder);

	//initialize a second vector given by problem statement
	holder = { Complex(-10, 3.5), Complex(4, 7.3), Complex(2, -8), Complex(10, -142) };
	ComplexVector v2(holder);

	//we can use our overridden output stream operator with cout stream
	cout << setprecision(1) << fixed;
	cout << "     v1 = " << v1;
	cout << "     v2 = " << v2;
	cout << "v1 + v2 = " << v1 + v2; //using each operator as we defined for complex vectors
	cout << "v1 - v2 = " << v1 - v2;
	cout << "v1 * v2 = " << v1 * v2;
	cout << "v1 / v2 = " << v1 / v2;
	cout << endl;

	//reset holder of complex numbers to be filled for sequence
	holder = {};

	//prepare output filestream to print elements of sequence to text file
	ofstream output_data;
	output_data.open("ComplexSequence.txt");

	cout << "Writing Complex Vector to File ...";

	//fill vector with each the first 6 elements of the 
	for (int i = 1; i <= 6; i++)
	{
		holder.push_back(sequence(Complex(1, 1), i));
	}

	output_data << ComplexVector(holder);
	output_data.close();
	cout << "Done" << endl;
}